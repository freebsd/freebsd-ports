Index: src/tarhelper.cpp
@@ -244,7 +244,8 @@
     retval = false;
   else
     {
-      if (strcmp(header.magic, "ustar  ") != 0)
+      if (strcmp(header.magic, "ustar  ") != 0 &&	/* GNU tar format */
+			  strcmp(header.magic, "ustar") != 0)	/* POSIX tar format */
         retval = false;
     }
   fclose (f);
