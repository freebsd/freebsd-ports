
$FreeBSD$

--- Shape.xs.orig	Tue Mar  4 14:18:00 2003
+++ Shape.xs	Mon Aug 23 16:42:18 2004
@@ -2,7 +2,7 @@
 #include "perl.h"
 #include "XSUB.h"
 
-#include <libshp/shapefil.h>
+#include <shapefil.h>
 
 
 MODULE = Shape		PACKAGE = Shape		
@@ -389,7 +389,7 @@
 				  case FTDouble:
 					if (!(sv = newSVnv(DBFReadDoubleAttribute(hDBF,record,field)))) goto BREAK;
 				  break;
-				  default:
+				  default: break;
 				}
 
 				hv_store(hv2, field_name, strlen(field_name), sv, 0);
