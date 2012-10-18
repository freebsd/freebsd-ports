--- usrp/firmware/include/fx2regs.h.orig	2012-10-03 18:13:13.000000000 -0500
+++ usrp/firmware/include/fx2regs.h	2012-10-03 19:22:39.000000000 -0500
@@ -63,172 +63,176 @@
 
 #ifdef ALLOCATE_EXTERN
 #define EXTERN
-#define _AT_(a) at a
+#define _AT_(a) __at a
 #else
 #define EXTERN extern
 #define _AT_ ;/ ## /
 #endif
+//#define xdata __xdata
+#define sfr __sfr
+#define at __at
+#define sbit __sbit
 
 typedef unsigned char BYTE;
 typedef unsigned short WORD;
 
-EXTERN xdata _AT_(0xE400) volatile BYTE GPIF_WAVE_DATA[128];
-EXTERN xdata _AT_(0xE480) volatile BYTE RES_WAVEDATA_END  ;
+EXTERN __xdata _AT_(0xE400) volatile BYTE GPIF_WAVE_DATA[128];
+EXTERN __xdata _AT_(0xE480) volatile BYTE RES_WAVEDATA_END  ;
 
 // General Configuration
 
-EXTERN xdata _AT_(0xE600) volatile BYTE CPUCS             ;  // Control & Status
-EXTERN xdata _AT_(0xE601) volatile BYTE IFCONFIG          ;  // Interface Configuration
-EXTERN xdata _AT_(0xE602) volatile BYTE PINFLAGSAB        ;  // FIFO FLAGA and FLAGB Assignments
-EXTERN xdata _AT_(0xE603) volatile BYTE PINFLAGSCD        ;  // FIFO FLAGC and FLAGD Assignments
-EXTERN xdata _AT_(0xE604) volatile BYTE FIFORESET         ;  // Restore FIFOS to default state
-EXTERN xdata _AT_(0xE605) volatile BYTE BREAKPT           ;  // Breakpoint
-EXTERN xdata _AT_(0xE606) volatile BYTE BPADDRH           ;  // Breakpoint Address H
-EXTERN xdata _AT_(0xE607) volatile BYTE BPADDRL           ;  // Breakpoint Address L
-EXTERN xdata _AT_(0xE608) volatile BYTE UART230           ;  // 230 Kbaud clock for T0,T1,T2
-EXTERN xdata _AT_(0xE609) volatile BYTE FIFOPINPOLAR      ;  // FIFO polarities
-EXTERN xdata _AT_(0xE60A) volatile BYTE REVID             ;  // Chip Revision
-EXTERN xdata _AT_(0xE60B) volatile BYTE REVCTL            ;  // Chip Revision Control
+EXTERN __xdata _AT_(0xE600) volatile BYTE CPUCS             ;  // Control & Status
+EXTERN __xdata _AT_(0xE601) volatile BYTE IFCONFIG          ;  // Interface Configuration
+EXTERN __xdata _AT_(0xE602) volatile BYTE PINFLAGSAB        ;  // FIFO FLAGA and FLAGB Assignments
+EXTERN __xdata _AT_(0xE603) volatile BYTE PINFLAGSCD        ;  // FIFO FLAGC and FLAGD Assignments
+EXTERN __xdata _AT_(0xE604) volatile BYTE FIFORESET         ;  // Restore FIFOS to default state
+EXTERN __xdata _AT_(0xE605) volatile BYTE BREAKPT           ;  // Breakpoint
+EXTERN __xdata _AT_(0xE606) volatile BYTE BPADDRH           ;  // Breakpoint Address H
+EXTERN __xdata _AT_(0xE607) volatile BYTE BPADDRL           ;  // Breakpoint Address L
+EXTERN __xdata _AT_(0xE608) volatile BYTE UART230           ;  // 230 Kbaud clock for T0,T1,T2
+EXTERN __xdata _AT_(0xE609) volatile BYTE FIFOPINPOLAR      ;  // FIFO polarities
+EXTERN __xdata _AT_(0xE60A) volatile BYTE REVID             ;  // Chip Revision
+EXTERN __xdata _AT_(0xE60B) volatile BYTE REVCTL            ;  // Chip Revision Control
 
 // Endpoint Configuration
 
