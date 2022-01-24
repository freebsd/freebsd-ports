--- qrq.c.orig	2022-01-22 09:18:24 UTC
+++ qrq.c
@@ -61,6 +61,7 @@ typedef int AUDIO_HANDLE;
 
 #define CALL_MAX    28    /* maximum allowed length of a call/word. limit to 28 so we can fit word + correction into the window */
 
+#define PREFIX "%%PREFIX%%"
 #ifndef DESTDIR
 #	define DESTDIR "/usr"
 #endif
@@ -208,7 +209,7 @@ int main (int argc, char *argv[]) {
   }
   strcat(destdir, "/Resources");
 #else
-  strcpy(destdir, DESTDIR);
+  strcpy(destdir, PREFIX);
 #endif
 
 	char abort = 0;
@@ -1867,8 +1868,8 @@ static int check_toplist () {
  * The can be: 
  * 1) In the current directory -> use them
  * 2) In ~/.qrq/  -> use toplist and qrqrc from there and callbase from
- *    DESTDIR/share/qrq/
- * 3) in DESTDIR/share/qrq/ -> create ~/.qrq/ and copy qrqrc and toplist
+ *    PREFIX/share/qrq/
+ * 3) in PREFIX/share/qrq/ -> create ~/.qrq/ and copy qrqrc and toplist
  *    there.
  * 4) Nowhere --> Exit.*/
 static int find_files () {
