--- camel/providers/groupwise/camel-groupwise-utils.c.orig	Mon Oct  3 11:05:45 2005
+++ camel/providers/groupwise/camel-groupwise-utils.c	Thu Nov 10 05:36:51 2005
@@ -339,8 +339,9 @@
 	attachment->name = g_strdup (filename ? filename : "");
 	if (!g_ascii_strncasecmp (attachment->contentType, RFC_822, strlen (RFC_822))) {
 		char *temp_id = NULL, *id = NULL;
+		int len;
 		temp_id = (char *)camel_medium_get_header (CAMEL_MEDIUM ((CamelMimeMessage *)dw), "Message-Id");
-		int len = strlen (temp_id);
+		len = strlen (temp_id);
 
 		id = (char *)g_malloc0 (len-1);
 		id = memcpy(id, temp_id+2, len-3);
@@ -430,9 +431,10 @@
 			dw = camel_medium_get_content_object (CAMEL_MEDIUM (part));
 			if (type->subtype && !strcmp (type->subtype, "alternative")) {
 				CamelMimePart *temp_part;
+				CamelDataWrapper *temp_dw;
 				CamelStreamMem *temp_content = (CamelStreamMem *)camel_stream_mem_new ();
 				temp_part = camel_multipart_get_part ((CamelMultipart *)dw, 1);
-				CamelDataWrapper *temp_dw = camel_data_wrapper_new ();
+				temp_dw = camel_data_wrapper_new ();
 				if (temp_part) {
 					is_alternative = TRUE;
 					temp_dw = camel_medium_get_content_object (CAMEL_MEDIUM (temp_part));
