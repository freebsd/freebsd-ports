--- src/GridText.c.orig	2010-04-26 08:44:30.000000000 +0900
+++ src/GridText.c	2010-05-24 18:15:47.000000000 +0900
@@ -11128,9 +11128,28 @@
 		if (check_form_specialchars(val_used) != 0) {
 		    /*  We should translate back. */
 		    StrAllocCopy(copied_val_used, val_used);
+		    if (HTCJK == JAPANESE) {
+			if ((0 <= target_cs) &&
+			    (strcmp(LYCharSet_UC[target_cs].MIMEname, "euc-jp") == 0)) {
+			    TO_EUC(val_used, copied_val_used);
+			    success = YES;
+			}
+			else if ((0 <= target_cs) &&
+			    (strcmp(LYCharSet_UC[target_cs].MIMEname, "shift_jis") == 0)) {
+			    TO_SJIS(val_used, copied_val_used);
+			    success = YES;
+			}
+			else {
 		    success = LYUCTranslateBackFormData(&copied_val_used,
 							form_ptr->value_cs,
 							target_cs, PlainText);
+			}
+		    }
+		    else {
+			success = LYUCTranslateBackFormData(&copied_val_used,
+							    form_ptr->value_cs,
+							    target_cs, PlainText);
+		    }
 		    CTRACE((tfp, "field \"%s\" %d %s -> %d %s %s\n",
 			    NonNull(form_ptr->name),
 			    form_ptr->value_cs,
