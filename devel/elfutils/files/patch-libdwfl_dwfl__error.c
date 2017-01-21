--- libdwfl/dwfl_error.c.orig	2016-12-25 13:36:55 UTC
+++ libdwfl/dwfl_error.c
@@ -136,7 +136,7 @@ __libdwfl_seterrno (Dwfl_Error error)
   global_error = canonicalize (error);
 }
 
-
+static __thread char strerr_buf[64];
 const char *
 dwfl_errmsg (int error)
 {
@@ -154,7 +154,9 @@ dwfl_errmsg (int error)
   switch (error &~ 0xffff)
     {
     case OTHER_ERROR (ERRNO):
-      return strerror_r (error & 0xffff, "bad", 0);
+      strcpy(strerr_buf, "bad");  
+      (void)strerror_r (error & 0xffff, strerr_buf, sizeof strerr_buf);
+      return strerr_buf;
     case OTHER_ERROR (LIBELF):
       return elf_errmsg (error & 0xffff);
     case OTHER_ERROR (LIBDW):
