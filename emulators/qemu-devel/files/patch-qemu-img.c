Index: qemu/qemu-img.c
@@ -134,7 +134,7 @@
            "Command syntax:\n"
            "  create [-e] [-b base_image] [-f fmt] filename [size]\n"
            "  commit [-f fmt] filename\n"
-           "  convert [-c] [-e] [-f fmt] filename [-O output_fmt] output_filename\n"
+           "  convert [-c] [-e] [-f fmt] [-O output_fmt] filename output_filename\n"
            "  info [-f fmt] filename\n"
            "\n"
            "Command parameters:\n"
