Obtained from [ruby-dev:21263]

Index: regparse.c
===================================================================
--- regparse.c	(revision 217)
+++ regparse.c	(working copy)
@@ -3571,7 +3571,10 @@
       in_israw = 1;
     val_entry:
       len = WC2MBLEN(env->enc, v);
-      if (len < 0) return len;
+      if (len < 0) {
+	r = len;
+	goto err;
+      }
       in_type = (len == 1 ? CCV_SB : CCV_WC);
       r = next_state_val(cc, &vs, v, &val_israw, in_israw, in_type, &val_type,
 			 &state, env);
@@ -3658,8 +3661,8 @@
 	acc = &(NCCLASS(anode));
 	r = or_cclass(cc, acc);
 
+	regex_node_free(anode);
       cc_open_err:
-	regex_node_free(anode);
 	if (r != 0) goto err;
       }
       break;

