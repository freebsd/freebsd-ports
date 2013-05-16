# Created by: alex
# $FreeBSD$

PORTNAME=	bochs
PORTVERSION=	2.6.1
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IA-32 (x86) PC emulator that runs DOS, Win 95, and more

LICENSE=	LGPL21

OPTIONS_DEFINE=	A20_PIN ALIGN_CHECK ASSERT_CHECK AVX \
		CDROM CHAINING CLGD54XX CONF_MSRS CPP_SUFX \
		DISASM DOCS \
		E1000 ES1370 FPU \
		GAMEPORT IDLE_HACK IODEBUG \
		LARGE_RAMFILE LOGGING LONG_PHY_ADDR \
		MWAIT NE2000 OPTIMIZATIONS PCI PLUGINS PNIC \
		RAW_SERIAL READLINE REPEAT_SPEED RFB \
		SB16 SDL SHOW_IPS SMP SVGALIB SVM TERM USB USB_OHCI USB_XHCI \
		VMX VOODOO WXGTK X11 X86_64 XPM
OPTIONS_DEFINE_i386=	FAST_FUNCCALL
OPTIONS_RADIO=	DEBUG
OPTIONS_RADIO_DEBUG=	DEBUGGER GDB_STUB
OPTIONS_DEFAULT=A20_PIN ALIGN_CHECK CDROM CONF_MSRS DISASM FPU LOGGING \
		NE2000 OPTIMIZATIONS SB16 X11

A20_PIN_DESC=	Enable support for A20 pin
ALIGN_CHECK_DESC=	Enable alignment check support
ASSERT_CHECK_DESC=	Enable BX_ASSERT checks
AVX_DESC=	Enable AVX instructions support
CDROM_DESC=	Enable CDROM support
CHAINING_DESC=	Enable handlers-chaining emulation speedups
CLGD54XX_DESC=	Enable Cirrus Logic GD54xx video card
CONF_MSRS_DESC=	Enable configurable MSR registers support
CPP_SUFX_DESC=	Use .cpp as C++ suffix
DEBUG_DESCR=	Enable Debugging, select this and one of DEBUGGER or GDB_STUB (or none)
DEBUGGER_DESC=	Enable debugger support
DEBUGGER_X86_DESC=	Enable x86 hardware debugger
DISASM_DESC=	Enable disassemler support
E1000_DESC=	Enable Intel(R) Gigabit Ethernet support
ES1370_DESC=	Enable ES1370 soundcard support
FAST_FUNCCALL_DESC=	Enable fast function calls support (x86 only)
FPU_DESC=	Enable FPU emulator
GAMEPORT_DESC=	Enable standard PC gameport support
GDB_STUB_DESC=	Enable GDB stub support
IDLE_HACK_DESC=	Keep Bochs from using all CPU time
IODEBUG_DESC=	Enable I/O interface to debugger
LARGE_RAMFILE_DESC=	Enable large ramfile support
LOGGING_DESC=	Enable logging
LONG_PHY_ADDR_DESC=	Enable support for physical address >= 32bit
MWAIT_DESC=	Enable experimental MONITOR/MWAIT support
NE2000_DESC=	Enable ne2000 support
OPTIMIZATIONS_DESC=	Enable all safe speed optimizations
PCI_DESC=	Enable i440FX PCI support
PLUGINS_DESC=	Enable building dynamic loadable plugins
PNIC_DESC=	Enable PCI pseudo NIC (network card) support
RAW_SERIAL_DESC=	Use raw serial port access
READLINE_DESC=	Enable readline support in debugger
REPEAT_SPEED_DESC=	Enable repeated IO and mem copy speedups
RFB_DESC=	Enable VNC server support in display
SB16_DESC=	Enable Sound Blaster 16 emulation
SHOW_IPS_DESC=	Enable logging of measured IPS
SMP_DESC=	Enable SMP simulation support (CPU level 6)
SVM_DESC=	Enable SVM (AMD: secure virtual machine) emulation
TERM_DESC=	Use text only, console based interface
USB_DESC=	Enable USB UHCI support
USB_OHCI_DESC=	Enable USB OHCI support
USB_XHCI_DESC=	Enable experimental USB xHCI support
VMX_DESC=	Enable Virtialization extensions
VOODOO_DESC=	Enable 3dfx Voodoo Graphics emulation
X86_64_DESC=	Enable AMD x86-64 support

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	ac_cv_header_alsa_asoundlib_h=no
CONFIGURE_ARGS=	--disable-docbook --disable-instrumentation
MAKE_JOBS_SAFE=	yes

CFLAGS+=	-fno-exceptions -fomit-frame-pointer ${CPPFLAGS}
CXXFLAGS+=	-fno-rtti
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

