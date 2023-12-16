--- lib/canna.sl.orig	1999-07-20 12:36:17 UTC
+++ lib/canna.sl
@@ -348,9 +348,10 @@ define canna_get_buf_id() {  % return -1 if cannot get
 	 message("Canna can not be used in any more buffer. Sorry...");
 	 return -1;
       }
-      create_blocal_var("canna_buf_id", 'i');
+%      create_blocal_var("canna_buf_id", 'i');
       canna_buf_number++;
-      set_blocal_var(canna_buf_number, "canna_buf_id");
+ %     set_blocal_var(canna_buf_number, "canna_buf_id");
+      define_blocal_var("canna_buf_id", canna_buf_number);
       return canna_buf_number;
    }
    return get_blocal_var("canna_buf_id");
