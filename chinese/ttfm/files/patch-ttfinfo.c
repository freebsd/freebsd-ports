--- ttfinfo.c.orig	Sun Dec 17 02:56:41 2000
+++ ttfinfo.c	Tue Jul 30 10:48:21 2002
@@ -112,6 +112,7 @@
 static void  usage             (const char *name);
 static const char *get_foundry (const TT_Char orig_code[4]);
 static const char *get_name    (TT_Face face);
+static const char *get_psname  (TT_Face face);
 static void  add_mapping (struct xlfdmapping **listhead,
 			  char *file_name,
 			  const char *foundry_name,
@@ -684,6 +685,7 @@
     TT_Face face;
     TT_Face_Properties  properties;
     const char *font_name;
+    const char *font_psname;
     const char *foundry_name;
     const char *weight_name;
     const char *width_name;
@@ -722,6 +724,7 @@
     }
 
     font_name    = get_name (face);
+    font_psname  = get_psname (face);
     foundry_name = get_foundry (properties.os2->achVendID);
     weight_name  = get_weight (path, &properties);
     width_name   = get_width_name (path, &properties);
@@ -729,6 +732,7 @@
     /* basic fone information */
     fprintf(outstream,"TTFINFO_FONT_FILE=\"%s\"\n",path);
     fprintf(outstream,"TTFINFO_FONT_NAME=\"%s\"\n",font_name);
+    fprintf(outstream,"TTFINFO_FONT_PSNAME=\"%s\"\n",font_psname);
     fprintf(outstream,"TTFINFO_FOUNDRY_NAME=\"%s\"\n",foundry_name);
     fprintf(outstream,"TTFINFO_WEIGHT_NAME=\"%s\"\n",weight_name);
     fprintf(outstream,"TTFINFO_WIDTH=\"%s\"\n",width_name);
@@ -1206,7 +1210,7 @@
        function returns as soon as an english name for the font is found,
        so most of the time one loop is enough; however some fonts have only
        non-english names in their font faminly entry, so the second loop
-       to try the Postscript name as last ressort
+       to try the Postscript name as last resort
     */
     for (k = 0; k < 2; k++) {
 
@@ -1276,6 +1280,99 @@
 		    }
 	    }
 	}
+    }
+ 
+    /* Not found */
+    return "unknown";
+}
+
+/* This get_psname() function is copied from get_name().  I probably should
+   try to merge the two functions somehow, but unfortunately, I do not have
+   the time right now.  :-)  Anthony Fok <anthony@thizlinux.com>
+*/
+
+const char *
+get_psname (TT_Face face)
+{
+    int i, j, k, n;
+
+    TT_UShort  platform;
+    TT_UShort  encoding;
+    TT_UShort  language;
+    TT_UShort  NameId;
+
+    /* get the number of name strings in this font */
+    if ((n = TT_Get_Name_Count (face)) < 0) {
+	return NULL;
+    }
+    /* printf("\nn=%d\n",n); */
+
+    /* for (k = 0; k < 2; k++) { */
+
+    k = 1;
+	/* now look at every entry */
+	for (i = 0; i < n; i++) {
+	    TT_Get_Name_ID (face, i, &platform, &encoding, &language, &NameId);
+	    /*	    printf("k=%d, face=%d, i=%d, platform=%d, encoding=%d, lang=%d, Id=%d\n",k ,face, i, platform, encoding, language, NameId); */
+
+	    if (NameId == TT_NAME_ID_PS_NAME) {
+
+		/* Try a Macintosh english name */
+		if ((platform == TT_PLATFORM_MACINTOSH) && 
+		    (language == TT_MAC_LANGID_ENGLISH))
+		    {
+			char*  string;
+			TT_UShort string_len;
+			static char  name_buffer[257];
+			int   name_len;
+			int   english=1;
+
+			TT_Get_Name_String (face, i, &string, &string_len);
+			string_len =  string_len < 257 ? string_len : 257;
+			name_len = 0;
+
+			for (j = 0; j < string_len; j++) {
+			    /* some font names claim to be in english but aren't */
+			    if ((string[j] & 0xff) > 0x7f) english=0;
+			    name_buffer[name_len++] = string[j];
+			}
+
+			name_buffer[name_len] = '\0';
+			if (english) return name_buffer;
+		    }
+		/* Try to find an Apple Unicode or Microsoft English name */
+		if ((platform == TT_PLATFORM_APPLE_UNICODE) ||
+		    ((platform == TT_PLATFORM_MICROSOFT) &&
+		     ((language & 0x00FF) ==
+		      (TT_MS_LANGID_ENGLISH_UNITED_STATES & 0x00FF))) ||
+		    (((platform == TT_PLATFORM_MICROSOFT) &&
+		      (encoding == TT_MS_ID_UNICODE_CS)) &&
+		     (NameId == TT_NAME_ID_PS_NAME)))
+		    {
+			/* The following code was inspired from Mark Leisher's */
+			/* ttf2bdf package                                     */
+			char*  string;
+			TT_UShort string_len;
+			static char  name_buffer[513];
+			int   name_len;
+			int   english=1;
+
+			TT_Get_Name_String (face, i, &string, &string_len);
+			string_len =  string_len < 512 ? string_len : 512;
+			name_len = 0;
+			/* convert from unicode to ASCII */
+			for (j = 0; j < string_len; j ++) {
+			  /* drop the NULL part, dont't use j+=2 to avoid
+			     endian problem. */
+			  if (string[j] != '\0'){
+			    if ((string[j] & 0xff) > 0x7f) english=0;
+			    name_buffer[name_len++] = string[j];
+			  }
+			}
+			name_buffer[name_len] = '\0';
+			if (english) return name_buffer;
+		    }
+	    }
     }
  
     /* Not found */
