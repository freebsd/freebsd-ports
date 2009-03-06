http://sourceforge.net/tracker/index.php?func=detail&aid=2615264&group_id=33473&atid=408391
diff -up assembler.y.midrule assembler.y
--- assembler.y.midrule	2008-12-20 22:44:50.000000000 +0100
+++ assembler.y	2008-12-20 22:54:03.000000000 +0100
@@ -605,24 +605,24 @@ finally_opt
 
 trycatchfinally 
         : TRY name_opt                          {
-                                                    $$ = writeByte(SWFACTION_TRY);
+                                                    $<num>$ = writeByte(SWFACTION_TRY);
                                                     /* action length */
-                                                    $$ += writeShort(strlen($2)+8);
+                                                    $<num>$ += writeShort(strlen($2)+8);
                                                     /* zero flag */
-                                                    $$ += writeByte(0);
+                                                    $<num>$ += writeByte(0);
                                                     /* zero try length */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                     /* zero catch length */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                     /* zero finally length */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                     /* error variable name */
-                                                    $$ += writeString($2);
+                                                    $<num>$ += writeString($2);
                                                 }
 
-        statements_opt                          {   $$ = $<num>3 + $4; patchLength($$ - 6,  $4);    }
-        catch_opt                               {   $$ = $<num>5 + $6; patchLength($$ - 8,  $6);    }
-        finally_opt                             {   $$ = $<num>7 + $8; patchLength($$ - 10, $8);    }
+        statements_opt                          {   $<num>$ = $<num>3 + $4; patchLength($<num>$ - 6,  $4);    }
+        catch_opt                               {   $<num>$ = $<num>5 + $6; patchLength($<num>$ - 8,  $6);    }
+        finally_opt                             {   $<num>$ = $<num>7 + $8; patchLength($<num>$ - 10, $8);    }
         END                                     {
                                                     byte flag = 0;
                                                     $$ = $<num>9;
@@ -634,24 +634,24 @@ trycatchfinally 
                                                 }
 
         | TRY register                          {
-                                                    $$ = writeByte(SWFACTION_TRY);
+                                                    $<num>$ = writeByte(SWFACTION_TRY);
                                                     /* action length */
-                                                    $$ += writeShort(8);
+                                                    $<num>$ += writeShort(8);
                                                     /* zero flag */
-                                                    $$ += writeByte(0);
+                                                    $<num>$ += writeByte(0);
                                                     /* zero try length */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                     /* zero catch length */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                     /* zero finally length */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                     /* error register number */
-                                                    $$ += writeByte((byte) $2);
+                                                    $<num>$ += writeByte((byte) $2);
                                                 }
 