-EXTERN xdata _AT_(0xE610) volatile BYTE EP1OUTCFG         ;  // Endpoint 1-OUT Configuration
-EXTERN xdata _AT_(0xE611) volatile BYTE EP1INCFG          ;  // Endpoint 1-IN Configuration
-EXTERN xdata _AT_(0xE612) volatile BYTE EP2CFG            ;  // Endpoint 2 Configuration
-EXTERN xdata _AT_(0xE613) volatile BYTE EP4CFG            ;  // Endpoint 4 Configuration
-EXTERN xdata _AT_(0xE614) volatile BYTE EP6CFG            ;  // Endpoint 6 Configuration
-EXTERN xdata _AT_(0xE615) volatile BYTE EP8CFG            ;  // Endpoint 8 Configuration
-EXTERN xdata _AT_(0xE618) volatile BYTE EP2FIFOCFG        ;  // Endpoint 2 FIFO configuration
-EXTERN xdata _AT_(0xE619) volatile BYTE EP4FIFOCFG        ;  // Endpoint 4 FIFO configuration
-EXTERN xdata _AT_(0xE61A) volatile BYTE EP6FIFOCFG        ;  // Endpoint 6 FIFO configuration
-EXTERN xdata _AT_(0xE61B) volatile BYTE EP8FIFOCFG        ;  // Endpoint 8 FIFO configuration
-EXTERN xdata _AT_(0xE620) volatile BYTE EP2AUTOINLENH     ;  // Endpoint 2 Packet Length H (IN only)
-EXTERN xdata _AT_(0xE621) volatile BYTE EP2AUTOINLENL     ;  // Endpoint 2 Packet Length L (IN only)
-EXTERN xdata _AT_(0xE622) volatile BYTE EP4AUTOINLENH     ;  // Endpoint 4 Packet Length H (IN only)
-EXTERN xdata _AT_(0xE623) volatile BYTE EP4AUTOINLENL     ;  // Endpoint 4 Packet Length L (IN only)
-EXTERN xdata _AT_(0xE624) volatile BYTE EP6AUTOINLENH     ;  // Endpoint 6 Packet Length H (IN only)
-EXTERN xdata _AT_(0xE625) volatile BYTE EP6AUTOINLENL     ;  // Endpoint 6 Packet Length L (IN only)
-EXTERN xdata _AT_(0xE626) volatile BYTE EP8AUTOINLENH     ;  // Endpoint 8 Packet Length H (IN only)
-EXTERN xdata _AT_(0xE627) volatile BYTE EP8AUTOINLENL     ;  // Endpoint 8 Packet Length L (IN only)
-EXTERN xdata _AT_(0xE630) volatile BYTE EP2FIFOPFH        ;  // EP2 Programmable Flag trigger H
-EXTERN xdata _AT_(0xE631) volatile BYTE EP2FIFOPFL        ;  // EP2 Programmable Flag trigger L
-EXTERN xdata _AT_(0xE632) volatile BYTE EP4FIFOPFH        ;  // EP4 Programmable Flag trigger H
-EXTERN xdata _AT_(0xE633) volatile BYTE EP4FIFOPFL        ;  // EP4 Programmable Flag trigger L
-EXTERN xdata _AT_(0xE634) volatile BYTE EP6FIFOPFH        ;  // EP6 Programmable Flag trigger H
-EXTERN xdata _AT_(0xE635) volatile BYTE EP6FIFOPFL        ;  // EP6 Programmable Flag trigger L
-EXTERN xdata _AT_(0xE636) volatile BYTE EP8FIFOPFH        ;  // EP8 Programmable Flag trigger H
-EXTERN xdata _AT_(0xE637) volatile BYTE EP8FIFOPFL        ;  // EP8 Programmable Flag trigger L
-EXTERN xdata _AT_(0xE640) volatile BYTE EP2ISOINPKTS      ;  // EP2 (if ISO) IN Packets per frame (1-3)
-EXTERN xdata _AT_(0xE641) volatile BYTE EP4ISOINPKTS      ;  // EP4 (if ISO) IN Packets per frame (1-3)
-EXTERN xdata _AT_(0xE642) volatile BYTE EP6ISOINPKTS      ;  // EP6 (if ISO) IN Packets per frame (1-3)
-EXTERN xdata _AT_(0xE643) volatile BYTE EP8ISOINPKTS      ;  // EP8 (if ISO) IN Packets per frame (1-3)
-EXTERN xdata _AT_(0xE648) volatile BYTE INPKTEND          ;  // Force IN Packet End
-EXTERN xdata _AT_(0xE649) volatile BYTE OUTPKTEND         ;  // Force OUT Packet End
+EXTERN __xdata _AT_(0xE610) volatile BYTE EP1OUTCFG         ;  // Endpoint 1-OUT Configuration
+EXTERN __xdata _AT_(0xE611) volatile BYTE EP1INCFG          ;  // Endpoint 1-IN Configuration
+EXTERN __xdata _AT_(0xE612) volatile BYTE EP2CFG            ;  // Endpoint 2 Configuration
+EXTERN __xdata _AT_(0xE613) volatile BYTE EP4CFG            ;  // Endpoint 4 Configuration
+EXTERN __xdata _AT_(0xE614) volatile BYTE EP6CFG            ;  // Endpoint 6 Configuration
+EXTERN __xdata _AT_(0xE615) volatile BYTE EP8CFG            ;  // Endpoint 8 Configuration
+EXTERN __xdata _AT_(0xE618) volatile BYTE EP2FIFOCFG        ;  // Endpoint 2 FIFO configuration
+EXTERN __xdata _AT_(0xE619) volatile BYTE EP4FIFOCFG        ;  // Endpoint 4 FIFO configuration
+EXTERN __xdata _AT_(0xE61A) volatile BYTE EP6FIFOCFG        ;  // Endpoint 6 FIFO configuration
+EXTERN __xdata _AT_(0xE61B) volatile BYTE EP8FIFOCFG        ;  // Endpoint 8 FIFO configuration
+EXTERN __xdata _AT_(0xE620) volatile BYTE EP2AUTOINLENH     ;  // Endpoint 2 Packet Length H (IN only)
+EXTERN __xdata _AT_(0xE621) volatile BYTE EP2AUTOINLENL     ;  // Endpoint 2 Packet Length L (IN only)
+EXTERN __xdata _AT_(0xE622) volatile BYTE EP4AUTOINLENH     ;  // Endpoint 4 Packet Length H (IN only)
+EXTERN __xdata _AT_(0xE623) volatile BYTE EP4AUTOINLENL     ;  // Endpoint 4 Packet Length L (IN only)
+EXTERN __xdata _AT_(0xE624) volatile BYTE EP6AUTOINLENH     ;  // Endpoint 6 Packet Length H (IN only)
+EXTERN __xdata _AT_(0xE625) volatile BYTE EP6AUTOINLENL     ;  // Endpoint 6 Packet Length L (IN only)
+EXTERN __xdata _AT_(0xE626) volatile BYTE EP8AUTOINLENH     ;  // Endpoint 8 Packet Length H (IN only)
+EXTERN __xdata _AT_(0xE627) volatile BYTE EP8AUTOINLENL     ;  // Endpoint 8 Packet Length L (IN only)
+EXTERN __xdata _AT_(0xE630) volatile BYTE EP2FIFOPFH        ;  // EP2 Programmable Flag trigger H
+EXTERN __xdata _AT_(0xE631) volatile BYTE EP2FIFOPFL        ;  // EP2 Programmable Flag trigger L
+EXTERN __xdata _AT_(0xE632) volatile BYTE EP4FIFOPFH        ;  // EP4 Programmable Flag trigger H
+EXTERN __xdata _AT_(0xE633) volatile BYTE EP4FIFOPFL        ;  // EP4 Programmable Flag trigger L
+EXTERN __xdata _AT_(0xE634) volatile BYTE EP6FIFOPFH        ;  // EP6 Programmable Flag trigger H
+EXTERN __xdata _AT_(0xE635) volatile BYTE EP6FIFOPFL        ;  // EP6 Programmable Flag trigger L
+EXTERN __xdata _AT_(0xE636) volatile BYTE EP8FIFOPFH        ;  // EP8 Programmable Flag trigger H
+EXTERN __xdata _AT_(0xE637) volatile BYTE EP8FIFOPFL        ;  // EP8 Programmable Flag trigger L
+EXTERN __xdata _AT_(0xE640) volatile BYTE EP2ISOINPKTS      ;  // EP2 (if ISO) IN Packets per frame (1-3)
+EXTERN __xdata _AT_(0xE641) volatile BYTE EP4ISOINPKTS      ;  // EP4 (if ISO) IN Packets per frame (1-3)
+EXTERN __xdata _AT_(0xE642) volatile BYTE EP6ISOINPKTS      ;  // EP6 (if ISO) IN Packets per frame (1-3)
+EXTERN __xdata _AT_(0xE643) volatile BYTE EP8ISOINPKTS      ;  // EP8 (if ISO) IN Packets per frame (1-3)
+EXTERN __xdata _AT_(0xE648) volatile BYTE INPKTEND          ;  // Force IN Packet End
+EXTERN __xdata _AT_(0xE649) volatile BYTE OUTPKTEND         ;  // Force OUT Packet End
 
 // Interrupts
 
