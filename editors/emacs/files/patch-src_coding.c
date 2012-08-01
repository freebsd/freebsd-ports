
$FreeBSD$

--- src/coding.c.orig
+++ src/coding.c
@@ -3717,8 +3717,20 @@
 	      else
 		charset = CHARSET_FROM_ID (charset_id_2);
 	      ONE_MORE_BYTE (c1);
-	      if (c1 < 0x20 || (c1 >= 0x80 && c1 < 0xA0))
-		goto invalid_code;
+	      /*
+	       * <ESC>N sequence is recognized as SS2 in some ISO2022
+	       * encodings.  As a workaround, mark invalid only if
+	       * <ESC>N + GR in a 7-bit encoding or <ESC>N + GL in an 8-bit
+	       * encoding.
+	       */
+	      if (CODING_ISO_FLAGS (coding) & CODING_ISO_FLAG_SEVEN_BITS) {
+		if (c1 < 0x20 || c1 >= 0x80)
+		  goto invalid_code;
+	      }
+	      else {
+		if (c1 < 0xA0)
+		  goto invalid_code;
+	      }
 	      break;
 
 	    case 'O':		/* invocation of single-shift-3 */
@@ -3731,8 +3743,20 @@
 	      else
 		charset = CHARSET_FROM_ID (charset_id_3);
 	      ONE_MORE_BYTE (c1);
-	      if (c1 < 0x20 || (c1 >= 0x80 && c1 < 0xA0))
-		goto invalid_code;
+	      /*
+	       * <ESC>O sequence by arrow keys is recognized as SS3 in
+	       * some ISO2022 encodings.  As a workaround, mark invalid only if
+	       * <ESC>O + GR in a 7-bit encoding or <ESC>O + GL in an 8-bit
+	       * encoding.
+	       */
+	      if (CODING_ISO_FLAGS (coding) & CODING_ISO_FLAG_SEVEN_BITS) {
+		if (c1 < 0x20 || c1 >= 0x80)
+		  goto invalid_code;
+	      }
+	      else {
+		if (c1 < 0xA0)
+		  goto invalid_code;
+	      }
 	      break;
 
 	    case '0': case '2':	case '3': case '4': /* start composition */
