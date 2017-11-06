Fix potential crashes found by ASan/Clang/GCC

--- openbor.c.orig	2011-09-28 01:05:05 UTC
+++ openbor.c
@@ -8843,7 +8843,7 @@ char* llHandleCommandSpawnscript(ArgList
 
 
 void load_level(char *filename){
-	char *buf;
+	char *buf = NULL;
 	size_t size, len;
 	ptrdiff_t pos, oldpos;
 	char *command;
@@ -9820,6 +9820,7 @@ void bar(int x, int y, int value, int ma
 	else if(pstatus->orientation==verticalbar) max = pstatus->sizey;
 	else return;
 
+	if (value < 0) value = 0;
 	if (value > maxvalue) value = maxvalue;
 
 	if(pstatus->type==valuebar)
@@ -12884,7 +12885,7 @@ void common_dot()
 	entity*     eOpp;       //Owner of dot effect.
 	s_attack    attack;     //Attack struct.
 
-	for(iIndex=0; iIndex<=MAX_DOTS; iIndex++)                                                   //Loop through all DOT indexes.
+	for(iIndex=0; iIndex<MAX_DOTS; iIndex++)                                                   //Loop through all DOT indexes.
 	{
 		iDot_time   =   self->dot_time[iIndex];                                                 //Get expire time.
 		iDot_cnt    =   self->dot_cnt[iIndex];                                                  //Get next tick time.
