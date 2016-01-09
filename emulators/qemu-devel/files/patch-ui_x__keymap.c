--- ui/x_keymap.c.orig	2015-12-16 00:59:05 UTC
+++ ui/x_keymap.c
@@ -43,9 +43,9 @@ static const uint8_t x_keycode_to_pc_key
    0xb5,      /* 112  Divide */
    0xb8,      /* 113  Alt-R  */
    0xc6,      /* 114  Break  */
-   0x0,         /* 115 */
-   0x0,         /* 116 */
-   0x0,         /* 117 */
+   0xdb,      /* 115 left windows key */
+   0xdc,      /* 116 right windows key */
+   0xdd,      /* 117 right menu key */
    0x0,         /* 118 */
    0x0,         /* 119 */
    0x0,         /* 120 */