MANCOMPRESSED=	yes
MAN1=		bochs.1 bochs-dlx.1 bxcommit.1 bximage.1
MAN5=		bochsrc.5

SUB_FILES=	pkg-message

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MTERM) && empty(PORT_OPTIONS:MWXGTK) && empty(PORT_OPTIONS:MX11)
CONFIGURE_ARGS+=--with-nogui
.endif

.if ${PORT_OPTIONS:MA20_PIN}
CONFIGURE_ARGS+=--enable-a20-pin
.else
CONFIGURE_ARGS+=--disable-a20-pin
.endif

.if ${PORT_OPTIONS:MALIGN_CHECK}
CONFIGURE_ARGS+=--enable-alignment-check
.else
CONFIGURE_ARGS+=--disable-alignment-check
.endif

.if ${PORT_OPTIONS:MASSERT_CHECK}
CONFIGURE_ARGS+=--enable-assert-checks
.else
CONFIGURE_ARGS+=--disable-assert-checks
.endif

.if ${PORT_OPTIONS:MAVX}
CONFIGURE_ARGS+=--enable-avx
.else
CONFIGURE_ARGS+=--disable-avx
.endif

.if ${PORT_OPTIONS:MCDROM}
CONFIGURE_ARGS+=--enable-cdrom
.else
CONFIGURE_ARGS+=--disable-cdrom
.endif

.if ${PORT_OPTIONS:MCHAINING}
CONFIGURE_ARGS+=--enable-handlers-chaining
.else
CONFIGURE_ARGS+=--disable-handlers-chaining
.endif

.if ${PORT_OPTIONS:MCLGD54XX}
CONFIGURE_ARGS+=--enable-clgd54xx
.else
CONFIGURE_ARGS+=--disable-clgd54xx
.endif

.if ${PORT_OPTIONS:MCONF_MSRS}
CONFIGURE_ARGS+=--enable-configurable-msrs
.else
CONFIGURE_ARGS+=--disable-configurable-msrs
.endif

.if ${PORT_OPTIONS:MCPP_SUFX}
CONFIGURE_ARGS+=--enable-cpp
.else
CONFIGURE_ARGS+=--disable-cpp
.endif

.if ${PORT_OPTIONS:MDEBUGGER}
CONFIGURE_ARGS+=--enable-debugger
.else
CONFIGURE_ARGS+=--disable-debugger
.endif

.if ${PORT_OPTIONS:MDEBUGGER_X86}
CONFIGURE_ARGS+=--enable-x86-debugger
.else
CONFIGURE_ARGS+=--disable-x86-debugger
.endif

.if ${PORT_OPTIONS:MDISASM}
CONFIGURE_ARGS+=--enable-disasm
.else
CONFIGURE_ARGS+=--disable-disasm
.endif

.if ${PORT_OPTIONS:ME1000}
CONFIGURE_ARGS+=--enable-e1000
.else
CONFIGURE_ARGS+=--disable-e1000
.endif

.if ${PORT_OPTIONS:MES1370}
CONFIGURE_ARGS+=--enable-es1370
.else
CONFIGURE_ARGS+=--disable-es1370
.endif

.if ${PORT_OPTIONS:MFAST_FUNCCALL}
CONFIGURE_ARGS+=--enable-fast-function-calls
.else
CONFIGURE_ARGS+=--disable-fast-function-calls
.endif

.if ${PORT_OPTIONS:MFPU}
CONFIGURE_ARGS+=--enable-fpu
.else
CONFIGURE_ARGS+=--disable-fpu
WITH_CPU_LEVEL=	3
.endif

.if ${PORT_OPTIONS:MGAMEPORT}
CONFIGURE_ARGS+=--enable-gameport
.else
CONFIGURE_ARGS+=--disable-gameport
.endif

.if ${PORT_OPTIONS:MGDB_STUB}
CONFIGURE_ARGS+=--enable-gdb-stub
.else
CONFIGURE_ARGS+=--disable-gdb-stub
.endif

.if ${PORT_OPTIONS:MIDLE_HACK}
CONFIGURE_ARGS+=--enable-idle-hack
.else
CONFIGURE_ARGS+=--disable-idle-hack
.endif

.if ${PORT_OPTIONS:MIODEBUG}
CONFIGURE_ARGS+=--enable-iodebug
.else
CONFIGURE_ARGS+=--disable-iodebug
.endif

.if ${PORT_OPTIONS:MLARGE_RAMFILE}
CONFIGURE_ARGS+=--enable-large-ramfile
.else
CONFIGURE_ARGS+=--disable-large-ramfile
.endif

