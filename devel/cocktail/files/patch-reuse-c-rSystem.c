--- /usr/ports/devel/cocktail/work/cocktail-9309//./reuse/c/rSystem.c	Tue Feb 15 14:26:43 1994
+++ ./reuse/c/rSystem.c	Fri Sep 10 13:35:03 2004
@@ -12,14 +12,15 @@
 /* compilation with the option -DUNIX uses UNIX system calls for IO (efficient),
    otherwise the C library routines are used for IO (portable).			*/
 
-static char rcsid [] = "$Id: rSystem.c,v 1.10 1993/08/19 09:53:41 grosch rel $";
+# include <sys/cdefs.h>
+__RCSID("$Id: rSystem.c,v 1.10 1993/08/19 09:53:41 grosch rel $");
 
 # include "rSystem.h"
 
 # ifdef m68000
-# define hz 50
+# define HZ 50
 # else
-# define hz 60
+# define HZ 60
 # endif
 
 # ifndef UNIX
@@ -57,6 +58,12 @@
 # include <fcntl.h>
 # include <sys/types.h>
 # include <sys/stat.h>
+# include <stdlib.h>
+
+# ifdef UNIX
+# include <sys/uio.h>
+# include <unistd.h>
+# endif
 
 bool IsCharacterSpecial (File) tFile File;
 {
@@ -98,7 +105,7 @@
 # endif
    return FilePtr == NULL ? -1 : FileToInt (FilePtr);
 # else
-   return creat (FileName, 0666);
+   return creat (FileName, (mode_t)(0666));
 # endif
 }
 
@@ -115,7 +122,7 @@
    } else
       return fread (Buffer, 1, Size, IntToFile (File));
 # else
-   return read (File, Buffer, Size);
+   return read (File, (void*)Buffer, (size_t)Size);
 # endif
 }
 
@@ -127,7 +134,7 @@
 # ifndef UNIX
    return fwrite (Buffer, 1, Size, IntToFile (File));
 # else
-   return write (File, Buffer, Size);
+   return write (File, Buffer, (size_t)Size);
 # endif
 }
 
@@ -143,9 +150,11 @@
 
 /* calls other than IO */
 
-/* # include <malloc.h> */
-
-char * rAlloc (ByteCount) long ByteCount; { return (char *) malloc ((unsigned) ByteCount); }
+char * rAlloc (ByteCount) 
+    long ByteCount; 
+{ 
+    return (char *) calloc (1UL, (size_t) ByteCount); 
+}
 
 # include <sys/times.h>
 
@@ -156,7 +165,7 @@
 # else
    struct tms	buffer;
    (void) times (& buffer);
-   return (buffer.tms_utime + buffer.tms_stime) * 1000 / hz;
+   return (buffer.tms_utime + buffer.tms_stime) * 1000 / HZ;
 # endif
 }
 
@@ -187,12 +196,10 @@
 
 # include <errno.h>
 
-int rErrNo () { return errno; }
+int rErrNo (NOARGS) { return errno; }
 
 int rSystem (String) char * String; { return system (String); }
 
-extern void exit ();
-
 void rExit (Status) int Status; { exit (Status); }
 
-void BEGIN_rSystem () {}
+void BEGIN_rSystem (NOARGS) {}