-EXTERN xdata _AT_(0xE650) volatile BYTE EP2FIFOIE         ;  // Endpoint 2 Flag Interrupt Enable
-EXTERN xdata _AT_(0xE651) volatile BYTE EP2FIFOIRQ        ;  // Endpoint 2 Flag Interrupt Request
-EXTERN xdata _AT_(0xE652) volatile BYTE EP4FIFOIE         ;  // Endpoint 4 Flag Interrupt Enable
-EXTERN xdata _AT_(0xE653) volatile BYTE EP4FIFOIRQ        ;  // Endpoint 4 Flag Interrupt Request
-EXTERN xdata _AT_(0xE654) volatile BYTE EP6FIFOIE         ;  // Endpoint 6 Flag Interrupt Enable
-EXTERN xdata _AT_(0xE655) volatile BYTE EP6FIFOIRQ        ;  // Endpoint 6 Flag Interrupt Request
-EXTERN xdata _AT_(0xE656) volatile BYTE EP8FIFOIE         ;  // Endpoint 8 Flag Interrupt Enable
-EXTERN xdata _AT_(0xE657) volatile BYTE EP8FIFOIRQ        ;  // Endpoint 8 Flag Interrupt Request
-EXTERN xdata _AT_(0xE658) volatile BYTE IBNIE             ;  // IN-BULK-NAK Interrupt Enable
-EXTERN xdata _AT_(0xE659) volatile BYTE IBNIRQ            ;  // IN-BULK-NAK interrupt Request
-EXTERN xdata _AT_(0xE65A) volatile BYTE NAKIE             ;  // Endpoint Ping NAK interrupt Enable
-EXTERN xdata _AT_(0xE65B) volatile BYTE NAKIRQ            ;  // Endpoint Ping NAK interrupt Request
-EXTERN xdata _AT_(0xE65C) volatile BYTE USBIE             ;  // USB Int Enables
-EXTERN xdata _AT_(0xE65D) volatile BYTE USBIRQ            ;  // USB Interrupt Requests
-EXTERN xdata _AT_(0xE65E) volatile BYTE EPIE              ;  // Endpoint Interrupt Enables
-EXTERN xdata _AT_(0xE65F) volatile BYTE EPIRQ             ;  // Endpoint Interrupt Requests
-EXTERN xdata _AT_(0xE660) volatile BYTE GPIFIE            ;  // GPIF Interrupt Enable
-EXTERN xdata _AT_(0xE661) volatile BYTE GPIFIRQ           ;  // GPIF Interrupt Request
-EXTERN xdata _AT_(0xE662) volatile BYTE USBERRIE          ;  // USB Error Interrupt Enables
-EXTERN xdata _AT_(0xE663) volatile BYTE USBERRIRQ         ;  // USB Error Interrupt Requests
-EXTERN xdata _AT_(0xE664) volatile BYTE ERRCNTLIM         ;  // USB Error counter and limit
-EXTERN xdata _AT_(0xE665) volatile BYTE CLRERRCNT         ;  // Clear Error Counter EC[3..0]
-EXTERN xdata _AT_(0xE666) volatile BYTE INT2IVEC          ;  // Interupt 2 (USB) Autovector
-EXTERN xdata _AT_(0xE667) volatile BYTE INT4IVEC          ;  // Interupt 4 (FIFOS & GPIF) Autovector
-EXTERN xdata _AT_(0xE668) volatile BYTE INTSETUP          ;  // Interrupt 2&4 Setup
+EXTERN __xdata _AT_(0xE650) volatile BYTE EP2FIFOIE         ;  // Endpoint 2 Flag Interrupt Enable
+EXTERN __xdata _AT_(0xE651) volatile BYTE EP2FIFOIRQ        ;  // Endpoint 2 Flag Interrupt Request
+EXTERN __xdata _AT_(0xE652) volatile BYTE EP4FIFOIE         ;  // Endpoint 4 Flag Interrupt Enable
+EXTERN __xdata _AT_(0xE653) volatile BYTE EP4FIFOIRQ        ;  // Endpoint 4 Flag Interrupt Request
+EXTERN __xdata _AT_(0xE654) volatile BYTE EP6FIFOIE         ;  // Endpoint 6 Flag Interrupt Enable
+EXTERN __xdata _AT_(0xE655) volatile BYTE EP6FIFOIRQ        ;  // Endpoint 6 Flag Interrupt Request
+EXTERN __xdata _AT_(0xE656) volatile BYTE EP8FIFOIE         ;  // Endpoint 8 Flag Interrupt Enable
+EXTERN __xdata _AT_(0xE657) volatile BYTE EP8FIFOIRQ        ;  // Endpoint 8 Flag Interrupt Request
+EXTERN __xdata _AT_(0xE658) volatile BYTE IBNIE             ;  // IN-BULK-NAK Interrupt Enable
+EXTERN __xdata _AT_(0xE659) volatile BYTE IBNIRQ            ;  // IN-BULK-NAK interrupt Request
+EXTERN __xdata _AT_(0xE65A) volatile BYTE NAKIE             ;  // Endpoint Ping NAK interrupt Enable
+EXTERN __xdata _AT_(0xE65B) volatile BYTE NAKIRQ            ;  // Endpoint Ping NAK interrupt Request
+EXTERN __xdata _AT_(0xE65C) volatile BYTE USBIE             ;  // USB Int Enables
+EXTERN __xdata _AT_(0xE65D) volatile BYTE USBIRQ            ;  // USB Interrupt Requests
+EXTERN __xdata _AT_(0xE65E) volatile BYTE EPIE              ;  // Endpoint Interrupt Enables
+EXTERN __xdata _AT_(0xE65F) volatile BYTE EPIRQ             ;  // Endpoint Interrupt Requests
+EXTERN __xdata _AT_(0xE660) volatile BYTE GPIFIE            ;  // GPIF Interrupt Enable
+EXTERN __xdata _AT_(0xE661) volatile BYTE GPIFIRQ           ;  // GPIF Interrupt Request
+EXTERN __xdata _AT_(0xE662) volatile BYTE USBERRIE          ;  // USB Error Interrupt Enables
+EXTERN __xdata _AT_(0xE663) volatile BYTE USBERRIRQ         ;  // USB Error Interrupt Requests
+EXTERN __xdata _AT_(0xE664) volatile BYTE ERRCNTLIM         ;  // USB Error counter and limit
+EXTERN __xdata _AT_(0xE665) volatile BYTE CLRERRCNT         ;  // Clear Error Counter EC[3..0]
+EXTERN __xdata _AT_(0xE666) volatile BYTE INT2IVEC          ;  // Interupt 2 (USB) Autovector
+EXTERN __xdata _AT_(0xE667) volatile BYTE INT4IVEC          ;  // Interupt 4 (FIFOS & GPIF) Autovector
+EXTERN __xdata _AT_(0xE668) volatile BYTE INTSETUP          ;  // Interrupt 2&4 Setup
 
 // Input/Output
 
