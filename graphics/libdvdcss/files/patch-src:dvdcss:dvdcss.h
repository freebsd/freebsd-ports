--- src/dvdcss/dvdcss.h.orig	Tue Apr 16 16:04:36 2002
+++ src/dvdcss/dvdcss.h	Tue Apr 16 16:05:06 2002
@@ -22,6 +22,9 @@
  * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111, USA.
  *****************************************************************************/
 
+#ifndef	__DVDCSS_H__
+#define	__DVDCSS_H__
+
 /*****************************************************************************
  * The libdvdcss structure
  *****************************************************************************/
@@ -62,3 +65,4 @@
                                     int i_flags );
 extern char *        dvdcss_error ( dvdcss_handle );
 
+#endif	/* __DVDCSS_H__ */
