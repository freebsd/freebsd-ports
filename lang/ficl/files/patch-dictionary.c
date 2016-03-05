--- dictionary.c.orig	2010-09-12 15:14:52 UTC
+++ dictionary.c
@@ -662,7 +662,7 @@ void ficlDictionarySee(ficlDictionary *d
             *trace++ = '>';
         else
             *trace++ = ' ';
-        trace += sprintf(trace, "%3d   ", cell - param0);
+        trace += sprintf(trace, "%3ld   ", (long)(cell - param0));
         
         if (ficlDictionaryIsAWord(dictionary, word))
         {
@@ -676,7 +676,7 @@ void ficlDictionarySee(ficlDictionary *d
                 break;
             case FICL_WORDKIND_INSTRUCTION_WITH_ARGUMENT:
                 c = *++cell;
-                sprintf(trace, "%s (instruction %ld), with argument %ld (%#lx)", ficlDictionaryInstructionNames[(long)word], (long)word, c.i, c.u);
+                sprintf(trace, "%s (instruction %ld), with argument %ld (%#lx)", ficlDictionaryInstructionNames[(long)word], (long)word, (long)c.i, (long unsigned)c.u);
                 break;
             case FICL_WORDKIND_INSTRUCTION_WORD:
                 sprintf(trace, "%s :: executes %s (instruction word %ld)", word->name, ficlDictionaryInstructionNames[(long)word->code], (long)word->code);
@@ -687,20 +687,20 @@ void ficlDictionarySee(ficlDictionary *d
                 {
                     ficlWord *word = (ficlWord *)c.p;
                     sprintf(trace, "%.*s ( %#lx literal )", 
-                        word->length, word->name, c.u);
+                        word->length, word->name, (long unsigned)c.u);
                 }
                 else
-                    sprintf(trace, "literal %ld (%#lx)", c.i, c.u);
+                    sprintf(trace, "literal %ld (%#lx)", (long)c.i, (long unsigned)c.u);
                 break;
             case FICL_WORDKIND_2LITERAL:
                 c = *++cell;
                 c2 = *++cell;
-                sprintf(trace, "2literal %d %d (%#lx %#lx)", c2.i, c.i, c2.u, c.u);
+                sprintf(trace, "2literal %ld %ld (%#lx %#lx)", (long)c2.i, (long)c.i, (long unsigned)c2.u, (long unsigned)c.u);
                 break;
 #if FICL_WANT_FLOAT
             case FICL_WORDKIND_FLITERAL:
                 c = *++cell;
-                sprintf(trace, "fliteral %f (%#lx)", c.f, c.u);
+                sprintf(trace, "fliteral %f (%#lx)", (double)c.f, (long unsigned)c.u);
                 break;
 #endif /* FICL_WANT_FLOAT */
             case FICL_WORDKIND_STRING_LITERAL:
@@ -719,32 +719,32 @@ void ficlDictionarySee(ficlDictionary *d
                 break;
             case FICL_WORDKIND_BRANCH0:
                 c = *++cell;
-                sprintf(trace, "branch0 %d", cell + c.i - param0);
+                sprintf(trace, "branch0 %ld", (long)(cell + c.i - param0));
                 break;                                                           
             case FICL_WORDKIND_BRANCH:
                 c = *++cell;
-                sprintf(trace, "branch %d",     cell + c.i - param0);
+                sprintf(trace, "branch %ld", (long)(cell + c.i - param0));
                 break;
 
             case FICL_WORDKIND_QDO:
                 c = *++cell;
-                sprintf(trace, "?do (leave %d)",  (ficlCell *)c.p - param0);
+                sprintf(trace, "?do (leave %ld)", (long)((ficlCell *)c.p - param0));
                 break;
             case FICL_WORDKIND_DO:
                 c = *++cell;
-                sprintf(trace, "do (leave %d)", (ficlCell *)c.p - param0);
+                sprintf(trace, "do (leave %ld)", (long)((ficlCell *)c.p - param0));
                 break;
             case FICL_WORDKIND_LOOP:
                 c = *++cell;
-                sprintf(trace, "loop (branch %d)", cell + c.i - param0);
+                sprintf(trace, "loop (branch %ld)", (long)(cell + c.i - param0));
                 break;
             case FICL_WORDKIND_OF:
                 c = *++cell;
-                sprintf(trace, "of (branch %d)",      cell + c.i - param0);
+                sprintf(trace, "of (branch %ld)", (long)(cell + c.i - param0));
                 break;
             case FICL_WORDKIND_PLOOP:
                 c = *++cell;
-                sprintf(trace, "+loop (branch %d)", cell + c.i - param0);
+                sprintf(trace, "+loop (branch %ld)", (long)(cell + c.i - param0));
                 break;
             default:
                 sprintf(trace, "%.*s", word->length, word->name);
@@ -754,7 +754,7 @@ void ficlDictionarySee(ficlDictionary *d
         }
         else /* probably not a word - punt and print value */
         {
-            sprintf(trace, "%ld ( %#lx )", cell->i, cell->u);
+            sprintf(trace, "%ld ( %#lx )", (long)cell->i, (long unsigned)cell->u);
         }
 
         ficlCallbackTextOut(callback, buffer);
