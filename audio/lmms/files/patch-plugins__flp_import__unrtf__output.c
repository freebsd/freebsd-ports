--- plugins/flp_import/unrtf/output.c.orig	2009-02-24 07:34:26.000000000 +0900
+++ plugins/flp_import/unrtf/output.c	2009-04-10 22:19:43.000000000 +0900
@@ -238,49 +238,49 @@
 	switch (size) {
 	case 8:
 		if (op->fontsize8_begin) {
-			outstring+=QString().sprintf(op->fontsize8_begin);
+			outstring+=QString().sprintf("%s", op->fontsize8_begin);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 10:
 		if (op->fontsize10_begin) {
-			outstring+=QString().sprintf(op->fontsize10_begin);
+			outstring+=QString().sprintf("%s", op->fontsize10_begin);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 12:
 		if (op->fontsize12_begin) {
-			outstring+=QString().sprintf(op->fontsize12_begin);
+			outstring+=QString().sprintf("%s", op->fontsize12_begin);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 14:
 		if (op->fontsize14_begin) {
-			outstring+=QString().sprintf(op->fontsize14_begin);
+			outstring+=QString().sprintf("%s", op->fontsize14_begin);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 18:
 		if (op->fontsize18_begin) {
-			outstring+=QString().sprintf(op->fontsize18_begin);
+			outstring+=QString().sprintf("%s", op->fontsize18_begin);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 24:
 		if (op->fontsize24_begin) {
-			outstring+=QString().sprintf(op->fontsize24_begin);
+			outstring+=QString().sprintf("%s", op->fontsize24_begin);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 36:
 		if (op->fontsize36_begin) {
-			outstring+=QString().sprintf(op->fontsize36_begin);
+			outstring+=QString().sprintf("%s", op->fontsize36_begin);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 48:
 		if (op->fontsize48_begin) {
-			outstring+=QString().sprintf(op->fontsize48_begin);
+			outstring+=QString().sprintf("%s", op->fontsize48_begin);
 			found_std_expr = TRUE;
 		}
 		break;
@@ -300,46 +300,46 @@
 			 * size.
 			 */
 			if (size<9 && op->fontsize8_begin) {
-				outstring+=QString().sprintf(op->fontsize8_begin);
+				outstring+=QString().sprintf("%s", op->fontsize8_begin);
 			} else 
 			if (size<11 && op->fontsize10_begin) {
-				outstring+=QString().sprintf(op->fontsize10_begin);
+				outstring+=QString().sprintf("%s", op->fontsize10_begin);
 			} else 
 			if (size<13 && op->fontsize12_begin) {
-				outstring+=QString().sprintf(op->fontsize12_begin);
+				outstring+=QString().sprintf("%s", op->fontsize12_begin);
 			} else 
 			if (size<16 && op->fontsize14_begin) {
-				outstring+=QString().sprintf(op->fontsize14_begin);
+				outstring+=QString().sprintf("%s", op->fontsize14_begin);
 			} else 
 			if (size<21 && op->fontsize18_begin) {
-				outstring+=QString().sprintf(op->fontsize18_begin);
+				outstring+=QString().sprintf("%s", op->fontsize18_begin);
 			} else 
 			if (size<30 && op->fontsize24_begin) {
-				outstring+=QString().sprintf(op->fontsize24_begin);
+				outstring+=QString().sprintf("%s", op->fontsize24_begin);
 			} else 
 			if (size<42 && op->fontsize36_begin) {
-				outstring+=QString().sprintf(op->fontsize36_begin);
+				outstring+=QString().sprintf("%s", op->fontsize36_begin);
 			} else 
 			if (size>40 && op->fontsize48_begin) {
-				outstring+=QString().sprintf(op->fontsize48_begin);
+				outstring+=QString().sprintf("%s", op->fontsize48_begin);
 			} else 
 			/* If we can't even produce a good approximation,
 			 * just try to get a font size near 12 point.
 			 */
 			if (op->fontsize12_begin)
-				outstring+=QString().sprintf(op->fontsize12_begin);
+				outstring+=QString().sprintf("%s", op->fontsize12_begin);
 			else
 			if (op->fontsize14_begin)
-				outstring+=QString().sprintf(op->fontsize14_begin);
+				outstring+=QString().sprintf("%s", op->fontsize14_begin);
 			else
 			if (op->fontsize10_begin)
-				outstring+=QString().sprintf(op->fontsize10_begin);
+				outstring+=QString().sprintf("%s", op->fontsize10_begin);
 			else
 			if (op->fontsize18_begin)
-				outstring+=QString().sprintf(op->fontsize18_begin);
+				outstring+=QString().sprintf("%s", op->fontsize18_begin);
 			else
 			if (op->fontsize8_begin)
-				outstring+=QString().sprintf(op->fontsize8_begin);
+				outstring+=QString().sprintf("%s", op->fontsize8_begin);
 			else
 				error_handler ("output personality lacks sufficient font size change capability");
 		}
@@ -367,49 +367,49 @@
 	switch (size) {
 	case 8:
 		if (op->fontsize8_end) {
-			outstring+=QString().sprintf(op->fontsize8_end);
+			outstring+=QString().sprintf("%s", op->fontsize8_end);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 10:
 		if (op->fontsize10_end) {
-			outstring+=QString().sprintf(op->fontsize10_end);
+			outstring+=QString().sprintf("%s", op->fontsize10_end);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 12:
 		if (op->fontsize12_end) {
-			outstring+=QString().sprintf(op->fontsize12_end);
+			outstring+=QString().sprintf("%s", op->fontsize12_end);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 14:
 		if (op->fontsize14_end) {
-			outstring+=QString().sprintf(op->fontsize14_end);
+			outstring+=QString().sprintf("%s", op->fontsize14_end);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 18:
 		if (op->fontsize18_end) {
-			outstring+=QString().sprintf(op->fontsize18_end);
+			outstring+=QString().sprintf("%s", op->fontsize18_end);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 24:
 		if (op->fontsize24_end) {
-			outstring+=QString().sprintf(op->fontsize24_end);
+			outstring+=QString().sprintf("%s", op->fontsize24_end);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 36:
 		if (op->fontsize36_end) {
-			outstring+=QString().sprintf(op->fontsize36_end);
+			outstring+=QString().sprintf("%s", op->fontsize36_end);
 			found_std_expr = TRUE;
 		}
 		break;
 	case 48:
 		if (op->fontsize48_end) {
-			outstring+=QString().sprintf(op->fontsize48_end);
+			outstring+=QString().sprintf("%s", op->fontsize48_end);
 			found_std_expr = TRUE;
 		}
 		break;
@@ -429,46 +429,46 @@
 			 * size.
 			 */
 			if (size<9 && op->fontsize8_end) {
-				outstring+=QString().sprintf(op->fontsize8_end);
+				outstring+=QString().sprintf("%s", op->fontsize8_end);
 			} else 
 			if (size<11 && op->fontsize10_end) {
-				outstring+=QString().sprintf(op->fontsize10_end);
+				outstring+=QString().sprintf("%s", op->fontsize10_end);
 			} else 
 			if (size<13 && op->fontsize12_end) {
-				outstring+=QString().sprintf(op->fontsize12_end);
+				outstring+=QString().sprintf("%s", op->fontsize12_end);
 			} else 
 			if (size<16 && op->fontsize14_end) {
-				outstring+=QString().sprintf(op->fontsize14_end);
+				outstring+=QString().sprintf("%s", op->fontsize14_end);
 			} else 
 			if (size<21 && op->fontsize18_end) {
-				outstring+=QString().sprintf(op->fontsize18_end);
+				outstring+=QString().sprintf("%s", op->fontsize18_end);
 			} else 
 			if (size<30 && op->fontsize24_end) {
-				outstring+=QString().sprintf(op->fontsize24_end);
+				outstring+=QString().sprintf("%s", op->fontsize24_end);
 			} else 
 			if (size<42 && op->fontsize36_end) {
-				outstring+=QString().sprintf(op->fontsize36_end);
+				outstring+=QString().sprintf("%s", op->fontsize36_end);
 			} else 
 			if (size>40 && op->fontsize48_end) {
-				outstring+=QString().sprintf(op->fontsize48_end);
+				outstring+=QString().sprintf("%s", op->fontsize48_end);
 			} else 
 			/* If we can't even produce a good approximation,
 			 * just try to get a font size near 12 point.
 			 */
 			if (op->fontsize12_end)
-				outstring+=QString().sprintf(op->fontsize12_end);
+				outstring+=QString().sprintf("%s", op->fontsize12_end);
 			else
 			if (op->fontsize14_end)
-				outstring+=QString().sprintf(op->fontsize14_end);
+				outstring+=QString().sprintf("%s", op->fontsize14_end);
 			else
 			if (op->fontsize10_end)
-				outstring+=QString().sprintf(op->fontsize10_end);
+				outstring+=QString().sprintf("%s", op->fontsize10_end);
 			else
 			if (op->fontsize18_end)
-				outstring+=QString().sprintf(op->fontsize18_end);
+				outstring+=QString().sprintf("%s", op->fontsize18_end);
 			else
 			if (op->fontsize8_end)
-				outstring+=QString().sprintf(op->fontsize8_end);
+				outstring+=QString().sprintf("%s", op->fontsize8_end);
 			else
 				error_handler ("output personality lacks sufficient font size change capability");
 		}
