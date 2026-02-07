--- cvsps.c.orig	2005-05-26 03:39:40 UTC
+++ cvsps.c
@@ -2551,8 +2551,8 @@ static void determine_branch_ancestor(PatchSet * ps, P
     for (next = ps->members.next; next != &ps->members; next = next->next) 
     {
 	PatchSetMember * psm = list_entry(next, PatchSetMember, link);
-	rev = psm->pre_rev;
 	int d1, d2;
+	rev = psm->pre_rev;
 
 	/* the reason this is at all complicated has to do with a 
 	 * branch off of a branch.  it is possible (and indeed 
