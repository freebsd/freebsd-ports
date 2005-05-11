--- src/plugins/live365/live365.c.orig	Wed May 11 03:49:30 2005
+++ src/plugins/live365/live365.c	Wed May 11 03:51:11 2005
@@ -1,5 +1,5 @@
 /*
- * Copyright (c) 2002, 2003, 2004 Jean-Yves Lefort
+ * Copyright (C) 2002-2005 Jean-Yves Lefort
  * All rights reserved.
  *
  * Redistribution and use in source and binary forms, with or without
@@ -59,7 +59,9 @@
 {
   ACCESS_ALL,
   ACCESS_VIP,
-  ACCESS_SUBSCRIPTION
+  ACCESS_SUBSCRIPTION,
+  ACCESS_SOLD_OUT,
+  ACCESS_UNKNOWN
 } Access;
 
 typedef struct
@@ -94,7 +96,8 @@
 {
   GList			**streams;
   Live365Stream		*stream;
-  Live365Stream		*finished_stream;
+  gboolean		first_page;
+  gboolean		looped;
   gboolean		has_next_page;
 } ReloadStreamsInfo;
 
@@ -263,13 +266,16 @@
 
     case FIELD_ACCESS_STRING:
       {
-	const char *str = NULL;
+	const char *str;
 
 	switch (stream->access)
 	  {
 	  case ACCESS_ALL:		str = _("All"); break;
 	  case ACCESS_VIP:		str = _("VIP"); break;
 	  case ACCESS_SUBSCRIPTION:	str = _("Subscription"); break;
+	  case ACCESS_SOLD_OUT:		str = _("Sold out"); break;
+	  case ACCESS_UNKNOWN:		str = _("Unknown"); break;
+	  default:			str = NULL; break;
 	  }
 
 	g_value_set_string(value, str);
@@ -707,14 +713,16 @@
   char *s1, *s2, *s3, *s4, *s5;
 
   if ((s1 = st_strstr_span(line, "<a href=\"/cgi-bin/directory"))
-      && (s2 = st_strstr_span(s1, "&genre="))
+      && (s2 = st_strstr_span(s1, "genre="))
       && (s3 = strchr(s2, '"'))
       && (s4 = st_strchr_span(s3, '>'))
       && (s5 = strstr(s4, "</a>")))
     {
       category = st_category_new();
       category->name = g_strndup(s2, s3 - s2);
-      category->label = st_sgml_ref_expand_len(s4, s5 - s4);
+      category->label = ! strcmp(category->name, "Recommendations")
+	? g_strdup(_("Recommendations"))
+	: st_sgml_ref_expand_len(s4, s5 - s4);
       category->url_postfix = g_strconcat(DIRECTORY_PREFIX, category->name, NULL);
     }
   else if ((s1 = st_strstr_span(line, "<a href=\"/genres/"))
@@ -755,6 +763,8 @@
 
   *streams = NULL;
   info.streams = streams;
+  info.first_page = TRUE;
+  info.looped = FALSE;
 
   session = st_transfer_session_new();
 
@@ -802,9 +812,11 @@
 	  if (status) /* only display warning if the transfer was otherwise correct */
 	    PARSE_ERROR;
 	}
+
+      info.first_page = FALSE;
     }
-  while (status && info.has_next_page
-	 && (stream_limit == -1 || received_streams < stream_limit));
+  while (status && info.has_next_page && ! info.looped
+	  && (stream_limit == -1 || received_streams < stream_limit));
 
   st_transfer_session_free(session);
 
@@ -818,6 +830,10 @@
   char *s1, *s2, *s3, *s4, *s5, *s6, *s7;
   char *word1, *word2, *word3;
 
