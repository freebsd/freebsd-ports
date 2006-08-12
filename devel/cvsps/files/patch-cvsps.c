--- cvsps.c.orig	Wed Aug  9 21:59:54 2006
+++ cvsps.c	Wed Aug  9 22:00:17 2006
@@ -2551,8 +2551,8 @@
     for (next = ps->members.next; next != &ps->members; next = next->next) 
     {
 	PatchSetMember * psm = list_entry(next, PatchSetMember, link);
-	rev = psm->pre_rev;
 	int d1, d2;
+	rev = psm->pre_rev;
 
 	/* the reason this is at all complicated has to do with a 
 	 * branch off of a branch.  it is possible (and indeed 
