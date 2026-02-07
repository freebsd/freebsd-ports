--- memory.c.orig	2024-04-25 09:31:04 UTC
+++ memory.c
@@ -298,7 +298,7 @@ for (k=1; fgets(buffer,800,fp) ; k++)
          continue;
       }
       else if (!(rom_fp = fopen(filename,"r")))
-      {  char  err_msg[64];
+      {  char  err_msg[256];
          sprintf(err_line,ERROR_BANK,k);
          sprintf(err_msg," can't open bank file %63s", filename);
          error(0,err_line,err_msg);
@@ -311,7 +311,7 @@ for (k=1; fgets(buffer,800,fp) ; k++)
       }
       if (rom_fp)
       {  if (1U<<log2 != fread(bank[id].back_up,1,1U<<log2,rom_fp))
-         {  char  err_msg[64];
+         {  char  err_msg[256];
             sprintf(err_msg," insufficient rom %63s", filename);
             sprintf(err_line,ERROR_BANK,k);
             error(0,err_line," rom malfunction");
@@ -402,7 +402,7 @@ for (k=1; fgets(buffer,800,fp) ; k++)
       for (j=0;j<h;j++)
       {  id = strtoul(tok4+3*j,&p,16);
          if (id >= 256 || (p && *p && *p != ',') || tok4[3*j]=='-' || tok4[3*j]=='+')
-         {  char  err_msg[32];
+         {  char  err_msg[256];
             sprintf(err_line,ERROR_MAP,k);
             sprintf(err_msg," invalid %u-th bank_id: %3s",j+1,tok4+3*j);
             error(0,err_line,err_msg);
@@ -414,7 +414,7 @@ for (k=1; fgets(buffer,800,fp) ; k++)
             break;
          }
          if (!bank[id].type)
-         {  char  err_msg[32];
+         {  char  err_msg[256];
             sprintf(err_line,ERROR_MAP,k);
             sprintf(err_msg," bank_id %u not defined",id);
             error(0,err_line,err_msg);
