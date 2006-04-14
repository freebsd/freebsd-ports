
$FreeBSD$

--- src/ComTerp/comterpserv.c.orig
+++ src/ComTerp/comterpserv.c
@@ -152,7 +152,7 @@
     fbuf.attach(fd);
     istream in (&fbuf);
     in.gets(&instr);
-#elif (__GNUC__==3 && __GNUC_MINOR__<1) || __GNUC__>3
+#elif (__GNUC__==3 && __GNUC_MINOR__<1) || __GNUC__>3 || defined(__FreeBSD__)
     char instr[BUFSIZ];
     FILE* ifptr = fdopen(fd, "r");
     fileptr_filebuf fbuf(ifptr, ios_base::in);
@@ -160,6 +160,7 @@
     in.get(instr, BUFSIZ, '\n');  // needs to be generalized with <vector.h>
 #else
     char instr[BUFSIZ];
+    fileptr_filebuf fbuf(ifptr, ios_base::in);
     fileptr_filebuf fbuf(fd, ios_base::in, false, static_cast<size_t>(BUFSIZ));
     istream in (&fbuf);
     in.get(instr, BUFSIZ, '\n');  // needs to be generalized with <vector.h>
@@ -202,7 +203,7 @@
 #if __GNUC__<3
     filebuf fbuf;
     fbuf.attach(fd);
-#elif (__GNUC__==3 && __GNUC_MINOR__<1) || __GNUC__>3
+#elif (__GNUC__==3 && __GNUC_MINOR__<1) || __GNUC__>3  || defined(__FreeBSD__)
     FILE* ofptr = fdopen(fd, "w");
     fileptr_filebuf fbuf(ofptr, ios_base::out);
 #else
@@ -320,7 +321,7 @@
 	        err_print( stderr, "comterp" );
 #if __GNUC__<3
 	        filebuf obuf(handler() ? handler()->get_handle() : 1);
-#elif __GNUC__==3 && __GNUC_MINOR__<1 || __GNUC__>3
+#elif __GNUC__==3 && __GNUC_MINOR__<1 || __GNUC__>3  || defined(__FreeBSD__)
                 FILE* ofptr = fdopen(handler() ? handler()->get_handle() : 1, "w"); 
 	        fileptr_filebuf obuf(ofptr, ios_base::out);
 #else
@@ -345,7 +346,7 @@
 	  err_print( stderr, "comterp" );
 #if __GNUC__<3
 	  filebuf obuf(handler() ? handler()->get_handle() : 1);
-#elif __GNUC__==3 && __GNUC_MINOR__<1 || __GNUC__>3
+#elif __GNUC__==3 && __GNUC_MINOR__<1 || __GNUC__>3  || defined(__FreeBSD__)
           FILE* ofptr = fdopen(handler() ? handler()->get_handle() : 1, "w"); 
 	  fileptr_filebuf obuf(ofptr, ios_base::out);
 #else
