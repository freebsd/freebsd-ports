Index: ext/io/wait/wait.c
===================================================================
RCS file: /src/shim/ruby16/ext/io/wait/wait.c,v
retrieving revision 1.1
retrieving revision 1.2
diff -u -r1.1 -r1.2
--- ext/io/wait/wait.c	19 Oct 2003 20:40:52 -0000	1.1
+++ ext/io/wait/wait.c	1 Nov 2003 09:09:35 -0000	1.2
@@ -3,7 +3,7 @@
   io/wait.c -
 
   $Author: knu $
-  $Date: 2003/10/19 20:40:52 $
+  $Date: 2003/11/01 09:09:35 $
   created at: Tue Aug 28 09:08:06 JST 2001
 
   All the files in this distribution are covered under the Ruby's
@@ -14,6 +14,7 @@
 #include "ruby.h"
 #include "rubyio.h"
 
+#include <sys/time.h>
 #include <sys/types.h>
 #include FIONREAD_HEADER
 
