--- modules/src/frbinmodule/mpeg3driver.cpp.orig	2007-04-29 23:53:40.000000000 +0900
+++ modules/src/frbinmodule/mpeg3driver.cpp	2008-08-08 22:32:25.000000000 +0900
@@ -82,7 +82,9 @@
 
   if(mpeg3_check_sig(const_cast<char*>(m_impl->file_name.c_str()))==1)
     {
-      m_impl->file=mpeg3_open(const_cast<char*>(m_impl->file_name.c_str()));
+      int retcode = 0;
+
+      m_impl->file=mpeg3_open(const_cast<char*>(m_impl->file_name.c_str()), &retcode);
 	  
       try
         {