-EXTERN xdata _AT_(0xE670) volatile BYTE PORTACFG          ;  // I/O PORTA Alternate Configuration
-EXTERN xdata _AT_(0xE671) volatile BYTE PORTCCFG          ;  // I/O PORTC Alternate Configuration
-EXTERN xdata _AT_(0xE672) volatile BYTE PORTECFG          ;  // I/O PORTE Alternate Configuration
-EXTERN xdata _AT_(0xE678) volatile BYTE I2CS              ;  // Control & Status
-EXTERN xdata _AT_(0xE679) volatile BYTE I2DAT             ;  // Data
-EXTERN xdata _AT_(0xE67A) volatile BYTE I2CTL             ;  // I2C Control
-EXTERN xdata _AT_(0xE67B) volatile BYTE XAUTODAT1         ;  // Autoptr1 MOVX access
-EXTERN xdata _AT_(0xE67C) volatile BYTE XAUTODAT2         ;  // Autoptr2 MOVX access
+EXTERN __xdata _AT_(0xE670) volatile BYTE PORTACFG          ;  // I/O PORTA Alternate Configuration
+EXTERN __xdata _AT_(0xE671) volatile BYTE PORTCCFG          ;  // I/O PORTC Alternate Configuration
+EXTERN __xdata _AT_(0xE672) volatile BYTE PORTECFG          ;  // I/O PORTE Alternate Configuration
+EXTERN __xdata _AT_(0xE678) volatile BYTE I2CS              ;  // Control & Status
+EXTERN __xdata _AT_(0xE679) volatile BYTE I2DAT             ;  // Data
+EXTERN __xdata _AT_(0xE67A) volatile BYTE I2CTL             ;  // I2C Control
+EXTERN __xdata _AT_(0xE67B) volatile BYTE XAUTODAT1         ;  // Autoptr1 MOVX access
+EXTERN __xdata _AT_(0xE67C) volatile BYTE XAUTODAT2         ;  // Autoptr2 MOVX access
 
 #define EXTAUTODAT1 XAUTODAT1
 #define EXTAUTODAT2 XAUTODAT2
 
 // USB Control
 
-EXTERN xdata _AT_(0xE680) volatile BYTE USBCS             ;  // USB Control & Status
-EXTERN xdata _AT_(0xE681) volatile BYTE SUSPEND           ;  // Put chip into suspend
-EXTERN xdata _AT_(0xE682) volatile BYTE WAKEUPCS          ;  // Wakeup source and polarity
-EXTERN xdata _AT_(0xE683) volatile BYTE TOGCTL            ;  // Toggle Control
-EXTERN xdata _AT_(0xE684) volatile BYTE USBFRAMEH         ;  // USB Frame count H
-EXTERN xdata _AT_(0xE685) volatile BYTE USBFRAMEL         ;  // USB Frame count L
-EXTERN xdata _AT_(0xE686) volatile BYTE MICROFRAME        ;  // Microframe count, 0-7
-EXTERN xdata _AT_(0xE687) volatile BYTE FNADDR            ;  // USB Function address
+EXTERN __xdata _AT_(0xE680) volatile BYTE USBCS             ;  // USB Control & Status
+EXTERN __xdata _AT_(0xE681) volatile BYTE SUSPEND           ;  // Put chip into suspend
+EXTERN __xdata _AT_(0xE682) volatile BYTE WAKEUPCS          ;  // Wakeup source and polarity
+EXTERN __xdata _AT_(0xE683) volatile BYTE TOGCTL            ;  // Toggle Control
+EXTERN __xdata _AT_(0xE684) volatile BYTE USBFRAMEH         ;  // USB Frame count H
+EXTERN __xdata _AT_(0xE685) volatile BYTE USBFRAMEL         ;  // USB Frame count L
+EXTERN __xdata _AT_(0xE686) volatile BYTE MICROFRAME        ;  // Microframe count, 0-7
+EXTERN __xdata _AT_(0xE687) volatile BYTE FNADDR            ;  // USB Function address
 
 // Endpoints
 
