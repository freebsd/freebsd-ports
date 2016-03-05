--- vm.c.orig	2010-09-13 18:43:04 UTC
+++ vm.c
@@ -280,12 +280,12 @@ void ficlVmInnerLoop(ficlVm *vm, ficlWor
 	if (once)
 		count = 1;
 
-	LOCAL_VARIABLE_REFILL;
-
     oldExceptionHandler = vm->exceptionHandler;
     vm->exceptionHandler = &exceptionHandler; /* This has to come before the setjmp! */
     except = setjmp(exceptionHandler);
 
+	LOCAL_VARIABLE_REFILL;
+
 	if (except)
 		{
 		LOCAL_VARIABLE_SPILL;
@@ -717,8 +717,8 @@ AGAIN:
 				i = dataTop->i;
 				if (i < 0)
 					continue;
-				CHECK_STACK(i + 1, i + 2);
-				*dataTop = dataTop[-i];
+				CHECK_STACK(i + 2, i + 3);
+				*dataTop = dataTop[-i - 1];
 				continue;
 			}
 
@@ -1228,7 +1228,7 @@ COMPARE:
 			**************************************************************************/
 			case ficlInstructionRandom:
 			{
-				(++dataTop)->i = rand();
+				(++dataTop)->u = random();
 				continue;
 			}
 
@@ -1239,7 +1239,7 @@ COMPARE:
 			**************************************************************************/
 			case ficlInstructionSeedRandom:
 			{
-				srand((dataTop--)->i);
+				srandom((dataTop--)->u);
 				continue;
 			}
 
