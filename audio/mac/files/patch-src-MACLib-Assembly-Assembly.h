--- src/MACLib/Assembly/Assembly.h.orig	Wed May 12 06:35:56 2004
+++ src/MACLib/Assembly/Assembly.h	Mon Aug  9 20:26:40 2004
@@ -6,7 +6,7 @@
     void Adapt(short * pM, const short * pAdapt, int nDirection, int nOrder);
     int CalculateDotProduct(const short * pA, const short * pB, int nOrder);
     BOOL GetMMXAvailable();
-};
+}
 
 #endif // #ifndef APE_ASSEMBLY_H
 
