--- ../connectivity/source/drivers/mozab/mozillasrc/MTypeConverter.cxx.orig	Mon Nov 26 14:52:26 2001
+++ ../connectivity/source/drivers/mozab/mozillasrc/MTypeConverter.cxx	Sat May 18 14:02:06 2002
@@ -2,9 +2,9 @@
  *
  *  $RCSfile: MTypeConverter.cxx,v $
  *
- *  $Revision: 1.3 $
+ *  $Revision: 1.4 $
  *
- *  last change: $Author: oj $ $Date: 2001/11/26 13:52:26 $
+ *  last change: $Author: fs $ $Date: 2002/05/17 12:08:41 $
  *
  *  The Contents of this file are made available subject to the terms of
  *  either of the following licenses
@@ -136,9 +136,11 @@
 	::rtl::OString os(ous,ous.getLength(),RTL_TEXTENCODING_ASCII_US);
 	return( ::std::string(os.getStr()));
 }
+#if 0
 // -------------------------------------------------------------------------
 ::std::string MTypeConverter::nsStringToStlString(nsString const &nss)
 {
 	return( ::std::string(nss.GetBuffer()));
 }
+#endif
 // -------------------------------------------------------------------------