.if ${PORT_OPTIONS:MLOGGING}
CONFIGURE_ARGS+=--enable-logging
.else
CONFIGURE_ARGS+=--disable-logging
.endif

.if ${PORT_OPTIONS:MLONG_PHY_ADDR}
CONFIGURE_ARGS+=--enable-long-phy-address
.else
CONFIGURE_ARGS+=--disable-long-phy-address
.endif

.if ${PORT_OPTIONS:MMWAIT}
CONFIGURE_ARGS+=--enable-monitor-mwait
.else
CONFIGURE_ARGS+=--disable-monitor-mwait
.endif

.if ${PORT_OPTIONS:MNE2000}
CONFIGURE_ARGS+=--enable-ne2000
.else
CONFIGURE_ARGS+=--disable-ne2000
.endif

.if ${PORT_OPTIONS:MOPTIMIZATIONS}
CONFIGURE_ARGS+=--enable-all-optimizations
.else
CONFIGURE_ARGS+=--disable-all-optimizations
.endif

.if ${PORT_OPTIONS:MPCI}
CONFIGURE_ARGS+=--enable-pci
.else
CONFIGURE_ARGS+=--disable-pci
.endif

.if ${PORT_OPTIONS:MPLUGINS}
CONFIGURE_ARGS+=--enable-plugins
.else
CONFIGURE_ARGS+=--disable-plugins
.endif

.if ${PORT_OPTIONS:MPNIC}
CONFIGURE_ARGS+=--enable-pnic
.else
CONFIGURE_ARGS+=--disable-pnic
.endif

.if ${PORT_OPTIONS:MRAW_SERIAL}
CONFIGURE_ARGS+=--enable-raw-serial
.else
CONFIGURE_ARGS+=--disable-raw-serial
.endif

.if ${PORT_OPTIONS:MREADLINE}
USES+=		readline
CONFIGURE_ARGS+=--enable-readline
.else
CONFIGURE_ARGS+=--disable-readline
.endif

.if ${PORT_OPTIONS:MREPEAT_SPEED}
CONFIGURE_ARGS+=--enable-repeat-speedups
.else
CONFIGURE_ARGS+=--disable-repeat-speedups
.endif

.if ${PORT_OPTIONS:MRFB}
CONFIGURE_ARGS+=--with-rfb
.else
CONFIGURE_ARGS+=--without-rfb
.endif

.if ${PORT_OPTIONS:MSB16}
CONFIGURE_ARGS+=--enable-sb16
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
CONFIGURE_ARGS+=--with-sdl
.endif

.if ${PORT_OPTIONS:MSHOW_IPS}
CONFIGURE_ARGS+=--enable-show-ips
.else
CONFIGURE_ARGS+=--disable-show-ips
.endif

.if ${PORT_OPTIONS:MSMP}
CONFIGURE_ARGS+=--enable-smp
WITH_CPU_LEVEL=	6
.endif

.if ${PORT_OPTIONS:MSVGALIB}
LIB_DEPENDS+=	vga:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--with-svga
.else
CONFIGURE_ARGS+=--without-svga
.endif

.if ${PORT_OPTIONS:MSVM}
CONFIGURE_ARGS+=--enable-svm
.else
CONFIGURE_ARGS+=--disable-svm
.endif

.if ${PORT_OPTIONS:MTERM}
CONFIGURE_ARGS+=--with-term
.else
CONFIGURE_ARGS+=--without-term
.endif

.if ${PORT_OPTIONS:MUSB}
CONFIGURE_ARGS+=--enable-usb
.else
CONFIGURE_ARGS+=--disable-usb
.endif

.if ${PORT_OPTIONS:MUSB_OHCI}
CONFIGURE_ARGS+=--enable-usb-ohci
.else
CONFIGURE_ARGS+=--disable-usb-ohci
.endif

.if ${PORT_OPTIONS:MUSB_XHCI}
CONFIGURE_ARGS+=--enable-usb-xhci
.else
CONFIGURE_ARGS+=--disable-usb-xhci
.endif

.if ${PORT_OPTIONS:MVMX} && ${PORT_OPTIONS:MX86_64}
CONFIGURE_ARGS+=--enable-vmx=2
WITH_CPU_LEVEL=	6
.endif

.if ${PORT_OPTIONS:MVMX} && empty(PORT_OPTIONS:MX86_64)
CONFIGURE_ARGS+=--enable-vmx=1
WITH_CPU_LEVEL=	6
.endif

.if ${PORT_OPTIONS:MVOODOO}
CONFIGURE_ARGS+=--enable-voodoo
.else
CONFIGURE_ARGS+=--disable-voodoo
.endif

