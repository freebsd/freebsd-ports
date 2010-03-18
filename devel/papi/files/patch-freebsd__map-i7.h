Index: freebsd/map-i7.h
diff -u freebsd/map-i7.h:1.1.2.1 freebsd/map-i7.h:1.1.2.2
--- freebsd/map-i7.h:1.1.2.1	Sat Oct 31 06:16:53 2009
+++ freebsd/map-i7.h	Sat Mar  6 11:12:08 2010
@@ -4,7 +4,7 @@
 
 /* 
 * File:    map-i7.h
-* CVS:     $Id: map-i7.h,v 1.1.2.1 2009/10/31 10:16:53 servat Exp $
+* CVS:     $Id: map-i7.h,v 1.1.2.2 2010/03/06 16:12:08 servat Exp $
 * Author:  George Neville-Neil
 *          gnn@freebsd.org
 */
@@ -310,6 +310,9 @@
 	PNE_I7_SIMD_INT_64_PACKED_LOGICAL,
 	PNE_I7_SIMD_INT_64_PACKED_ARITH,
 	PNE_I7_SIMD_INT_64_SHUFFLE_MOVE,
+	PNE_I7_INSTR_RETIRED_ANY,
+	PNE_I7_CPU_CLK_UNHALTED_CORE,
+	PNE_I7_CPU_CLK_UNHALTED_REF,
 	PNE_I7_NATNAME_GUARD
 };
 
