diff -ruN libfam/fam.c++ libfam/fam.c++
--- libfam/fam.c++.orig	Mon Apr 29 02:26:55 2002
+++ libfam/fam.c++	Sat Jun  8 16:54:04 2002
@@ -21,6 +21,7 @@
 //  Temple Place - Suite 330, Boston MA 02111-1307, USA.
 
 #include <sys/types.h>
+#include <rpc/rpc.h>
 #include <sys/time.h>
 #include <unistd.h>
 #include <stdlib.h>
@@ -80,7 +81,7 @@
     fc->client = new Client(LOCALHOSTNUMBER, famnumber, famversion);
     fc->fd = ((Client *)fc->client)->getSock();
     if (fc->fd < 0) {
-	delete fc->client;
+	delete (Client *)fc->client;
         fc->client = NULL;
 	return(-1);
     }
