--- generator/cpu68k.c.orig	2007-12-04 16:57:08 UTC
+++ generator/cpu68k.c
@@ -259,7 +259,7 @@ int cpu68k_init(void)
             continue;
           }
         }
-        if (cpu68k_iibtable[bitmap] != NULL) {EXIT(283,0,"CPU definition #%d conflicts (0x%x)", i, bitmap);}
+        if (cpu68k_iibtable[bitmap] != NULL) {EXITR(283,0,"CPU definition #%d conflicts (0x%x)", i, bitmap);}
 
         cpu68k_iibtable[bitmap] = iib;
         /* set both flag and non-flag versions */
@@ -285,7 +285,7 @@ int cpu68k_init(void)
 
   if (j != cpu68k_totalinstr) 
     {
-      EXIT(84,0,"Instruction count not verified (%d/%d)\n",
+      EXITR(84,0,"Instruction count not verified (%d/%d)\n",
                   cpu68k_totalinstr, i);
     }
 
@@ -904,19 +904,19 @@ t_ipc_table *get_ipct(void)
 	else /*---- Nope! We're out of IPCt's, allocate some more.  ----*/
 	{
 
-        if ( ipcts_free) { EXIT(3,0,"Bug! ipcts_free is %ld, but ipct_free_head is null",ipcts_free);}
+        if ( ipcts_free) { EXITR(3,0,"Bug! ipcts_free is %ld, but ipct_free_head is null",ipcts_free);}
 
         //check_iib();
 
         /*--- Did we call Malloc too many times? ---*/
-        if ((iipct_mallocs++)>MAX_IPCT_MALLOCS) { EXIT(2,0,"Excessive mallocs of ipct's recompile with more!");}
+        if ((iipct_mallocs++)>MAX_IPCT_MALLOCS) { EXITR(2,0,"Excessive mallocs of ipct's recompile with more!");}
 
 		size_to_get = (ipcts_allocated/IPCT_ALLOC_PERCENT)+1; // add a percentange of what we have, least 1
 		if ( (ipct_mallocs[iipct_mallocs]=(t_ipc_table *)malloc(size_to_get * sizeof(t_ipc_table)+1)  )==NULL)
 		{
             DEBUG_LOG(0,"Out of memory getting more ipcs: %p was returned",  ipct_mallocs[iipct_mallocs]);
             DEBUG_LOG(0,"%d ipcts allocated so far, %d are free, %d used, %d mallocs done", ipcts_allocated, ipcts_free, ipcts_used, iipct_mallocs);
-            EXIT(86,0,"Out of memory while allocating more ipct's");
+            EXITR(86,0,"Out of memory while allocating more ipct's");
 		}
 
 //        DEBUG_LOG(0,"zzzzzzz ipct land allocated:: %p -to- %p", ipct_mallocs[iipct_mallocs], (void *)(ipct_mallocs[iipct_mallocs]+size_to_get * sizeof(t_ipc_table)));
@@ -1084,8 +1084,8 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
         DEBUG_LOG(1000,"Nope - calling get_ipct()");
 		mmu_trn->table=get_ipct(); // allocate an ipc table for this mmu_t
         table=mmu_trn->table;
-        if (!table) {EXIT(21,0,"Couldn't get IPC Table! Doh!");}
-        if (pc&1) {EXIT(14,0,"odd pc!");}
+        if (!table) {EXITR(21,0,"Couldn't get IPC Table! Doh!");}
+        if (pc&1) {EXITR(14,0,"odd pc!");}
 
         //check_iib();
 
@@ -1094,11 +1094,11 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
 			// ipc points to the MMU translation table entry for this page.
             ipc = &(table->ipc[((pc>>1) & 0xff)]);
             DEBUG_LOG(200,"ipc is now %p at pc %06x max %06x",ipc,pc,xpc);
-            if (!ipc) {EXIT(501,0,"cpu68k_makeipclist: But! ipc is null!"); }
-            if (pc&1) {EXIT(501,0,"odd pc!");}
+            if (!ipc) {EXITR(501,0,"cpu68k_makeipclist: But! ipc is null!"); }
+            if (pc&1) {EXITR(501,0,"odd pc!");}
 		}
         else
-        {EXIT(502,0,"Let the bodies hit the floor!\nLet the bodies hit the floor!\nLet the bodies hit the floor!\n\n  Either mmu_trn or table is null!");}
+        {EXITR(502,0,"Let the bodies hit the floor!\nLet the bodies hit the floor!\nLet the bodies hit the floor!\n\n  Either mmu_trn or table is null!");}
 	}
 
     //check_iib();
@@ -1106,7 +1106,7 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
 
         if ( !ipc)
                 {
-                    EXIT(17,0,"ipc=NULL\n1. Something's got to give 2. Something's got to give. 3. Something's got to give 4. Something's got to give.\nNOW!");
+                    EXITR(17,0,"ipc=NULL\n1. Something's got to give 2. Something's got to give. 3. Something's got to give 4. Something's got to give.\nNOW!");
                 }
 
     //check_iib();
