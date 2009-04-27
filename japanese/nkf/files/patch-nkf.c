--- nkf.c.orig	2009-01-20 18:49:31.000000000 +0900
+++ nkf.c	2009-04-27 22:44:46.124911367 +0900
@@ -21,7 +21,7 @@
  * 3. This notice may not be removed or altered from any source distribution.
  */
 #define NKF_VERSION "2.0.9"
-#define NKF_RELEASE_DATE "2009-01-20"
+#define NKF_RELEASE_DATE "2009-02-21"
 #define COPY_RIGHT \
     "Copyright (C) 1987, FUJITSU LTD. (I.Ichikawa).\n" \
     "Copyright (C) 1996-2009, The nkf Project."
@@ -468,6 +468,8 @@
     {"Shift_JIS", 0, 0, 0, {0, 0, 0}, s_status, s_iconv, 0},
 #ifdef UTF8_INPUT_ENABLE
     {"UTF-8",     0, 0, 0, {0, 0, 0}, w_status, w_iconv, 0},
+    {"UTF-16",     0, 0, 0, {0, 0, 0}, NULL, w_iconv16, 0},
+    {"UTF-32",     0, 0, 0, {0, 0, 0}, NULL, w_iconv32, 0},
 #endif
     {0}
 };
@@ -1426,6 +1428,7 @@
 	output_endian = ENDIAN_LITTLE;
 	output_bom_f = TRUE;
 	break;
+    case UTF_32:
     case UTF_32BE_BOM:
 	output_bom_f = TRUE;
 	break;
@@ -6159,9 +6162,6 @@
 		    output_endian = ENDIAN_LITTLE;
 		} else if (cp[0] == 'B') {
 		    cp++;
-		} else {
-		    output_encoding = nkf_enc_from_index(enc_idx);
-		    continue;
 		}
 		if (cp[0] == '0'){
 		    cp++;
@@ -6232,6 +6232,7 @@
 	    while ('0'<= *cp && *cp <='9') {
 		alpha_f |= 1 << (*cp++ - '0');
 	    }
+	    if (alpha_f & ((1 << 2) | (1 << 3))) alpha_f |= 1;
 	    if (!alpha_f) alpha_f = 1;
 	    continue;
 	case 'x':   /* Convert X0201 kana to X0208 or X0201 Conversion */
