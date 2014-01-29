--- src/gens/segacd/cd_aspi.c.orig
+++ src/gens/segacd/cd_aspi.c
@@ -8,6 +8,8 @@
 #include "cd_aspi.h"
 #include "mem_s68k.h"
 
+#ifdef linux
+
 #define HIBYTE(x) x >> 8
 #define LOBYTE(x) x & 0xff
 void Sleep (int i);
@@ -760,3 +762,104 @@
 
   CD_Present = 0;
 }
+
+#else
+
+int CUR_DEV;
+int Num_CD_Drive;
+
+int
+ASPI_Close_Tray_CDD_cC_COMP (SRB_ExecSCSICmd * s)
+{
+	return -1;
+}
+
+int
+ASPI_End (void)
+{
+	return 1;
+}
+
+int
+ASPI_Fast_Seek_COMP (SRB_ExecSCSICmd * s)
+{
+	return 0;
+}
+
+void
+ASPI_Flush_Cache_CDC (void)
+{
+	return;
+}
+
+int
+ASPI_Init (void)
+{
+	Num_CD_Drive = 0;
+	return 0;
+}
+
+int
+ASPI_Lock (int flock)
+{
+	return 5;
+}
+
+int
+ASPI_Open_Tray_CDD_cD_COMP (SRB_ExecSCSICmd * s)
+{
+	return -1;
+}
+
+void
+ASPI_Read_One_LBA_CDC (void)
+{
+	return;
+}
+
+void
+ASPI_Reset_Drive (char *buf)
+{
+	return;
+}
+
+int
+ASPI_Seek (int pos, int async,
+           int (*PostProc) (struct tagSRB32_ExecSCSICmd *))
+{
+	return 5;
+}
+
+int
+ASPI_Seek_CDD_c4_COMP (SRB_ExecSCSICmd * s)
+{
+	return -1;
+}
+
+int
+ASPI_Star_Stop_Unit (int op,
+                     int (*PostProc) (struct tagSRB32_ExecSCSICmd *))
+{
+	return 5;
+}
+
+int
+ASPI_Stop_CDD_c1_COMP (SRB_ExecSCSICmd * s)
+{
+	return 0;
+}
+
+int
+ASPI_Stop_Play_Scan (int async,
+                     int (*PostProc) (struct tagSRB32_ExecSCSICmd *))
+{
+	return 5;
+}
+
+void
+Wait_Read_Complete (void)
+{
+	return;
+}
+
+#endif
