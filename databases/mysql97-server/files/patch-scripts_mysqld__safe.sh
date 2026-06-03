--- scripts/mysqld_safe.sh.orig	2022-01-23 11:48:36 UTC
+++ scripts/mysqld_safe.sh
@@ -360,7 +360,7 @@ mysqld_ld_preload_text() {
 # running mysqld.  See ld.so for details.
 set_malloc_lib() {
   # This list is kept intentionally simple.
-  malloc_dirs="/usr/lib /usr/lib64 /usr/lib/i386-linux-gnu /usr/lib/x86_64-linux-gnu"
+  malloc_dirs="/usr/lib /usr/lib64 /usr/lib/i386-linux-gnu /usr/lib/x86_64-linux-gnu /usr/local/lib"
   malloc_lib="$1"
 
   # Allow --malloc-lib='' to override other settings
@@ -379,6 +379,7 @@ set_malloc_lib() {
         /usr/lib64) ;;
         /usr/lib/i386-linux-gnu) ;;
         /usr/lib/x86_64-linux-gnu) ;;
+	/usr/local/lib) ;;
         *)
           log_error "--malloc-lib must be located in one of the directories: $malloc_dirs"
           exit 1
