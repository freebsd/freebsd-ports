--- main.c.orig	2006-01-22 03:40:17.000000000 +0100
+++ main.c	2014-12-07 19:14:39.778784753 +0100
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
@@ -118,6 +124,7 @@
   strncpy(cnst_dflt_format, "s16_le", (size_t) (MAX_FORMAT_STRING_LENGTH + 1));
 
   /* at the moment, this application goes with the default for most signals */
+  ignorer_act.sa_flags = 0;
   ignorer_act.sa_handler = SIG_IGN;
   /* because I'm unclear on how SIGIO is supposed to work, it's not 
      applicable here, and I'm paranoid */