-EXTERN xdata _AT_(0xE68A) volatile BYTE EP0BCH            ;  // Endpoint 0 Byte Count H
-EXTERN xdata _AT_(0xE68B) volatile BYTE EP0BCL            ;  // Endpoint 0 Byte Count L
-EXTERN xdata _AT_(0xE68D) volatile BYTE EP1OUTBC          ;  // Endpoint 1 OUT Byte Count
-EXTERN xdata _AT_(0xE68F) volatile BYTE EP1INBC           ;  // Endpoint 1 IN Byte Count
-EXTERN xdata _AT_(0xE690) volatile BYTE EP2BCH            ;  // Endpoint 2 Byte Count H
-EXTERN xdata _AT_(0xE691) volatile BYTE EP2BCL            ;  // Endpoint 2 Byte Count L
-EXTERN xdata _AT_(0xE694) volatile BYTE EP4BCH            ;  // Endpoint 4 Byte Count H
-EXTERN xdata _AT_(0xE695) volatile BYTE EP4BCL            ;  // Endpoint 4 Byte Count L
-EXTERN xdata _AT_(0xE698) volatile BYTE EP6BCH            ;  // Endpoint 6 Byte Count H
-EXTERN xdata _AT_(0xE699) volatile BYTE EP6BCL            ;  // Endpoint 6 Byte Count L
-EXTERN xdata _AT_(0xE69C) volatile BYTE EP8BCH            ;  // Endpoint 8 Byte Count H
-EXTERN xdata _AT_(0xE69D) volatile BYTE EP8BCL            ;  // Endpoint 8 Byte Count L
-EXTERN xdata _AT_(0xE6A0) volatile BYTE EP0CS             ;  // Endpoint  Control and Status
-EXTERN xdata _AT_(0xE6A1) volatile BYTE EP1OUTCS          ;  // Endpoint 1 OUT Control and Status
-EXTERN xdata _AT_(0xE6A2) volatile BYTE EP1INCS           ;  // Endpoint 1 IN Control and Status
-EXTERN xdata _AT_(0xE6A3) volatile BYTE EP2CS             ;  // Endpoint 2 Control and Status
-EXTERN xdata _AT_(0xE6A4) volatile BYTE EP4CS             ;  // Endpoint 4 Control and Status
-EXTERN xdata _AT_(0xE6A5) volatile BYTE EP6CS             ;  // Endpoint 6 Control and Status
-EXTERN xdata _AT_(0xE6A6) volatile BYTE EP8CS             ;  // Endpoint 8 Control and Status
-EXTERN xdata _AT_(0xE6A7) volatile BYTE EP2FIFOFLGS       ;  // Endpoint 2 Flags
-EXTERN xdata _AT_(0xE6A8) volatile BYTE EP4FIFOFLGS       ;  // Endpoint 4 Flags
-EXTERN xdata _AT_(0xE6A9) volatile BYTE EP6FIFOFLGS       ;  // Endpoint 6 Flags
-EXTERN xdata _AT_(0xE6AA) volatile BYTE EP8FIFOFLGS       ;  // Endpoint 8 Flags
-EXTERN xdata _AT_(0xE6AB) volatile BYTE EP2FIFOBCH        ;  // EP2 FIFO total byte count H
-EXTERN xdata _AT_(0xE6AC) volatile BYTE EP2FIFOBCL        ;  // EP2 FIFO total byte count L
-EXTERN xdata _AT_(0xE6AD) volatile BYTE EP4FIFOBCH        ;  // EP4 FIFO total byte count H
-EXTERN xdata _AT_(0xE6AE) volatile BYTE EP4FIFOBCL        ;  // EP4 FIFO total byte count L
-EXTERN xdata _AT_(0xE6AF) volatile BYTE EP6FIFOBCH        ;  // EP6 FIFO total byte count H
-EXTERN xdata _AT_(0xE6B0) volatile BYTE EP6FIFOBCL        ;  // EP6 FIFO total byte count L
-EXTERN xdata _AT_(0xE6B1) volatile BYTE EP8FIFOBCH        ;  // EP8 FIFO total byte count H
-EXTERN xdata _AT_(0xE6B2) volatile BYTE EP8FIFOBCL        ;  // EP8 FIFO total byte count L
-EXTERN xdata _AT_(0xE6B3) volatile BYTE SUDPTRH           ;  // Setup Data Pointer high address byte
-EXTERN xdata _AT_(0xE6B4) volatile BYTE SUDPTRL           ;  // Setup Data Pointer low address byte
-EXTERN xdata _AT_(0xE6B5) volatile BYTE SUDPTRCTL         ;  // Setup Data Pointer Auto Mode
-EXTERN xdata _AT_(0xE6B8) volatile BYTE SETUPDAT[8]       ;  // 8 bytes of SETUP data
+EXTERN __xdata _AT_(0xE68A) volatile BYTE EP0BCH            ;  // Endpoint 0 Byte Count H
+EXTERN __xdata _AT_(0xE68B) volatile BYTE EP0BCL            ;  // Endpoint 0 Byte Count L
+EXTERN __xdata _AT_(0xE68D) volatile BYTE EP1OUTBC          ;  // Endpoint 1 OUT Byte Count
+EXTERN __xdata _AT_(0xE68F) volatile BYTE EP1INBC           ;  // Endpoint 1 IN Byte Count
+EXTERN __xdata _AT_(0xE690) volatile BYTE EP2BCH            ;  // Endpoint 2 Byte Count H
+EXTERN __xdata _AT_(0xE691) volatile BYTE EP2BCL            ;  // Endpoint 2 Byte Count L
+EXTERN __xdata _AT_(0xE694) volatile BYTE EP4BCH            ;  // Endpoint 4 Byte Count H
+EXTERN __xdata _AT_(0xE695) volatile BYTE EP4BCL            ;  // Endpoint 4 Byte Count L
+EXTERN __xdata _AT_(0xE698) volatile BYTE EP6BCH            ;  // Endpoint 6 Byte Count H
+EXTERN __xdata _AT_(0xE699) volatile BYTE EP6BCL            ;  // Endpoint 6 Byte Count L
+EXTERN __xdata _AT_(0xE69C) volatile BYTE EP8BCH            ;  // Endpoint 8 Byte Count H
+EXTERN __xdata _AT_(0xE69D) volatile BYTE EP8BCL            ;  // Endpoint 8 Byte Count L
+EXTERN __xdata _AT_(0xE6A0) volatile BYTE EP0CS             ;  // Endpoint  Control and Status
+EXTERN __xdata _AT_(0xE6A1) volatile BYTE EP1OUTCS          ;  // Endpoint 1 OUT Control and Status
+EXTERN __xdata _AT_(0xE6A2) volatile BYTE EP1INCS           ;  // Endpoint 1 IN Control and Status
+EXTERN __xdata _AT_(0xE6A3) volatile BYTE EP2CS             ;  // Endpoint 2 Control and Status
+EXTERN __xdata _AT_(0xE6A4) volatile BYTE EP4CS             ;  // Endpoint 4 Control and Status
+EXTERN __xdata _AT_(0xE6A5) volatile BYTE EP6CS             ;  // Endpoint 6 Control and Status
+EXTERN __xdata _AT_(0xE6A6) volatile BYTE EP8CS             ;  // Endpoint 8 Control and Status
+EXTERN __xdata _AT_(0xE6A7) volatile BYTE EP2FIFOFLGS       ;  // Endpoint 2 Flags
+EXTERN __xdata _AT_(0xE6A8) volatile BYTE EP4FIFOFLGS       ;  // Endpoint 4 Flags
+EXTERN __xdata _AT_(0xE6A9) volatile BYTE EP6FIFOFLGS       ;  // Endpoint 6 Flags
+EXTERN __xdata _AT_(0xE6AA) volatile BYTE EP8FIFOFLGS       ;  // Endpoint 8 Flags
+EXTERN __xdata _AT_(0xE6AB) volatile BYTE EP2FIFOBCH        ;  // EP2 FIFO total byte count H
+EXTERN __xdata _AT_(0xE6AC) volatile BYTE EP2FIFOBCL        ;  // EP2 FIFO total byte count L
+EXTERN __xdata _AT_(0xE6AD) volatile BYTE EP4FIFOBCH        ;  // EP4 FIFO total byte count H
+EXTERN __xdata _AT_(0xE6AE) volatile BYTE EP4FIFOBCL        ;  // EP4 FIFO total byte count L
+EXTERN __xdata _AT_(0xE6AF) volatile BYTE EP6FIFOBCH        ;  // EP6 FIFO total byte count H
+EXTERN __xdata _AT_(0xE6B0) volatile BYTE EP6FIFOBCL        ;  // EP6 FIFO total byte count L
+EXTERN __xdata _AT_(0xE6B1) volatile BYTE EP8FIFOBCH        ;  // EP8 FIFO total byte count H
+EXTERN __xdata _AT_(0xE6B2) volatile BYTE EP8FIFOBCL        ;  // EP8 FIFO total byte count L
+EXTERN __xdata _AT_(0xE6B3) volatile BYTE SUDPTRH           ;  // Setup Data Pointer high address byte
+EXTERN __xdata _AT_(0xE6B4) volatile BYTE SUDPTRL           ;  // Setup Data Pointer low address byte
+EXTERN __xdata _AT_(0xE6B5) volatile BYTE SUDPTRCTL         ;  // Setup Data Pointer Auto Mode
+EXTERN __xdata _AT_(0xE6B8) volatile BYTE SETUPDAT[8]       ;  // 8 bytes of SETUP data
 
 // GPIF
 
