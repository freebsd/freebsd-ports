--- gdb/config/sparc/fbsd.mt.orig	Wed Mar 13 03:20:24 2002
+++ gdb/config/sparc/fbsd.mt	Thu Oct 17 05:59:59 2002
@@ -19,5 +19,6 @@
 #  Foundation, Inc., 675 Mass Ave, Cambridge, MA 02139, USA.  */
 
 # Target: FreeBSD/sparc64
-TDEPFILES= sparc-tdep.o solib.o solib-svr4.o solib-legacy.o 
+TDEPFILES= sparc-tdep.o sparcnbsd-tdep.o nbsd-tdep.o corelow.o solib.o \
+	solib-svr4.o solib-legacy.o
 TM_FILE= tm-fbsd.h
