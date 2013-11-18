--- libiqxmlrpc/except.h.orig	2013-11-18 21:00:03.000000000 +0700
+++ libiqxmlrpc/except.h	2013-11-18 20:59:49.000000000 +0700
@@ -7,6 +7,7 @@
 #include "api_export.h"
 
 #include <stdexcept>
+#include <string>
 
 // Exceptions are conformant ot Fault Code Interoperability, version 20010516.
 // http://xmlrpc-epi.sourceforge.net/specs/rfc.fault_codes.php