-EXTERN xdata _AT_(0xE6C0) volatile BYTE GPIFWFSELECT      ;  // Waveform Selector
-EXTERN xdata _AT_(0xE6C1) volatile BYTE GPIFIDLECS        ;  // GPIF Done, GPIF IDLE drive mode
-EXTERN xdata _AT_(0xE6C2) volatile BYTE GPIFIDLECTL       ;  // Inactive Bus, CTL states
-EXTERN xdata _AT_(0xE6C3) volatile BYTE GPIFCTLCFG        ;  // CTL OUT pin drive
-EXTERN xdata _AT_(0xE6C4) volatile BYTE GPIFADRH          ;  // GPIF Address H
-EXTERN xdata _AT_(0xE6C5) volatile BYTE GPIFADRL          ;  // GPIF Address L
-
-EXTERN xdata _AT_(0xE6CE) volatile BYTE GPIFTCB3          ;  // GPIF Transaction Count Byte 3
-EXTERN xdata _AT_(0xE6CF) volatile BYTE GPIFTCB2          ;  // GPIF Transaction Count Byte 2
-EXTERN xdata _AT_(0xE6D0) volatile BYTE GPIFTCB1          ;  // GPIF Transaction Count Byte 1
-EXTERN xdata _AT_(0xE6D1) volatile BYTE GPIFTCB0          ;  // GPIF Transaction Count Byte 0
+EXTERN __xdata _AT_(0xE6C0) volatile BYTE GPIFWFSELECT      ;  // Waveform Selector
+EXTERN __xdata _AT_(0xE6C1) volatile BYTE GPIFIDLECS        ;  // GPIF Done, GPIF IDLE drive mode
+EXTERN __xdata _AT_(0xE6C2) volatile BYTE GPIFIDLECTL       ;  // Inactive Bus, CTL states
+EXTERN __xdata _AT_(0xE6C3) volatile BYTE GPIFCTLCFG        ;  // CTL OUT pin drive
+EXTERN __xdata _AT_(0xE6C4) volatile BYTE GPIFADRH          ;  // GPIF Address H
+EXTERN __xdata _AT_(0xE6C5) volatile BYTE GPIFADRL          ;  // GPIF Address L
+
+EXTERN __xdata _AT_(0xE6CE) volatile BYTE GPIFTCB3          ;  // GPIF Transaction Count Byte 3
+EXTERN __xdata _AT_(0xE6CF) volatile BYTE GPIFTCB2          ;  // GPIF Transaction Count Byte 2
+EXTERN __xdata _AT_(0xE6D0) volatile BYTE GPIFTCB1          ;  // GPIF Transaction Count Byte 1
+EXTERN __xdata _AT_(0xE6D1) volatile BYTE GPIFTCB0          ;  // GPIF Transaction Count Byte 0
 
 #define EP2GPIFTCH GPIFTCB1   // these are here for backwards compatibility
 #define EP2GPIFTCL GPIFTCB0   // before REVE silicon (ie. REVB and REVD)
@@ -239,68 +243,68 @@
 #define EP8GPIFTCH GPIFTCB1   // these are here for backwards compatibility
 #define EP8GPIFTCL GPIFTCB0   // before REVE silicon (ie. REVB and REVD)
 
