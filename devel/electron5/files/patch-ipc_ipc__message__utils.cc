--- ipc/ipc_message_utils.cc.orig	2019-04-08 08:32:59 UTC
+++ ipc/ipc_message_utils.cc
@@ -349,7 +349,7 @@ void ParamTraits<unsigned int>::Log(const param_type& 
 }
 
 #if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_FUCHSIA) || \
-    (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
+    defined(OS_BSD) || (defined(OS_ANDROID) && defined(ARCH_CPU_64_BITS))
 void ParamTraits<long>::Log(const param_type& p, std::string* l) {
   l->append(base::NumberToString(p));
 }
