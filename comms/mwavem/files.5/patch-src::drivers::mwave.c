
$FreeBSD$

--- src/drivers/mwave.c	2002/12/11 00:20:13	1.1
+++ src/drivers/mwave.c	2002/12/11 00:22:11
@@ -236,7 +236,6 @@
 
       pDrvData->IPCs[ipcnum].bIsHere=FALSE;
       pDrvData->IPCs[ipcnum].bIsEnabled=TRUE;
-      current->p_nice=-16; /* boost to provide priority timing */
       
       PRINTK_2(TRACE_MWAVE,"mwave::mwave_ioctl IOCTL_MW_REGISTER_IPC ipcnum %x exit\n",ipcnum);
     }
