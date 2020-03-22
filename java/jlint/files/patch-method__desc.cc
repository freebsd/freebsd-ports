--- method_desc.cc.orig	2003-06-09 09:29:14 UTC
+++ method_desc.cc
@@ -767,7 +767,7 @@ void method_desc::parse_code(constant** constant_pool,
           sp->mask = var_desc::vs_not_null;
         }
         sp->index = NO_ASSOC_VAR;
-        sp->equals = is_const;
+        sp->equals = jlint_is_const;
         sp += 1;
       }
       break;
@@ -1906,7 +1906,7 @@ void method_desc::parse_code(constant** constant_pool,
     case dsub:
     case dmul:
     case ddiv:
-    case drem:
+    case Jdrem:
       sp -= 2;
       break;
     case ineg:
@@ -2381,7 +2381,7 @@ void method_desc::parse_code(constant** constant_pool,
             aux->name_and_type = nt;
             sp->equals = aux;
             equal_descs.push_back(aux);*/
-            sp->equals = is_const;
+            sp->equals = jlint_is_const;
           }
         }
         field->equals = sp->equals;