-        statements_opt                          {   $$ = $<num>3 + $4; patchLength($$ - 6,  $4);    }
-        catch_opt                               {   $$ = $<num>5 + $6; patchLength($$ - 8,  $6);    }
-        finally_opt                             {   $$ = $<num>7 + $8; patchLength($$ - 10, $8);    }
+        statements_opt                          {   $<num>$ = $<num>3 + $4; patchLength($<num>$ - 6,  $4);    }
+        catch_opt                               {   $<num>$ = $<num>5 + $6; patchLength($<num>$ - 8,  $6);    }
+        finally_opt                             {   $<num>$ = $<num>7 + $8; patchLength($<num>$ - 10, $8);    }
         END                                     {
                                                     byte flag = 4;
                                                     $$ = $<num>9;
@@ -707,25 +707,25 @@ name_opt
 
 function
         : FUNCTION name_opt                     {
-                                                    $$ = writeByte(SWFACTION_DEFINEFUNCTION);
+                                                    $<num>$ = writeByte(SWFACTION_DEFINEFUNCTION);
                                                     /* zero block length */
-                                                    $$ += writeShort(0);
-                                                    $$ += writeString($2);
+                                                    $<num>$ += writeShort(0);
+                                                    $<num>$ += writeString($2);
                                                 }
 
           '(' function_args ')'                 {
                                                     unsigned int i;
                                                     numArgs = $5;
 
-                                                    $$ = $<num>3 + writeShort(numArgs);
+                                                    $<num>$ = $<num>3 + writeShort(numArgs);
 
                                                     for(i = 0; i < numArgs; ++i)
-                                                        $$ += writeString(func_args[i]);
+                                                        $<num>$ += writeString(func_args[i]);
 
                                                     /* zero function length */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                     /* patch block length */
-                                                    patchLength($$-3, $$-3);
+                                                    patchLength($<num>$-3, $<num>$-3);
                                                 }
 
           statements_opt END                    {
@@ -837,25 +837,25 @@ autoregarglist
 
 function2
         : FUNCTION2 name_opt                    {
-                                                    $$ = writeByte(SWFACTION_DEFINEFUNCTION2);
+                                                    $<num>$ = writeByte(SWFACTION_DEFINEFUNCTION2);
                                                     /* zero block length */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                     /* function name */
-                                                    $$ += writeString($2);
+                                                    $<num>$ += writeString($2);
                                                     curFunc++;
                                                     memset(regfunc_args[curFunc], 0, sizeof (regfunc_args[curFunc]));
                                                     numArgs = 0;
                                                     /* zero num of function arguments */
-                                                    $$ += writeShort(numArgs);
+                                                    $<num>$ += writeShort(numArgs);
                                                     /* allocate zero registers */
                                                     numRegisters[curFunc] = 0;
-                                                    $$ += writeByte(numRegisters[curFunc]);
+                                                    $<num>$ += writeByte(numRegisters[curFunc]);
                                                     /* zero automatic register flags */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                 }
 
           '(' regarglist ')'                    {
-                                                    $$ = $<num>3 + $5;
+                                                    $<num>$ = $<num>3 + $5;
                                                     /* patch num of function arguments */
                                                     patchLength($5 + 3, numArgs);
                                                     autoregFlags = 0;
@@ -866,9 +866,9 @@ function2
                                                     byte curautoreg = 1;
                                                     unsigned int i;
 
-                                                    $$ = $<num>7;
+                                                    $<num>$ = $<num>7;
                                                     /* zero body length */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                     
                                                     /* make sure auto registers are allocated in the right order */
                                                     for (i = 0; i < MAX_AUTO_REGS; i++) {
@@ -883,9 +883,9 @@ function2
                                                     }
 
                                                     /* patch automatic register flags */
-                                                    patchLength($$ - $<num>3, autoregFlags);
+                                                    patchLength($<num>$ - $<num>3, autoregFlags);
                                                     /* patch block length */
-                                                    patchLength($$ - 3, $$ - 3);
+                                                    patchLength($<num>$ - 3, $<num>$ - 3);
                                                 }
 
           statements_opt END                    {
@@ -905,11 +905,11 @@ function2
 
 with
         : WITH                                  {
-                                                    $$ = writeByte(SWFACTION_WITH);
+                                                    $<num>$ = writeByte(SWFACTION_WITH);
                                                     /* length of with action */
-                                                    $$ += writeShort(2);
+                                                    $<num>$ += writeShort(2);
                                                     /* length of with block - will be patched */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                 }
                                                 
           statements_opt END                    { 
@@ -921,9 +921,9 @@ with
 
 settarget
         : SETTARGET STRING                      {
-                                                    $$ = writeByte(SWFACTION_SETTARGET);
-                                                    $$ += writeShort(strlen($2)+1);
-                                                    $$ += writeString($2);
+                                                    $<num>$ = writeByte(SWFACTION_SETTARGET);
+                                                    $<num>$ += writeShort(strlen($2)+1);
+                                                    $<num>$ += writeString($2);
                                                 }
 
           statements_opt END                    {
@@ -934,7 +934,7 @@ settarget
         ;
 
 settargetexpression
-        : SETTARGETEXPR                         {   $$ = writeByte(SWFACTION_SETTARGETEXPRESSION);  }
+        : SETTARGETEXPR                         {   $<num>$ = writeByte(SWFACTION_SETTARGETEXPRESSION);  }
           statements_opt END                    {
                                                     $$ = $3 + writeByte(SWFACTION_SETTARGET);
                                                     $$ += $<num>2 + writeShort(1);
@@ -946,9 +946,9 @@ ifframeloadedexpression
         : IFFRAMELOADEDEXPR                     {
                                                     if (frameloadedStart>-1)
                                                         yyerror("IfFrameLoaded actions can't be nested");
-                                                    $$ = writeByte(SWFACTION_IFFRAMELOADEDEXPRESSION);
-                                                    $$ += writeShort(1);
-                                                    $$ += writeByte(0);
+                                                    $<num>$ = writeByte(SWFACTION_IFFRAMELOADEDEXPRESSION);
+                                                    $<num>$ += writeShort(1);
+                                                    $<num>$ += writeByte(0);
                                                     frameloadedStart = numActions;
                                                 }
 
@@ -963,10 +963,10 @@ ifframeloaded
         : IFFRAMELOADED INTEGER                 {
                                                     if (frameloadedStart>-1)
                                                         yyerror("IfFrameLoaded actions can't be nested");
-                                                    $$ = writeByte(SWFACTION_IFFRAMELOADED);
-                                                    $$ += writeShort(3);
-                                                    $$ += writeShort($2);
-                                                    $$ += writeByte(0);
+                                                    $<num>$ = writeByte(SWFACTION_IFFRAMELOADED);
+                                                    $<num>$ += writeShort(3);
+                                                    $<num>$ += writeShort($2);
+                                                    $<num>$ += writeByte(0);
                                                     frameloadedStart = numActions;
                                                 }
                                          
@@ -1199,9 +1199,9 @@ opcode
           constant_list_opt                     {   $$ = writeConstants();  }
 
         | PUSH                                  {
-                                                    $$ = writeByte(SWFACTION_PUSHDATA);
+                                                    $<num>$ = writeByte(SWFACTION_PUSHDATA);
                                                     /* length */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                 }
 
           push_list                             {   
@@ -1212,10 +1212,10 @@ opcode
         | SWFACTION HEX                         {
                                                     if (xtoi($2)>0xff)
                                                         yyerror("Action code out of range");
-                                                    $$ = writeByte((char)xtoi($2));
+                                                    $<num>$ = writeByte((char)xtoi($2));
                                                     if (xtoi($2)>=0x80)
                                                     /* length */
-                                                    $$ += writeShort(0);
+                                                    $<num>$ += writeShort(0);
                                                 }
 
           hexlist_opt                           {


 	 
