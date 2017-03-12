--- src/mpi/mpi_caf.c.orig	2017-02-07 05:19:01 UTC
+++ src/mpi/mpi_caf.c
@@ -37,7 +37,6 @@ SOFTWARE, EVEN IF ADVISED OF THE POSSIBI
 #include <stdlib.h>
 #include <string.h>        /* For memcpy.  */
 #include <stdarg.h>        /* For variadic arguments.  */
-#include <alloca.h>
 #include <unistd.h>
 #include <mpi.h>
 #include <pthread.h>
