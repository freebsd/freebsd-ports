Index: qemu/sdl.c
@@ -115,9 +115,9 @@
    0xb5,      /* 112  Divide */
    0xb8,      /* 113  Alt-R  */
    0xc6,      /* 114  Break  */   
-   0x0,         /* 115 */
-   0x0,         /* 116 */
-   0x0,         /* 117 */
+   0xdb,         /* 115 windows left button */
+   0xdc,         /* 116 windows right button */
+   0xdd,         /* 117 right menu button */
    0x0,         /* 118 */
    0x0,         /* 119 */
    0x70,         /* 120 Hiragana_Katakana */
