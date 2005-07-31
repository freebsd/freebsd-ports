--- cvsps.c.orig	Sun Jul 31 13:23:28 2005
+++ cvsps.c	Sun Jul 31 13:23:36 2005
@@ -2550,9 +2550,9 @@
 
     for (next = ps->members.next; next != &ps->members; next = next->next) 
     {
+	int d1, d2;
 	PatchSetMember * psm = list_entry(next, PatchSetMember, link);
 	rev = psm->pre_rev;
-	int d1, d2;
 
 	/* the reason this is at all complicated has to do with a 
 	 * branch off of a branch.  it is possible (and indeed 
