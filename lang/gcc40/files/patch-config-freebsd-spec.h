Index: gcc/config/freebsd-spec.h
===================================================================
RCS file: /cvs/gcc/gcc/gcc/config/freebsd-spec.h,v
retrieving revision 1.13
diff -u -3 -p -r1.13 freebsd-spec.h
--- gcc/config/freebsd-spec.h	23 Jan 2005 15:05:37 -0000	1.13
+++ gcc/config/freebsd-spec.h	27 Apr 2005 17:37:38 -0000
@@ -78,6 +78,7 @@ Boston, MA 02111-1307, USA.  */
 
 #define FBSD_CPP_SPEC "							\
   %(cpp_cpu)								\
+  %(cpp_arch)								\
   %{fPIC|fpic|fPIE|fpie:-D__PIC__ -D__pic__}				\
   %{posix:-D_POSIX_SOURCE}"
 
