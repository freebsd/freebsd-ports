$FreeBSD$

--- ../../hotspot1.3.1/src/share/vm/runtime/javaCalls.cpp	5 Jun 2002 05:27:48 -0000	1.2
+++ ../../hotspot1.3.1/src/share/vm/runtime/javaCalls.cpp	27 Jul 2003 10:43:28 -0000	1.3
@@ -344,36 +344,6 @@
   { JavaCallWrapper link(method, receiver, result, CHECK);  
     { HandleMark hm(thread);
 
-#if 0
-fprintf(stderr, "
-StubRoutines::call_stub:
-	link				= 0x%08x,
-	result_val_address		= 0x%08x,
-	result_type			= 0x%08x,
-	entry_point			= 0x%08x,
-	method				= 0x%08x,",
-//	args->parameters()		= 0x%08x,
-//	args->size_of_parameters()	= 0x%08x\n",
-		(address)&link,
-		result_val_address,
-		result_type,
-		entry_point,
-		method()
-//		args->parameters(),
-//		args->size_of_parameters()
-		);
-
-#if 0
-fprintf(stderr, "
-	address		= %d,
-	BasicType	= %d,
-	jint*		= %d\n",
-		sizeof(address),
-		sizeof(BasicType),
-		sizeof(jint*)
-		);
-#endif
-#endif
 
       StubRoutines::call_stub()(
         (address)&link,        
