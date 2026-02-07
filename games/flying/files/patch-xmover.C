--- xmover.C.orig	Sun Jan  9 01:16:44 2000
+++ xmover.C	Sun Jan  9 01:16:51 2000
@@ -101,7 +101,7 @@
 	private:
 		int	ws;	// Bits klein
 		const int	wl;	// Bits gross
-		static mtab[9];
+		static int mtab[9];
 };
 
 int Stuffer::mtab[9] = { 0x00, 0x01, 0x03, 0x07, 0x0f, 0x1f, 0x3f, 0x7f, 0xff };