.if ${PORT_OPTIONS:MWXGTK}
USE_WX=		2.4+
CONFIGURE_ARGS+=--with-wx
.else
CONFIGURE_ARGS+=--disable-debugger-gui
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	xrandr
CONFIGURE_ARGS+=--with-x11
.endif

.if ${PORT_OPTIONS:MX86_64}
CONFIGURE_ARGS+=--enable-x86-64
WITH_CPU_LEVEL=	6
.else
CONFIGURE_ARGS+=--disable-x86-64
.endif

.if ${PORT_OPTIONS:MXPM} && ${PORT_OPTIONS:MX11}
USE_XORG+=	xpm
CONFIGURE_ARGS+=--enable-xpm
.else
CONFIGURE_ARGS+=--disable-xpm
.endif

.if defined(WITH_CPU_LEVEL)
.if ${WITH_CPU_LEVEL} < 3 || ${WITH_CPU_LEVEL} > 6
IGNORE=		can not install: WITH_CPU_LEVEL must be an integer value between 3 and 6
.endif
CONFIGURE_ARGS+=--enable-cpu-level=${WITH_CPU_LEVEL}
.endif

.if ${PORT_OPTIONS:MGDB_STUB} && ${PORT_OPTIONS:MSMP}
IGNORE=		GDB_STUB is incompatible with multiprocessor
.endif

.if empty(PORT_OPTIONS:MGAMEPORT) && ${PORT_OPTIONS:MES1370}
IGNORE=		ES1370 soundcard support requires GAMEPORT support
.endif

.if empty(PORT_OPTIONS:MPCI) && ${PORT_OPTIONS:MES1370}
IGNORE=		ES1370 soundcard support requires PCI support
.endif

.if empty(PORT_OPTIONS:MPCI) && ${PORT_OPTIONS:MVOODOO}
IGNORE=		3dfx Voodoo Graphics emulation requires PCI support
.endif

.if empty(PORT_OPTIONS:MX86_64) && ${PORT_OPTIONS:MAVX}
IGNORE=		AVX instructions support requires X86-64 support
.endif

.if empty(PORT_OPTIONS:MX86_64) && ${PORT_OPTIONS:MSVM}
IGNORE=		SVM emulation requires X86-64 support
.endif

pre-everything::
.if !defined(WITH_CPU_LEVEL)
	@${ECHO_CMD}
	@${ECHO_CMD} "If you want to change the processor level to emulate (default is 5, aka Pentium), set WITH_CPU_LEVEL to the desired value. Choices are 3, 4, 5 and 6 which mean target 386, 486, Pentium or Pentium Pro emulation." | ${FMT}
	@${ECHO_CMD}
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|$$BXSHARE/|${DATADIR}/|; \
		 s|^#clock: sync=none|clock: sync=realtime|; \
		 s|^log: .+|log: /dev/null|; \
		 s|^panic: .+|panic: action=ask|; \
		 s|^parport1: .+|#&|' \
		 ${WRKSRC}/.bochsrc
	@${REINPLACE_CMD} -Ee \
		's|install_share install_doc|install_share|; \
		 s|(^sharedir.+=).+|\1 ${DATADIR}|; \
		 s|(^docdir.+=).+|\1 ${DOCSDIR}|' \
		 ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/usr/local/share/bochs|${DATADIR}|; \
		 s|/usr/local/share/doc/bochs|${DOCSDIR}|' \
		 ${WRKSRC}/doc/docbook/user/user.dbk ${WRKSRC}/doc/man/*.[15]
	@${REINPLACE_CMD} -Ee 's|/usr/(include/vga\.h)|${LOCALBASE}/\1|' \
		 ${WRKSRC}/gui/svga.cc
	@${REINPLACE_CMD} -Ee \
		's|(^LOCAL_CXXFLAGS.+=)|\1 @CPPFLAGS@|; \
		 s|(-lvgagl)$$|\1 @LDFLAGS@|' \
		 ${WRKSRC}/gui/Makefile.in

post-install:
.if ${PORT_OPTIONS:MPLUGINS}
	@${FIND} ${PREFIX}/lib/bochs ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/lib/bochs -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/CHANGES ${DOCSDIR}/CHANGES
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/README
	@${INSTALL_DATA} ${WRKSRC}/TODO ${DOCSDIR}/TODO
	@${INSTALL_DATA} ${WRKSRC}/.bochsrc ${DOCSDIR}/bochsrc-sample.txt
	@${INSTALL_DATA} ${WRKSRC}/docs-html/*.txt ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	@${INSTALL_DATA} ${WRKSRC}/docs-html/*.html ${DOCSDIR}/html
.endif
	@${ECHO_CMD}; ${CAT} ${PKGMESSAGE}; ${ECHO_CMD}

.include <bsd.port.mk>
