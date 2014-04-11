Index: Coleco.c
@@ -40,10 +40,10 @@
 int  CheatCount;                  /* Number of cheats                       */
 int  DiskSpeed=100;               /* Time in ms it takes to read one...     */
 int  TapeSpeed=100;               /* ... block                              */
-char *CartName   = "CART.rom";    /* Cartridge ROM file                     */
-char *OS7File    = "OS7.rom";     /* ColecoVision ROM file                  */
-char *EOSFile    = "EOS.rom";     /* EOS ROM file                           */
-char *WPFile     = "WP.rom";      /* SmartWriter ROM file                   */
+char *CartName   = "%%DATADIR%%/CART.rom";    /* Cartridge ROM file                     */
+char *OS7File    = "%%DATADIR%%/OS7.rom";     /* ColecoVision ROM file                  */
+char *EOSFile    = "%%DATADIR%%/EOS.rom";     /* EOS ROM file                           */
+char *WPFile     = "%%DATADIR%%/WP.rom";      /* SmartWriter ROM file                   */
 char *SoundName;                  /* Sound log file                         */
 char *DiskName[4];                /* Disk images                            */
 char *TapeName[4];                /* Tape images                            */
@@ -616,7 +616,7 @@
  OutE0,OutE0,OutE0,OutE0,OutE0,OutE0,OutE0,OutE0
 };
 
-void Z80_Out (unsigned Port,byte Val)
+FASTCALL void Z80_Out (unsigned Port,byte Val)
 {
  OutPortFn fn;
  Port&=0xff;
@@ -763,7 +763,7 @@
  InpE0,InpE0,InpE2,InpE2,InpE0,InpE0,InpE2,InpE2
 };
 
-byte Z80_In (unsigned Port)
+FASTCALL byte Z80_In (unsigned Port)
 {
  InPortFn fn;
  Port&=0xff;
