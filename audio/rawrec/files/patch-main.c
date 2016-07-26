--- main.c.orig	2006-01-22 02:40:17 UTC
+++ main.c
@@ -14,6 +14,12 @@
 
 #include "rawrec.h"
 
+size_t strnlen (const char *string, size_t maxlen)
+{
+    const char *end = memchr (string, '\0', maxlen);
+    return end ? (size_t) (end - string) : maxlen;
+}
+
 int main(int argc, char *argv[])
 {
   /* Action for ignoring signals we don't want to deal with.  */
@@ -118,6 +124,7 @@ int main(int argc, char *argv[])
   strncpy(cnst_dflt_format, "s16_le", (size_t) (MAX_FORMAT_STRING_LENGTH + 1));
 
   /* at the moment, this application goes with the default for most signals */
+  ignorer_act.sa_flags = 0;
   ignorer_act.sa_handler = SIG_IGN;
   /* because I'm unclear on how SIGIO is supposed to work, it's not 
      applicable here, and I'm paranoid */
