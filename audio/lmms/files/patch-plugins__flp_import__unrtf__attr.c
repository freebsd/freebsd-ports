--- plugins/flp_import/unrtf/attr.c.orig	2009-02-24 07:34:26.000000000 +0900
+++ plugins/flp_import/unrtf/attr.c	2009-04-10 22:19:43.000000000 +0900
@@ -108,10 +108,10 @@
 	switch(attr) 
 	{
 	case ATTR_BOLD: 
-		outstring+=QString().sprintf(op->bold_begin); 
+		outstring+=QString().sprintf("%s", op->bold_begin); 
 		break;
 	case ATTR_ITALIC: 
-		outstring+=QString().sprintf(op->italic_begin); 
+		outstring+=QString().sprintf("%s", op->italic_begin); 
 		break;
 
 	/* Various underlines, they all resolve to HTML's <u> */
@@ -123,11 +123,11 @@
 	case ATTR_2DOT_DASH_UL:
 	case ATTR_WORD_UL: 
 	case ATTR_UNDERLINE: 
-		outstring+=QString().sprintf(op->underline_begin); 
+		outstring+=QString().sprintf("%s", op->underline_begin); 
 		break;
 
 	case ATTR_DOUBLE_UL: 
-		outstring+=QString().sprintf(op->dbl_underline_begin); 
+		outstring+=QString().sprintf("%s", op->dbl_underline_begin); 
 		break;
 
 	case ATTR_FONTSIZE: 
@@ -148,18 +148,18 @@
 		break;
 
 	case ATTR_SUPER: 
-		outstring+=QString().sprintf(op->superscript_begin); 
+		outstring+=QString().sprintf("%s", op->superscript_begin); 
 		break;
 	case ATTR_SUB: 
-		outstring+=QString().sprintf(op->subscript_begin); 
+		outstring+=QString().sprintf("%s", op->subscript_begin); 
 		break;
 
 	case ATTR_STRIKE: 
-		outstring+=QString().sprintf(op->strikethru_begin); 
+		outstring+=QString().sprintf("%s", op->strikethru_begin); 
 		break;
 
 	case ATTR_DBL_STRIKE: 
-		outstring+=QString().sprintf(op->dbl_strikethru_begin); 
+		outstring+=QString().sprintf("%s", op->dbl_strikethru_begin); 
 		break;
 
 	case ATTR_EXPAND: 
@@ -167,16 +167,16 @@
 		break;
 
 	case ATTR_OUTLINE: 
-		outstring+=QString().sprintf(op->outline_begin); 
+		outstring+=QString().sprintf("%s", op->outline_begin); 
 		break;
 	case ATTR_SHADOW: 
-		outstring+=QString().sprintf(op->shadow_begin); 
+		outstring+=QString().sprintf("%s", op->shadow_begin); 
 		break;
 	case ATTR_EMBOSS: 
-		outstring+=QString().sprintf(op->emboss_begin); 
+		outstring+=QString().sprintf("%s", op->emboss_begin); 
 		break;
 	case ATTR_ENGRAVE: 
-		outstring+=QString().sprintf(op->engrave_begin); 
+		outstring+=QString().sprintf("%s", op->engrave_begin); 
 		break;
 
 	case ATTR_CAPS:
@@ -189,7 +189,7 @@
 			simulate_smallcaps = TRUE;
 		else {
 			if (op->small_caps_begin)
-				outstring+=QString().sprintf(op->small_caps_begin); 
+				outstring+=QString().sprintf("%s", op->small_caps_begin); 
 		}
 		break;
 	}
@@ -209,10 +209,10 @@
 	switch(attr) 
 	{
 	case ATTR_BOLD: 
-		outstring+=QString().sprintf(op->bold_end); 
+		outstring+=QString().sprintf("%s", op->bold_end); 
 		break;
 	case ATTR_ITALIC: 
-		outstring+=QString().sprintf(op->italic_end); 
+		outstring+=QString().sprintf("%s", op->italic_end); 
 		break;
 
 	/* Various underlines, they all resolve to HTML's </u> */
@@ -224,11 +224,11 @@
 	case ATTR_2DOT_DASH_UL: 
 	case ATTR_WORD_UL: 
 	case ATTR_UNDERLINE: 
-		outstring+=QString().sprintf(op->underline_end); 
+		outstring+=QString().sprintf("%s", op->underline_end); 
 		break;
 
 	case ATTR_DOUBLE_UL: 
-		outstring+=QString().sprintf(op->dbl_underline_end); 
+		outstring+=QString().sprintf("%s", op->dbl_underline_end); 
 		break;
 
 	case ATTR_FONTSIZE: 
@@ -236,47 +236,47 @@
 		break;
 
 	case ATTR_FONTFACE: 
-		outstring+=QString().sprintf(op->font_end); 
+		outstring+=QString().sprintf("%s", op->font_end); 
 		break;
 
 	case ATTR_FOREGROUND: 
-		outstring+=QString().sprintf(op->foreground_end); 
+		outstring+=QString().sprintf("%s", op->foreground_end); 
 		break;
 	case ATTR_BACKGROUND: 
 		if (!simple_mode)
-		  outstring+=QString().sprintf(op->background_end);
+		  outstring+=QString().sprintf("%s", op->background_end);
 		break;
 
 	case ATTR_SUPER: 
-		outstring+=QString().sprintf(op->superscript_end); 
+		outstring+=QString().sprintf("%s", op->superscript_end); 
 		break;
 	case ATTR_SUB: 
-		outstring+=QString().sprintf(op->subscript_end); 
+		outstring+=QString().sprintf("%s", op->subscript_end); 
 		break;
 
 	case ATTR_STRIKE: 
-		outstring+=QString().sprintf(op->strikethru_end); 
+		outstring+=QString().sprintf("%s", op->strikethru_end); 
 		break;
 
 	case ATTR_DBL_STRIKE: 
-		outstring+=QString().sprintf(op->dbl_strikethru_end); 
+		outstring+=QString().sprintf("%s", op->dbl_strikethru_end); 
 		break;
 
 	case ATTR_OUTLINE: 
-		outstring+=QString().sprintf(op->outline_end); 
+		outstring+=QString().sprintf("%s", op->outline_end); 
 		break;
 	case ATTR_SHADOW: 
-		outstring+=QString().sprintf(op->shadow_end); 
+		outstring+=QString().sprintf("%s", op->shadow_end); 
 		break;
 	case ATTR_EMBOSS: 
-		outstring+=QString().sprintf(op->emboss_end); 
+		outstring+=QString().sprintf("%s", op->emboss_end); 
 		break;
 	case ATTR_ENGRAVE: 
-		outstring+=QString().sprintf(op->engrave_end); 
+		outstring+=QString().sprintf("%s", op->engrave_end); 
 		break;
 
 	case ATTR_EXPAND: 
-		outstring+=QString().sprintf(op->expand_end); 
+		outstring+=QString().sprintf("%s", op->expand_end); 
 		break;
 
 	case ATTR_CAPS:
@@ -289,7 +289,7 @@
 			simulate_smallcaps = FALSE;
 		else {
 			if (op->small_caps_end)
-				outstring+=QString().sprintf(op->small_caps_end); 
+				outstring+=QString().sprintf("%s", op->small_caps_end); 
 		}
 		break;
 	}
