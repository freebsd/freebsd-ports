--- ./freebsd/map.h.orig	2008-04-26 04:19:39.000000000 -0400
+++ ./freebsd/map.h	2009-07-15 12:05:10.769719000 -0400
@@ -4,9 +4,9 @@
 
 /* 
 * File:    freebsd-map.h
-* CVS:     $Id: map.h,v 1.1 2008-04-26 08:19:39 servat Exp $
+* CVS:     $Id: map.h,v 1.4 2009/07/09 13:02:26 servat Exp $
 * Author:  Harald Servat
-*          harald.servat@gmail.com
+*          redcrash@gmail.com
 */
 
 #ifndef _FreeBSD_MAP_H_
@@ -27,6 +27,10 @@
 	CPU_P4,
 	CPU_K7,
 	CPU_K8,
+	CPU_ATOM,
+	CPU_CORE,
+	CPU_CORE2,
+	CPU_CORE2EXTREME,
 	CPU_LAST
 };
 
@@ -57,5 +61,9 @@
 #include "map-p4.h"
 #include "map-k7.h"
 #include "map-k8.h"
+#include "map-atom.h"
+#include "map-core.h"
+#include "map-core2.h"
+#include "map-core2-extreme.h"
 
 #endif /* _FreeBSD_MAP_H_ */