-// EXTERN xdata volatile BYTE EP2GPIFTCH     _AT_ 0xE6D0;  // EP2 GPIF Transaction Count High
-// EXTERN xdata volatile BYTE EP2GPIFTCL     _AT_ 0xE6D1;  // EP2 GPIF Transaction Count Low
-EXTERN xdata _AT_(0xE6D2) volatile BYTE EP2GPIFFLGSEL     ;  // EP2 GPIF Flag select
-EXTERN xdata _AT_(0xE6D3) volatile BYTE EP2GPIFPFSTOP     ;  // Stop GPIF EP2 transaction on prog. flag
-EXTERN xdata _AT_(0xE6D4) volatile BYTE EP2GPIFTRIG       ;  // EP2 FIFO Trigger
-// EXTERN xdata volatile BYTE EP4GPIFTCH     _AT_ 0xE6D8;  // EP4 GPIF Transaction Count High
-// EXTERN xdata volatile BYTE EP4GPIFTCL     _AT_ 0xE6D9;  // EP4 GPIF Transactionr Count Low
-EXTERN xdata _AT_(0xE6DA) volatile BYTE EP4GPIFFLGSEL     ;  // EP4 GPIF Flag select
-EXTERN xdata _AT_(0xE6DB) volatile BYTE EP4GPIFPFSTOP     ;  // Stop GPIF EP4 transaction on prog. flag
-EXTERN xdata _AT_(0xE6DC) volatile BYTE EP4GPIFTRIG       ;  // EP4 FIFO Trigger
-// EXTERN xdata volatile BYTE EP6GPIFTCH     _AT_ 0xE6E0;  // EP6 GPIF Transaction Count High
-// EXTERN xdata volatile BYTE EP6GPIFTCL     _AT_ 0xE6E1;  // EP6 GPIF Transaction Count Low
-EXTERN xdata _AT_(0xE6E2) volatile BYTE EP6GPIFFLGSEL     ;  // EP6 GPIF Flag select
-EXTERN xdata _AT_(0xE6E3) volatile BYTE EP6GPIFPFSTOP     ;  // Stop GPIF EP6 transaction on prog. flag
-EXTERN xdata _AT_(0xE6E4) volatile BYTE EP6GPIFTRIG       ;  // EP6 FIFO Trigger
-// EXTERN xdata volatile BYTE EP8GPIFTCH     _AT_ 0xE6E8;  // EP8 GPIF Transaction Count High
-// EXTERN xdata volatile BYTE EP8GPIFTCL     _AT_ 0xE6E9;  // EP8GPIF Transaction Count Low
-EXTERN xdata _AT_(0xE6EA) volatile BYTE EP8GPIFFLGSEL     ;  // EP8 GPIF Flag select
-EXTERN xdata _AT_(0xE6EB) volatile BYTE EP8GPIFPFSTOP     ;  // Stop GPIF EP8 transaction on prog. flag
-EXTERN xdata _AT_(0xE6EC) volatile BYTE EP8GPIFTRIG       ;  // EP8 FIFO Trigger
-EXTERN xdata _AT_(0xE6F0) volatile BYTE XGPIFSGLDATH      ;  // GPIF Data H (16-bit mode only)
-EXTERN xdata _AT_(0xE6F1) volatile BYTE XGPIFSGLDATLX     ;  // Read/Write GPIF Data L & trigger transac
-EXTERN xdata _AT_(0xE6F2) volatile BYTE XGPIFSGLDATLNOX   ;  // Read GPIF Data L, no transac trigger
-EXTERN xdata _AT_(0xE6F3) volatile BYTE GPIFREADYCFG      ;  // Internal RDY,Sync/Async, RDY5CFG
-EXTERN xdata _AT_(0xE6F4) volatile BYTE GPIFREADYSTAT     ;  // RDY pin states
-EXTERN xdata _AT_(0xE6F5) volatile BYTE GPIFABORT         ;  // Abort GPIF cycles
+// EXTERN __xdata volatile BYTE EP2GPIFTCH     _AT_ 0xE6D0;  // EP2 GPIF Transaction Count High
+// EXTERN __xdata volatile BYTE EP2GPIFTCL     _AT_ 0xE6D1;  // EP2 GPIF Transaction Count Low
+EXTERN __xdata _AT_(0xE6D2) volatile BYTE EP2GPIFFLGSEL     ;  // EP2 GPIF Flag select
+EXTERN __xdata _AT_(0xE6D3) volatile BYTE EP2GPIFPFSTOP     ;  // Stop GPIF EP2 transaction on prog. flag
+EXTERN __xdata _AT_(0xE6D4) volatile BYTE EP2GPIFTRIG       ;  // EP2 FIFO Trigger
+// EXTERN __xdata volatile BYTE EP4GPIFTCH     _AT_ 0xE6D8;  // EP4 GPIF Transaction Count High
+// EXTERN __xdata volatile BYTE EP4GPIFTCL     _AT_ 0xE6D9;  // EP4 GPIF Transactionr Count Low
+EXTERN __xdata _AT_(0xE6DA) volatile BYTE EP4GPIFFLGSEL     ;  // EP4 GPIF Flag select
+EXTERN __xdata _AT_(0xE6DB) volatile BYTE EP4GPIFPFSTOP     ;  // Stop GPIF EP4 transaction on prog. flag
+EXTERN __xdata _AT_(0xE6DC) volatile BYTE EP4GPIFTRIG       ;  // EP4 FIFO Trigger
+// EXTERN __xdata volatile BYTE EP6GPIFTCH     _AT_ 0xE6E0;  // EP6 GPIF Transaction Count High
+// EXTERN __xdata volatile BYTE EP6GPIFTCL     _AT_ 0xE6E1;  // EP6 GPIF Transaction Count Low
+EXTERN __xdata _AT_(0xE6E2) volatile BYTE EP6GPIFFLGSEL     ;  // EP6 GPIF Flag select
+EXTERN __xdata _AT_(0xE6E3) volatile BYTE EP6GPIFPFSTOP     ;  // Stop GPIF EP6 transaction on prog. flag
+EXTERN __xdata _AT_(0xE6E4) volatile BYTE EP6GPIFTRIG       ;  // EP6 FIFO Trigger
+// EXTERN __xdata volatile BYTE EP8GPIFTCH     _AT_ 0xE6E8;  // EP8 GPIF Transaction Count High
+// EXTERN __xdata volatile BYTE EP8GPIFTCL     _AT_ 0xE6E9;  // EP8GPIF Transaction Count Low
+EXTERN __xdata _AT_(0xE6EA) volatile BYTE EP8GPIFFLGSEL     ;  // EP8 GPIF Flag select
+EXTERN __xdata _AT_(0xE6EB) volatile BYTE EP8GPIFPFSTOP     ;  // Stop GPIF EP8 transaction on prog. flag
+EXTERN __xdata _AT_(0xE6EC) volatile BYTE EP8GPIFTRIG       ;  // EP8 FIFO Trigger
+EXTERN __xdata _AT_(0xE6F0) volatile BYTE XGPIFSGLDATH      ;  // GPIF Data H (16-bit mode only)
+EXTERN __xdata _AT_(0xE6F1) volatile BYTE XGPIFSGLDATLX     ;  // Read/Write GPIF Data L & trigger transac
+EXTERN __xdata _AT_(0xE6F2) volatile BYTE XGPIFSGLDATLNOX   ;  // Read GPIF Data L, no transac trigger
+EXTERN __xdata _AT_(0xE6F3) volatile BYTE GPIFREADYCFG      ;  // Internal RDY,Sync/Async, RDY5CFG
+EXTERN __xdata _AT_(0xE6F4) volatile BYTE GPIFREADYSTAT     ;  // RDY pin states
+EXTERN __xdata _AT_(0xE6F5) volatile BYTE GPIFABORT         ;  // Abort GPIF cycles
 
 // UDMA
 
