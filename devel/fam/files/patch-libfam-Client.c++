diff -ruN libfam/Client.c++ libfam/Client.c++
--- libfam/Client.c++	Mon Apr 29 02:26:55 2002
+++ libfam/Client.c++	Sat Jun  8 16:31:07 2002
@@ -20,6 +20,7 @@
 //  with this program; if not, write the Free Software Foundation, Inc., 59
 //  Temple Place - Suite 330, Boston MA 02111-1307, USA.
 
+#include <stdio.h>
 #include <stdlib.h>
 #include <unistd.h>
 #include <netinet/in.h>
