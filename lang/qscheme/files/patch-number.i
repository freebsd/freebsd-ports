--- number.i.orig	2000-06-10 01:41:00.000000000 +0300
+++ number.i	2009-03-03 17:04:01.000000000 +0200
@@ -562,7 +562,8 @@
 Prim(plus1, "1+", 1)
 {
   if (SCM_INUMP(TOS) && (SCM_INUM(TOS) < SOBJ_INUM_MAX)) {
-	(long)TOS += (1 << SOBJ_INUM_SHIFT);
+	/*(long)TOS += (1 << SOBJ_INUM_SHIFT);*/
+	TOS = (long)TOS + (long)(1 << SOBJ_INUM_SHIFT);
 	NEXT;
   }
   TOS = scm_add2(SCM_MKINUM(1), TOS);
@@ -574,7 +575,8 @@
 Prim(plus2, "2+", 1)
 {
   if (SCM_INUMP(TOS) && (SCM_INUM(TOS) < SOBJ_INUM_MAX)) {
-	(long)TOS += (2 << SOBJ_INUM_SHIFT);
+	/*(long)TOS += (2 << SOBJ_INUM_SHIFT);*/
+	TOS = (long)TOS + (long)(2 << SOBJ_INUM_SHIFT);
 	NEXT;
   }
   TOS = scm_add2(SCM_MKINUM(2), TOS);
@@ -586,7 +588,8 @@
 Prim(minus1, "1-", 1)
 {
   if (SCM_INUMP(TOS) && (SCM_INUM(TOS) > SOBJ_INUM_MIN)) {
-	(long)TOS += (-1 << SOBJ_INUM_SHIFT);
+	/*(long)TOS += (-1 << SOBJ_INUM_SHIFT);*/
+	TOS = (long)TOS + (long)(-1 << SOBJ_INUM_SHIFT);
 	NEXT;
   }
   TOS = scm_sub2(TOS, SCM_MKINUM(1));
@@ -598,7 +601,8 @@
 Prim(minus2, "2-", 1)
 {
   if (SCM_INUMP(TOS) && (SCM_INUM(TOS) > SOBJ_INUM_MIN)) {
-	(long)TOS += (-2 << SOBJ_INUM_SHIFT);
+	/*(long)TOS += (-2 << SOBJ_INUM_SHIFT);*/
+	TOS = (long)TOS + (long)(-2 << SOBJ_INUM_SHIFT);
 	NEXT;
   }
   TOS = scm_sub2(TOS, SCM_MKINUM(2));
