--- ./xbase/xbstring.cpp.orig	Tue Feb 20 18:53:26 2001
+++ ./xbase/xbstring.cpp	Sat Nov 22 22:25:08 2003
@@ -582,7 +582,7 @@
 //! Short description.
 /*!
 */
-XBDLLEXPORT ostream& operator << ( ostream& os, const xbString& xbs ) {
+XBDLLEXPORT std::ostream& operator << ( std::ostream& os, const xbString& xbs ) {
   return os << xbs.data;
 }
 
