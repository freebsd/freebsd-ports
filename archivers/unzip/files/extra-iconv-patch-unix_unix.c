--- unix/unix.c.orig	2009-01-23 23:31:26 UTC
+++ unix/unix.c
@@ -30,6 +30,9 @@
 #define UNZIP_INTERNAL
 #include "unzip.h"
 
+#include <iconv.h>
+#include <langinfo.h>
+
 #ifdef SCO_XENIX
 #  define SYSNDIR
 #else  /* SCO Unix, AIX, DNIX, TI SysV, Coherent 4.x, ... */
@@ -1874,3 +1877,90 @@ static void qlfix(__G__ ef_ptr, ef_len)
     }
 }
 #endif /* QLZIP */
+
+
+typedef struct {
+    char *local_charset;
+    char *archive_charset;
+} CHARSET_MAP;
+
+/* A mapping of local <-> archive charsets used by default to convert filenames
+ * of DOS/Windows Zip archives. Currently very basic. */
+static CHARSET_MAP dos_charset_map[] = {
+    { "ANSI_X3.4-1968", "CP850" },
+    { "ISO-8859-1", "CP850" },
+    { "CP1252", "CP850" },
+    { "UTF-8", "CP866" },
+    { "KOI8-R", "CP866" },
+    { "KOI8-U", "CP866" },
+    { "ISO-8859-5", "CP866" }
+};
+
+char OEM_CP[MAX_CP_NAME] = "";
+char ISO_CP[MAX_CP_NAME] = "";
+
+/* Try to guess the default value of OEM_CP based on the current locale.
+ * ISO_CP is left alone for now. */
+void init_conversion_charsets()
+{
+    const char *local_charset;
+    int i;
+
+    /* Make a guess only if OEM_CP not already set. */ 
+    if(*OEM_CP == '\0') {
+    	local_charset = nl_langinfo(CODESET);
+    	for(i = 0; i < sizeof(dos_charset_map)/sizeof(CHARSET_MAP); i++)
+    		if(!strcasecmp(local_charset, dos_charset_map[i].local_charset)) {
+    			strncpy(OEM_CP, dos_charset_map[i].archive_charset,
+    					sizeof(OEM_CP));
+    			break;
+    		}
+    }
+}
+
+/* Convert a string from one encoding to the current locale using iconv().
+ * Be as non-intrusive as possible. If error is encountered during covertion
+ * just leave the string intact. */
+static void charset_to_intern(char *string, char *from_charset)
+{
+    iconv_t cd;
+    char *s,*d, *buf;
+    size_t slen, dlen, buflen;
+    const char *local_charset;
+
+    if(*from_charset == '\0')
+    	return;
+
+    buf = NULL;
+    local_charset = nl_langinfo(CODESET);
+
+    if((cd = iconv_open(local_charset, from_charset)) == (iconv_t)-1)
+        return;
+
+    slen = strlen(string);
+    s = string;
+    dlen = buflen = 2*slen;
+    d = buf = malloc(buflen + 1);
+    if(!d)
+    	goto cleanup;
+    bzero(buf,buflen);
+    if(iconv(cd, &s, &slen, &d, &dlen) == (size_t)-1)
+    	goto cleanup;
+    strncpy(string, buf, buflen);
+    
+    cleanup:
+    free(buf);
+    iconv_close(cd);
+}
+
+/* Convert a string from OEM_CP to the current locale charset. */
+inline void oem_intern(char *string)
+{
+    charset_to_intern(string, OEM_CP);
+}
+
+/* Convert a string from ISO_CP to the current locale charset. */
+inline void iso_intern(char *string)
+{
+    charset_to_intern(string, ISO_CP);
+}
