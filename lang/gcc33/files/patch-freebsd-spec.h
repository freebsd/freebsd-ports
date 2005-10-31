--- gcc/config/freebsd-spec.h.orig	Thu Jan 13 18:06:26 2005
+++ gcc/config/freebsd-spec.h	Sun Oct 30 21:22:05 2005
@@ -59,6 +59,8 @@ Boston, MA 02111-1307, USA.  */
 	  builtin_define ("__FreeBSD__=4");			       	\
 	else if (FBSD_MAJOR == 3)	       				\
 	  builtin_define ("__FreeBSD__=3");			       	\
+	else if (FBSD_MAJOR == 7)					\
+	  builtin_define ("__FreeBSD__=7");			       	\
 	else								\
 	  builtin_define ("__FreeBSD__");			       	\
 	builtin_define_std ("unix");					\
