diff -u -r1.43 -r1.44
--- include/dos_inc.h	2004/05/05 21:56:04	1.43
+++ include/dos_inc.h	2004/05/15 07:57:02	1.44
@@ -214,22 +214,22 @@
 
 class MemStruct {
 public:
-	INLINE Bit8u GetIt(Bit8u&,PhysPt addr) {
+	INLINE Bit8u GetIt(Bit8u,PhysPt addr) {
 		return mem_readb(pt+addr);
 	}
-	INLINE Bit16u GetIt(Bit16u&,PhysPt addr) {
+	INLINE Bit16u GetIt(Bit16u,PhysPt addr) {
 		return mem_readw(pt+addr);
 	}
-	INLINE Bit32u GetIt(Bit32u&,PhysPt addr) {
+	INLINE Bit32u GetIt(Bit32u,PhysPt addr) {
 		return mem_readd(pt+addr);
 	}
-	INLINE void SaveIt(Bit8u&,PhysPt addr,Bit8u val) {
+	INLINE void SaveIt(Bit8u,PhysPt addr,Bit8u val) {
 		mem_writeb(pt+addr,val);
 	}
-	INLINE void SaveIt(Bit16u&,PhysPt addr,Bit16u val) {
+	INLINE void SaveIt(Bit16u,PhysPt addr,Bit16u val) {
 		mem_writew(pt+addr,val);
 	}
-	INLINE void SaveIt(Bit32u&,PhysPt addr,Bit32u val) {
+	INLINE void SaveIt(Bit32u,PhysPt addr,Bit32u val) {
 		mem_writed(pt+addr,val);
 	}
 	INLINE void SetPt(Bit16u seg) { pt=PhysMake(seg,0);}

