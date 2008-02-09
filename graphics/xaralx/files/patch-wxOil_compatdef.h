--- wxOil/compatdef.h.orig	2006-08-10 22:36:43.000000000 +0300
+++ wxOil/compatdef.h	2008-02-09 09:23:24.000000000 +0200
@@ -595,6 +595,12 @@
 const size_t			MAX_PATH = 256;
 
 #if !defined(__WXMAC__)
+#if __FreeBSD__ >= 7
+#include <osreldate.h>
+#if __FreeBSD_version >= 700036
+#include <malloc_np.h>
+#endif /* __FreeBSD_version >= 700036 */
+#endif /* __FreeBSD__ >= 7 */
 inline size_t _msize( PVOID ptr )
 {
 	return malloc_usable_size( ptr );
