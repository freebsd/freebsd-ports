--- lefty/exec.c.orig	Wed Apr 17 16:28:33 2002
+++ lefty/exec.c	Wed Apr 17 16:33:21 2002
@@ -261,6 +261,8 @@
             return (boolop (v1o) == FALSE) ? Tfalse: Ttrue;
         case C_NOT:
             return (boolop (v1o) == TRUE) ? Tfalse: Ttrue;
+	default:
+	    break;
         }
         /* NOT REACHED */
         return Tfalse;
@@ -646,7 +648,7 @@
 }
 
 static Tobj getval (Tobj co, int ci) {
-    Tobj cvo, cko, cto;
+    Tobj cvo = 0, cko = 0, cto = 0;
     Ctype_t ct, vt;
     int vi, ni, nn = 0;
 
@@ -687,10 +689,10 @@
 }
 
 static int getvar (Tobj co, int ci, tnk_t *tnkp) {
-    Tobj cvo, cko, cto;
-    Ctype_t ct, vt;
+    Tobj cvo = 0, cko = 0, cto = 0;
+    Ctype_t ct, vt = 0;
     long m;
-    int vi, ovi, nn, ni;
+    int vi, ovi, nn = 0, ni;
 
     if ((ct = TCgettype (co, ci)) == C_LVAR) {
         nn = (int) TCgetinteger (co, (ni = TCgetnext (co, TCgetfp (co, ci))));
@@ -780,6 +782,8 @@
         case C_REAL:
             Tinsr (tnk.u.tnks.to, TCgetreal (tnk.u.tnks.co, tnk.u.tnks.vi), vo);
             break;
+        default:
+            break;
         }
         break;
     }
@@ -848,6 +852,7 @@
     case C_LE: return (r <= 0) ? TRUE : FALSE;
     case C_GT: return (r >  0) ? TRUE : FALSE;
     case C_GE: return (r >= 0) ? TRUE : FALSE;
+    default: break;
     }
     panic (POS, "orderop", "bad op code");
     return FALSE; /* NOT REACHED */
@@ -892,6 +897,7 @@
     case C_MUL:   d3 = d1 * d2;               break;
     case C_DIV:   d3 = d1 / d2;               break;
     case C_MOD:   d3 = (long) d1 % (long) d2; break;
+    default: break;
     }
 result:
     if (d3 == (double) (long) d3)
