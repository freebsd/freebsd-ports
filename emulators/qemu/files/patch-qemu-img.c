Index: qemu/qemu-img.c
@@ -90,7 +90,7 @@
            "Command syntax:\n"
            "  create [-e] [-6] [-b base_image] [-f fmt] filename [size]\n"
            "  commit [-f fmt] filename\n"
-           "  convert [-c] [-e] [-6] [-f fmt] filename [filename2 [...]] [-O output_fmt] output_filename\n"
+           "  convert [-c] [-e] [-6] [-f fmt] [-O output_fmt] filename [filename2 [...]] output_filename\n"
            "  info [-f fmt] filename\n"
            "\n"
            "Command parameters:\n"
