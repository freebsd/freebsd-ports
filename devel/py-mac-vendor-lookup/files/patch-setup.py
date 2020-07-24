--- setup.py.orig	2020-04-28 20:12:37 UTC
+++ setup.py
@@ -171,7 +171,6 @@ setup(
     #
     # In this case, 'data_file' will be installed into '<sys.prefix>/my_data'
     data_files=[
-        ("cache", ["mac-vendors.txt"]),
     ],  # Optional
 
     # To provide executable scripts, use entry points in preference to the
