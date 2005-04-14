--- db_dump.h.orig	Tue Oct  8 17:18:40 1996
+++ db_dump.h	Thu Apr 14 20:10:55 2005
@@ -48,7 +48,10 @@
 #define DB_FL_TRIM	0x20
 
 typedef struct dbase_head { 
-    unsigned char	version;		/* 03 for dbIII and 83 for dbIII w/memo file */
+    unsigned char	version;		/* 0x03,0x04,0x05-DBIII+/DBIV */
+						/* 0x83 - DBIII+ w/memo;*/
+						/* 0xF5-FoxPro w/memo;*/
+						/* 0x8B-DBIV w/memo file */
     unsigned char	l_update[3];		/* yymmdd for last update*/
     unsigned long	count;			/* number of records in file*/
     unsigned short	header;			/* length of the header
@@ -58,21 +61,32 @@
 						 * includes the delete
 						 * byte
 						 */
-    unsigned char   reserv[20];
+    unsigned char   reserv1[16];
+    unsigned char   excdx;                      /* 1-exist cdx file, 0 - nonexist*/
+    unsigned char   language;                   /* language driver:0x01 - 437 DOS;0x02 - 850 DOS; 0x03 - 1251; 0x00 - ignored*/
+    unsigned char   reserv2[2];
     } DBASE_HEAD;
 
-#define DB_FLD_CHAR  'C'
-#define DB_FLD_NUM   'N'
-#define DB_FLD_LOGIC 'L'
-#define DB_FLD_MEMO  'M'
-#define DB_FLD_DATE  'D'
+#define DB_FLD_CHAR     'C'
+#define DB_FLD_NUM      'N'
+#define DB_FLD_LOGIC    'L'
+#define DB_FLD_VARIABLE 'V'
+#define DB_FLD_MEMO     'M'
+#define DB_FLD_FLOAT    'F'
+#define DB_FLD_PICTURE  'P'
+#define DB_FLD_BINARY   'B'
+#define DB_FLD_GENERAL  'G'
+#define DB_FLD_SHINT    '2'
+#define DB_FLD_LINT     '4'
+#define DB_FLD_DOUBLE   '8'
+#define DB_FLD_DATE     'D'
  
 typedef struct dbase_fld {
     char    name[11];                                           /*field name*/
     char    type;                                               /*field type*/
     /* A-T uses large data model but drop it for now */
     char   *data_ptr;                         /*pointer into buffer*/
-    char   length;                                   /*field length*/
+    unsigned char   length;                   /*field length*/
     char   dec_point;                         /*field decimal point*/
     char   fill[14];
     } DBASE_FIELD;
