--- src/fdrivers/driver16.h.orig
+++ src/fdrivers/driver16.h
@@ -46,7 +46,7 @@
 # define repfill16_and   repfill_w_f_and
 # define repfill16       repfill_w_f
 # define SETFARSEL(sel)  setup_far_selector(sel)
-# if defined(__GNUC__) && defined(__i386__)
+# if defined(__GNUC__) && defined(__i386__) && !defined(__clang__)
 #   define ASM_386_SEL   I386_GCC_FAR_SELECTOR
 # endif /* GCC i386 */
 #else /* defined FAR_ACCESS */
@@ -180,7 +180,7 @@
     GRX_LEAVE();
 }
 
-#if defined(__GNUC__) && defined(__i386__)
+#if defined(__GNUC__) && defined(__i386__) && !defined(__clang__)
 static void drawline(int x,int y,int dx,int dy,GrColor color)
 {
     struct {
@@ -196,6 +196,7 @@
 
 #   ifdef __GNUC__
 #   ifdef __i386__
+#   ifndef __clang__
 #   define ASM_LINE1(OPC) asm volatile(""              \
 	"   .align 2,0x90                      \n"     \
 	"0: "#OPC"w %6,"ASM_386_SEL"(%0)       \n"     \
@@ -236,6 +237,7 @@
 	)
 #   endif
 #   endif
+#   endif
 
     if(dy < 0) {
 	y -= (dy = (-dy));
