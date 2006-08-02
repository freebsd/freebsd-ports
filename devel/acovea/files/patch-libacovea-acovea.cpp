diff -urN libacovea.orig/acovea.cpp libacovea/acovea.cpp
--- libacovea.orig/acovea.cpp	Tue Aug  1 19:58:27 2006
+++ libacovea/acovea.cpp	Tue Aug  1 19:58:38 2006
@@ -43,6 +43,7 @@
 #include <fcntl.h>
 #include <unistd.h>
 #include <sys/types.h>
+#include <sys/stat.h>
 #include <sys/wait.h>
 
 #include <vector>