@@ -1126,7 +1126,7 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
 
     if ( !ipc)
                 {
-                    EXIT(20,0,"ipc=NULL\n1. Something's got to give 2. Something's got to give. 3. Something's got to give 4. Something's got to give.\nNOW!");
+                    EXITR(20,0,"ipc=NULL\n1. Something's got to give 2. Something's got to give. 3. Something's got to give 4. Something's got to give.\nNOW!");
                 }
 
     //check_iib();
@@ -1236,8 +1236,8 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
         // fflush(buglog);
         // #endif
 
-        if (!iib) {EXIT(53,0,"There's no proper IIB for the possibly illegal instruction opcode %04x @ pc=%08x\n",opcode,pc);}
-        if ( !ipc)  {EXIT(54,0,"Have a cow man! ipc=NULL\n"); }
+        if (!iib) {EXITR(53,0,"There's no proper IIB for the possibly illegal instruction opcode %04x @ pc=%08x\n",opcode,pc);}
+        if ( !ipc)  {EXITR(54,0,"Have a cow man! ipc=NULL\n"); }
 
         //DEBUG_LOG(200,"ipc is %s",(!ipc)?"null":"ok");
 
@@ -1283,7 +1283,7 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
 		// grow the list of ipcs if we need to.
 		if (instrs>=ipcs_to_get)
 		{
-            EXIT(24,0,"Welcome to the realms of chaos! I'm dealing with over %d instructions, %d ipcs! %d/%d/%d pc=%d/%08x",instrs,ipcs_to_get,segment1,segment2,start,context,pc);
+            EXITR(24,0,"Welcome to the realms of chaos! I'm dealing with over %d instructions, %d ipcs! %d/%d/%d pc=%d/%08x",instrs,ipcs_to_get,segment1,segment2,start,context,pc);
             pc24=pc;
 		}
 
@@ -1308,7 +1308,7 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
               table=mmu_trn->table;
 
               if (!table) {
-                           EXIT(99,0,"Couldnt get IPC Table! Doh!\n");}
+                           EXITR(99,0,"Couldnt get IPC Table! Doh!\n");}
 
               //if (pc&1) {DEBUG_LOG(200,"odd pc!"); EXIT(26);}
             }
@@ -1333,7 +1333,7 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
 
                  // check_iib();
 
-                  if (!table) {EXIT(27,0,"Couldnt get IPC Table! Doh!");}
+                  if (!table) {EXITR(27,0,"Couldnt get IPC Table! Doh!");}
                   //ipc = &(mmu_trn->table->ipc[((pc>>1) & 0xff)]);
                   //myiib=cpu68k_iibtable[opcode]; iib=myiib; // iib =  myiib ? myiib : illegaliib;
                   //////cpu68k_ipc(pc, iib, ipc);
@@ -1370,7 +1370,7 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
     if (instrs == 2)
     {
 
-        if (pc&1) {EXIT(28,0,"odd pc!");}
+        if (pc&1) {EXITR(28,0,"odd pc!");}
         DEBUG_LOG(200,"*~*~*~*~*~*~ in 2instrs ipc is now %p at pc %06x max %06x",ipc,pc,xpc);
         ipc=ipcs[instrs-1-1]; //ipc--
         DEBUG_LOG(200,"ipc is now %p at pc %06x max %06x",ipc,pc,xpc);
@@ -1443,7 +1443,7 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
         DEBUG_LOG(200,"ipc is now %p at pc %06x max %06x ix=%d",ipc,pc,xpc,ix);
         if ( !ipc)
         {
-            EXIT(29,0,"Null ipc, bye");
+            EXITR(29,0,"Null ipc, bye");
         }
 
         //check_iib();
@@ -1460,7 +1460,7 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
 
         if (!ipc->function)
              {
-              EXIT(3,0,"Null IPC fn returned for opcode:%04x ix=%d of %d instrs",ipc->opcode,ix,instrs);
+              EXITR(3,0,"Null IPC fn returned for opcode:%04x ix=%d of %d instrs",ipc->opcode,ix,instrs);
               // cpu68k_printipc(ipc);
              }
 
@@ -1479,7 +1479,7 @@ t_ipc_table *cpu68k_makeipclist(uint32 p
 		{
           //  check_iib();
             ipc=ipcs[ix];
-            EXIT(6,0,"FATAL ipc with null fnction at index %d-> used:%d, set:%d, opcode %04x, len %02x, src %08x, dst %08x\n",
+            EXITR(6,0,"FATAL ipc with null fnction at index %d-> used:%d, set:%d, opcode %04x, len %02x, src %08x, dst %08x\n",
                 ix, ipc->used, ipc->set, ipc->opcode, ipc->wordlen, ipc->src, ipc->dst);
 		}
 
