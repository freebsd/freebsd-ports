$NetBSD: patch-libbase_IOChannel.h,v 1.1 2013/08/31 14:52:14 joerg Exp $

--- libbase/IOChannel.h.orig	2013-08-31 11:55:31.000000000 +0000
+++ libbase/IOChannel.h
@@ -24,6 +24,7 @@
 #include <string>
 #include <boost/cstdint.hpp> // for boost int types
 #include <iosfwd>
+#include <ios>
 
 #include "dsodefs.h" // DSOEXPORT
 #include "GnashException.h" // for IOException inheritance
