--- freehdl/kernel-sig-info.hh.orig	2013-02-25 17:49:33.000000000 +0000
+++ freehdl/kernel-sig-info.hh
@@ -164,10 +164,6 @@ template<class T>class sig_info : public
 	   type_info_interface *type, char attr, sig_info_base *base_sig,
 	   acl *aclp, vtime delay, void *sr) :
     sig_info_base(iname, n, sln, type, attr, base_sig, aclp, delay, sr) {};
-  /* Constructor to instantiate a guard signal */
-  sig_info(name_stack &iname, const char *n, const char *sln,
-	   void *reader, void *sr) : 
-    sig_info_base(iname, n, sln, reader, sr) {};
   /* Constructor to instantiate an alias signal */
   sig_info(name_stack &iname, const char *n, const char *sln,
 	   type_info_interface *ty, sig_info_base *aliased_sig,
