--- usecode/ucxt/include/ucfunc.h.orig	Mon Sep  1 02:32:28 2003
+++ usecode/ucxt/include/ucfunc.h	Thu Jun 14 01:41:17 2007
@@ -206,7 +206,7 @@
 		bool output_list(std::ostream &o, unsigned int funcno, const UCOptions &options);
 		
 		bool output_ucs(std::ostream &o, const FuncMap &funcmap, const std::map<unsigned int, std::string> &intrinsics, const UCOptions &options);
-		std::ostream &UCFunc::output_ucs_funcname(std::ostream &o, const FuncMap &funcmap);
+		std::ostream &output_ucs_funcname(std::ostream &o, const FuncMap &funcmap);
 		std::ostream &output_ucs_funcname(std::ostream &o, const FuncMap &funcmap,
                                     unsigned int funcid,
                                     unsigned int numargs, bool return_var);
