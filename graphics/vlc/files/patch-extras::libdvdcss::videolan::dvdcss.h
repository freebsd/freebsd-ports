--- extras/libdvdcss/videolan/dvdcss.h.orig	Sun Oct 14 20:58:16 2001
+++ extras/libdvdcss/videolan/dvdcss.h	Sun Oct 14 20:59:33 2001
@@ -22,6 +22,8 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
  *****************************************************************************/
 
+#ifndef		__DVDCSS_H__
+#define		__DVDCSS_H__	1
 /*****************************************************************************
  * The libdvdcss structure
  *****************************************************************************/
@@ -59,3 +61,4 @@
                                     int i_flags );
 extern char *        dvdcss_error ( dvdcss_handle );
 
+#endif
