--- lib/canna.sl~	Sat Aug 14 13:03:12 1999
+++ lib/canna.sl	Sat Aug 14 13:02:35 1999
@@ -348,9 +348,10 @@
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