-EXTERN xdata _AT_(0xE6C6) volatile BYTE FLOWSTATE         ; //Defines GPIF flow state
-EXTERN xdata _AT_(0xE6C7) volatile BYTE FLOWLOGIC         ; //Defines flow/hold decision criteria
-EXTERN xdata _AT_(0xE6C8) volatile BYTE FLOWEQ0CTL        ; //CTL states during active flow state
-EXTERN xdata _AT_(0xE6C9) volatile BYTE FLOWEQ1CTL        ; //CTL states during hold flow state
-EXTERN xdata _AT_(0xE6CA) volatile BYTE FLOWHOLDOFF       ;
-EXTERN xdata _AT_(0xE6CB) volatile BYTE FLOWSTB           ; //CTL/RDY Signal to use as master data strobe 
-EXTERN xdata _AT_(0xE6CC) volatile BYTE FLOWSTBEDGE       ; //Defines active master strobe edge
-EXTERN xdata _AT_(0xE6CD) volatile BYTE FLOWSTBHPERIOD    ; //Half Period of output master strobe
-EXTERN xdata _AT_(0xE60C) volatile BYTE GPIFHOLDAMOUNT    ; //Data delay shift 
-EXTERN xdata _AT_(0xE67D) volatile BYTE UDMACRCH          ; //CRC Upper byte
-EXTERN xdata _AT_(0xE67E) volatile BYTE UDMACRCL          ; //CRC Lower byte
-EXTERN xdata _AT_(0xE67F) volatile BYTE UDMACRCQUAL       ; //UDMA In only, host terminated use only
+EXTERN __xdata _AT_(0xE6C6) volatile BYTE FLOWSTATE         ; //Defines GPIF flow state
+EXTERN __xdata _AT_(0xE6C7) volatile BYTE FLOWLOGIC         ; //Defines flow/hold decision criteria
+EXTERN __xdata _AT_(0xE6C8) volatile BYTE FLOWEQ0CTL        ; //CTL states during active flow state
+EXTERN __xdata _AT_(0xE6C9) volatile BYTE FLOWEQ1CTL        ; //CTL states during hold flow state
+EXTERN __xdata _AT_(0xE6CA) volatile BYTE FLOWHOLDOFF       ;
+EXTERN __xdata _AT_(0xE6CB) volatile BYTE FLOWSTB           ; //CTL/RDY Signal to use as master data strobe 
+EXTERN __xdata _AT_(0xE6CC) volatile BYTE FLOWSTBEDGE       ; //Defines active master strobe edge
+EXTERN __xdata _AT_(0xE6CD) volatile BYTE FLOWSTBHPERIOD    ; //Half Period of output master strobe
+EXTERN __xdata _AT_(0xE60C) volatile BYTE GPIFHOLDAMOUNT    ; //Data delay shift 
+EXTERN __xdata _AT_(0xE67D) volatile BYTE UDMACRCH          ; //CRC Upper byte
+EXTERN __xdata _AT_(0xE67E) volatile BYTE UDMACRCL          ; //CRC Lower byte
+EXTERN __xdata _AT_(0xE67F) volatile BYTE UDMACRCQUAL       ; //UDMA In only, host terminated use only
 
 
 // Debug/Test
 
-EXTERN xdata _AT_(0xE6F8) volatile BYTE DBUG              ;  // Debug
-EXTERN xdata _AT_(0xE6F9) volatile BYTE TESTCFG           ;  // Test configuration
-EXTERN xdata _AT_(0xE6FA) volatile BYTE USBTEST           ;  // USB Test Modes
-EXTERN xdata _AT_(0xE6FB) volatile BYTE CT1               ;  // Chirp Test--Override
-EXTERN xdata _AT_(0xE6FC) volatile BYTE CT2               ;  // Chirp Test--FSM
-EXTERN xdata _AT_(0xE6FD) volatile BYTE CT3               ;  // Chirp Test--Control Signals
-EXTERN xdata _AT_(0xE6FE) volatile BYTE CT4               ;  // Chirp Test--Inputs
+EXTERN __xdata _AT_(0xE6F8) volatile BYTE DBUG              ;  // Debug
+EXTERN __xdata _AT_(0xE6F9) volatile BYTE TESTCFG           ;  // Test configuration
+EXTERN __xdata _AT_(0xE6FA) volatile BYTE USBTEST           ;  // USB Test Modes
+EXTERN __xdata _AT_(0xE6FB) volatile BYTE CT1               ;  // Chirp Test--Override
+EXTERN __xdata _AT_(0xE6FC) volatile BYTE CT2               ;  // Chirp Test--FSM
+EXTERN __xdata _AT_(0xE6FD) volatile BYTE CT3               ;  // Chirp Test--Control Signals
+EXTERN __xdata _AT_(0xE6FE) volatile BYTE CT4               ;  // Chirp Test--Inputs
 
 // Endpoint Buffers
 
-EXTERN xdata _AT_(0xE740) volatile BYTE EP0BUF[64]        ;  // EP0 IN-OUT buffer
-EXTERN xdata _AT_(0xE780) volatile BYTE EP1OUTBUF[64]     ;  // EP1-OUT buffer
-EXTERN xdata _AT_(0xE7C0) volatile BYTE EP1INBUF[64]      ;  // EP1-IN buffer
-EXTERN xdata _AT_(0xF000) volatile BYTE EP2FIFOBUF[1024]  ;  // 512/1024-byte EP2 buffer (IN or OUT)
-EXTERN xdata _AT_(0xF400) volatile BYTE EP4FIFOBUF[1024]  ;  // 512 byte EP4 buffer (IN or OUT)
-EXTERN xdata _AT_(0xF800) volatile BYTE EP6FIFOBUF[1024]  ;  // 512/1024-byte EP6 buffer (IN or OUT)
-EXTERN xdata _AT_(0xFC00) volatile BYTE EP8FIFOBUF[1024]  ;  // 512 byte EP8 buffer (IN or OUT)
+EXTERN __xdata _AT_(0xE740) volatile BYTE EP0BUF[64]        ;  // EP0 IN-OUT buffer
+EXTERN __xdata _AT_(0xE780) volatile BYTE EP1OUTBUF[64]     ;  // EP1-OUT buffer
+EXTERN __xdata _AT_(0xE7C0) volatile BYTE EP1INBUF[64]      ;  // EP1-IN buffer
+EXTERN __xdata _AT_(0xF000) volatile BYTE EP2FIFOBUF[1024]  ;  // 512/1024-byte EP2 buffer (IN or OUT)
+EXTERN __xdata _AT_(0xF400) volatile BYTE EP4FIFOBUF[1024]  ;  // 512 byte EP4 buffer (IN or OUT)
+EXTERN __xdata _AT_(0xF800) volatile BYTE EP6FIFOBUF[1024]  ;  // 512/1024-byte EP6 buffer (IN or OUT)
+EXTERN __xdata _AT_(0xFC00) volatile BYTE EP8FIFOBUF[1024]  ;  // 512 byte EP8 buffer (IN or OUT)
 
 #undef EXTERN
 #undef _AT_