+  /* if we have detected a loop, we just ignore the page */
+  if (info->looped)
+    return;
+
   if ((s1 = st_str_has_prefix_span(line, "<TD  CLASS=\"icon\""))
       && (s2 = st_strstr_span(s1, "DrawPlayIcon")))
     {
@@ -834,15 +850,18 @@
 	info->stream->access = ACCESS_VIP;
       else if (strstr(s2, "'SUBSCRIPTION'"))
 	info->stream->access = ACCESS_SUBSCRIPTION;
+      else if (strstr(s2, "'SOLD_OUT'"))
+	info->stream->access = ACCESS_SOLD_OUT;
       else
-	PARSE_ERROR;
-
-      info->finished_stream = NULL;
+	{
+	  PARSE_ERROR;
+	  info->stream->access = ACCESS_UNKNOWN;
+	}
     }
   else if ((s1 = st_str_has_prefix_span(line, "<TD  CLASS=\"title"))
-      && (s2 = st_strstr_span(s1, "href='"))
-      && (s3 = strstr(s2, "'>"))
-      && (s4 = strstr(s3, "</a>")))
+	   && (s2 = st_strstr_span(s1, "href='"))
+	   && (s3 = strstr(s2, "'>"))
+	   && (s4 = strstr(s3, "</a>")))
     {
       if (info->stream)
 	{
@@ -865,12 +884,19 @@
       else
 	PARSE_ERROR;
     }
-  else if ((s1 = st_strstr_span(line, "&station_id="))
-	   && (s2 = strchr(s1, '&')))
+  else if ((s1 = st_str_has_prefix_span(line, "<TD  CLASS=\"handle\""))
+	   && (s2 = st_strstr_span(s1, "ReadCookie("))
+	   && (s3 = st_strstr_span(s2, ", '"))
+	   && (s4 = strchr(s3, '\''))
+	   && (s5 = st_strstr_span(s4, "&station_id="))
+	   && (s6 = strchr(s5, '&')))
     {
       if (info->stream)
 	{
-	  word1 = g_strndup(s1, s2 - s1);
+	  g_free(info->stream->broadcaster);
+	  info->stream->broadcaster = st_sgml_ref_expand_len(s3, s4 - s3);
+
+	  word1 = g_strndup(s5, s6 - s5);
 	  if (st_str_like(word1, ST_NUMERIC))
 	    info->stream->station_id = atoi(word1);
 	  g_free(word1);
@@ -878,34 +904,23 @@
       else
 	PARSE_ERROR;
     }
-  else if ((s1 = st_strstr_span(line, "alt=\"More broadcaster info"))
-	   && (s2 = st_strchr_span(s1, '>'))
-	   && (s3 = strstr(s2, "</a>")))
-    {
-      if (info->stream)
-	{
-	  g_free(info->stream->broadcaster);
-	  info->stream->broadcaster = st_sgml_ref_expand_len(s2, s3 - s2);
-	}
-      else
-	PARSE_ERROR;
-    }
   else if ((s1 = st_str_has_prefix_span(line, "<TD  CLASS=\"connection\""))
 	   && (s2 = st_strchr_span(s1, '>'))
-	   && (s3 = strstr(s2, "<br>"))
-	   && ((s4 = strstr(s3, "<img src='/images/mp3pro"))
-	       || (s4 = strstr(s3, "</TD>"))))
+	   && (s3 = strchr(s2, '<')))
     {
       if (info->stream)
 	{
 	  word1 = st_sgml_ref_expand_len(s2, s3 - s2);
-	  s3 += 4; word2 = st_sgml_ref_expand_len(s3, s4 - s3);
-	  
+
 	  g_free(info->stream->audio);
-	  info->stream->audio = g_strdup_printf(g_str_has_prefix(s4, "</TD>") ? "%s %s" : "%s %s, MP3Pro", word2, word1);
 
-	  g_free(word1);
-	  g_free(word2);
+	  if (strstr(s3, "<img src='/images/mp3pro"))
+	    {
+	      info->stream->audio = g_strdup_printf("%s, MP3Pro", word1);
+	      g_free(word1);
+	    }
+	  else
+	    info->stream->audio = word1;
 	}
       else
 	PARSE_ERROR;
@@ -947,12 +962,17 @@
       else
 	PARSE_ERROR;
     }
-  else if (strstr(line, "TD  CLASS=\"tabledesc2\""))
+  else if ((s1 = st_strstr_span(line, "<TD  CLASS=\"desc\"")))
     {
       if (info->stream)
 	{
 	  if (info->stream->station_id)
 	    {
+	      if ((s2 = st_strstr_span(s1, "<a class='desc-link' href='"))
+		  && (s3 = st_strchr_span(s2, '>'))
+		  && (s4 = strstr(s3, "<BR>")))
+		info->stream->description = st_sgml_ref_expand_len(s3, s4 - s3);
+
 	      ((STStream *) info->stream)->name = g_strdup_printf("%i", info->stream->station_id);
 	      *(info->streams) = g_list_append(*(info->streams), info->stream);
 	    }
@@ -962,23 +982,23 @@
 	      stream_free_cb(info->stream, NULL);
 	    }
 
-	  info->finished_stream = info->stream;
 	  info->stream = NULL;
 	}
       else
 	PARSE_ERROR;
     }
-  else if ((s1 = st_strstr_span(line, "<a class='desc-link' href='"))
-	   && (s2 = st_strchr_span(s1, '>'))
-	   && (s3 = strstr(s2, "<BR>")))
-    {
-      if (info->finished_stream)
-	{
-	  info->finished_stream->description = st_sgml_ref_expand_len(s2, s3 - s2);
-	  info->finished_stream = NULL;
+  else if ((s1 = st_strstr_span(line, "<TD class=\"pagination\""))
+	   && (s2 = st_strstr_span(s1, ">Showing "))
+	   && (s3 = strchr(s2, '-')))
+    {
+      word1 = g_strndup(s2, s3 - s2);
+      if (st_str_like(word1, ST_NUMERIC))
+	{
+	  int n = atoi(word1);
+	  if (n == 1 && ! info->first_page)
+	    info->looped = TRUE;
 	}
-      else
-	PARSE_ERROR;
+      g_free(word1);
     }
   else if (strstr(line, "Next</A>"))
     info->has_next_page = TRUE;
