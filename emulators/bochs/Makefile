# Created by: alex
# $FreeBSD$

PORTNAME=	bochs
PORTVERSION=	2.6.9
PORTREVISION=	5
PORTEPOCH=	2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	mmokhi@FreeBSD.org
COMMENT=	IA-32 (x86) PC emulator that runs DOS, Win 95, and more

LICENSE=	LGPL21

BROKEN_i386=		does not build on i386 (../cpu.h:4513:117: error: 'regparm' parameter must be between 0 and 3 inclusive)

USES=		gmake libtool:keepla pkgconfig xorg
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_alsa_asoundlib_h=no \
		ac_cv_header_ltdl_h=no
CONFIGURE_ARGS=	--disable-docbook --disable-instrumentation

SUB_FILES=	pkg-message

CFLAGS+=	-fomit-frame-pointer
CXXFLAGS+=	-fno-exceptions
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		A20_PIN ALIGN_CHECK ASSERT_CHECK AVX BUSMOUSE \
			CDROM CHAINING CLGD54XX CONF_MSRS \
			DEBUGGER DEBUGGER_GUI DEBUGGER_X86 DISASM DOCS \
			E1000 ES1370 EVEX FPU \
			GAMEPORT GDB_STUB IDLE_HACK IODEBUG \
			LARGE_RAMFILE LOGGING LONG_PHY_ADDR MEMTYPE MWAIT \
			NE2000 OPTIMIZATIONS \
			PCI PERFMON PNIC PLUGINS USB USB_OHCI USB_XHCI \
			RAW_SERIAL READLINE REPEAT_SPEED \
			SB16 SHOW_IPS SMP STATS SVM TRACE_LINK \
			VMX VOODOO X86_64 XPM
OPTIONS_DEFINE_i386=	FAST_FUNCCALL
OPTIONS_GROUP=		UI
OPTIONS_GROUP_UI=	RFB SDL1 SDL2 SVGALIB TERM VNCSERVER WXGTK X11
OPTIONS_DEFAULT=	A20_PIN ALIGN_CHECK CDROM CONF_MSRS DISASM FPU \
			LARGE_RAMFILE LOGGING NE2000 OPTIMIZATIONS PCI \
			SB16 SHOW_IPS STATS X11

A20_PIN_DESC=		Support for A20 pin
A20_PIN_CONFIGURE_ENABLE=	a20-pin
ALIGN_CHECK_DESC=	Alignment check support
ALIGN_CHECK_CONFIGURE_ENABLE=	alignment-check
ASSERT_CHECK_DESC=	BX_ASSERT checks
ASSERT_CHECK_CONFIGURE_ENABLE=	assert-checks
ASSERT_CHECK_IMPLIES=	DEBUGGER
AVX_DESC=		AVX instructions support
AVX_CONFIGURE_ENABLE=	avx
AVX_IMPLIES=		X86_64
BUSMOUSE_DESC=		Busmouse support
BUSMOUSE_CONFIGURE_ENABLE=	busmouse
CDROM_DESC=		CDROM support
CDROM_CONFIGURE_ENABLE=	cdrom
CHAINING_DESC=		Support handlers-chaining emulation speedups
CHAINING_CONFIGURE_ENABLE=	handlers-chaining
CHAINING_PREVENTS=	ASSERT_CHECK DEBUGGER DEBUGGER_GUI IODEBUG GDB_STUB \
			READLINE
CLGD54XX_DESC=		Cirrus Logic GD54xx video card
CLGD54XX_CONFIGURE_ENABLE=	clgd54xx
CONF_MSRS_DESC=		Configurable MSR registers support
CONF_MSRS_CONFIGURE_ENABLE=	configurable-msrs
DEBUGGER_DESC=		Debugger support
DEBUGGER_CONFIGURE_ENABLE=	debugger
DEBUGGER_IMPLIES=	DISASM
DEBUGGER_GUI_DESC=	GTK+ 2 GUI debugger support
DEBUGGER_GUI_USE=	GNOME=gtk20
DEBUGGER_GUI_CONFIGURE_ENABLE=	debugger-gui
DEBUGGER_GUI_IMPLIES=	DEBUGGER
DEBUGGER_X86_DESC=	X86 hardware debugger
DEBUGGER_X86_CONFIGURE_ENABLE=	x86-debugger
DISASM_DESC=		Disassemler support
DISASM_CONFIGURE_ENABLE=	disasm
E1000_DESC=		Intel(R) Gigabit Ethernet support
E1000_CONFIGURE_ENABLE=	e1000
E1000_IMPLIES=		PCI
ES1370_DESC=		ES1370 soundcard support
ES1370_CONFIGURE_ENABLE=	es1370
ES1370_IMPLIES=		PCI
EVEX_DESC=		EVEX prefix and AVX-512 extensios support
EVEX_CONFIGURE_ENABLE=	evex
EVEX_IMPLIES=		AVX
FAST_FUNCCALL_DESC=	Support for fast function calls (x86 only)
FAST_FUNCCALL_CONFIGURE_ENABLE=	fast-function-calls
FPU_DESC=		FPU emulator
FPU_CONFIGURE_ENABLE=	fpu
FPU_VARS_OFF=		WITH_CPU_LEVEL=3
GAMEPORT_DESC=		Standard PC gameport support
GAMEPORT_CONFIGURE_ENABLE=	gameport
GDB_STUB_DESC=		GDB stub support
GDB_STUB_CONFIGURE_ENABLE=	gdb-stub
GDB_STUB_PREVENTS=	ASSERT_CHECK DEBUGGER DEBUGGER_GUI IODEBUG
IDLE_HACK_DESC=		Keep Bochs from using all CPU time
IDLE_HACK_CONFIGURE_ENABLE=	idle-hack
IODEBUG_DESC=		I/O interface to debugger
IODEBUG_CONFIGURE_ENABLE=	iodebug
IODEBUG_IMPLIES=	DEBUGGER
LARGE_RAMFILE_DESC=	Large ramfile support
LARGE_RAMFILE_CONFIGURE_ENABLE=	large-ramfile
LOGGING_DESC=		Logging support
LOGGING_CONFIGURE_ENABLE=	logging
LONG_PHY_ADDR_DESC=	Support for physical address >= 32bit
LONG_PHY_ADDR_CONFIGURE_ENABLE=	long-phy-address
MEMTYPE_DESC=		Memory type calculation support
MEMTYPE_CONFIGURE_ENABLE=	memtype
MWAIT_DESC=		MONITOR/MWAIT instructions support (experimemtal)
MWAIT_CONFIGURE_ENABLE=	monitor-mwait
NE2000_DESC=		NE2000 support
NE2000_CONFIGURE_ENABLE=	ne2000
OPTIMIZATIONS_DESC=	Compile in all safe speed optimizations
OPTIMIZATIONS_CONFIGURE_ENABLE=	all-optimizations
OPTIMIZATIONS_IMPLIES=	CHAINING FAST_FUNCCALL REPEAT_SPEED TRACE_LINK
OPTIMIZATIONS_PREVENTS=	ASSERT_CHECK DEBUGGER DEBUGGER_GUI IODEBUG GDB_STUB \
			READLINE
PCI_DESC=		Intel(R) i440FX PCI support
PCI_CONFIGURE_ENABLE=	pci
PERFMON_DESC=		Hardware performance monitoring emulation (experimental)
PERFMON_CONFIGURE_ENABLE=	perfmon
PLUGINS_CONFIGURE_ENABLE=	plugins
PNIC_DESC=		PCI pseudo NIC (network card) support
PNIC_CONFIGURE_ENABLE=	pnic
PNIC_IMPLIES=		PCI
RAW_SERIAL_DESC=	Raw serial port access
RAW_SERIAL_CONFIGURE_ENABLE=	raw-serial
READLINE_DESC=		Readline support in debugger
READLINE_USES=		readline
READLINE_CONFIGURE_ENABLE=	readline
READLINE_IMPLIES=	DEBUGGER
REPEAT_SPEED_DESC=	Support repeated IO and mem copy speedups
REPEAT_SPEED_CONFIGURE_ENABLE=	repeat-speedups
RFB_DESC=		RFB protocol support (works with VNC viewer)
RFB_CONFIGURE_WITH=	rfb
SB16_DESC=		Sound Blaster 16 emulation
SB16_CONFIGURE_ENABLE=	sb16
SDL1_DESC=		Simple Direct Media Layer 1 support
SDL1_USE=		SDL=sdl
SDL1_CONFIGURE_WITH=	sdl
SDL1_PREVENTS=		SDL2
SDL2_DESC=		Simple Direct Media Layer 2 support
SDL2_USE=		SDL=sdl2
SDL2_CONFIGURE_WITH=	sdl2
SHOW_IPS_DESC=		Show IPS in status bar or log file
SHOW_IPS_CONFIGURE_ENABLE=	show-ips
SMP_DESC=		Support for SMP configurations (CPU level 6)
SMP_CONFIGURE_ENABLE=	smp
SMP_VARS=		WITH_CPU_LEVEL=6
SMP_IMPLIES=		FPU
SMP_PREVENTS=		GDB_STUB
STATS_DESC=		Statistics collection
STATS_CONFIGURE_ENABLE=	stats
SVGALIB_LIB_DEPENDS=	libvga.so:graphics/svgalib
SVGALIB_CONFIGURE_WITH=	svga
SVM_DESC=		SVM (AMD: secure virtual machine) emulation
SVM_CONFIGURE_ENABLE=	svm
SVM_VARS=		WITH_CPU_LEVEL=6
SVM_IMPLIES=		X86_64
TERM_DESC=		Use text only, console based interface
TERM_CONFIGURE_WITH=	term
TRACE_LINK_DESC=	Support trace linking speedups
TRACE_LINK_CONFIGURE_ENABLE=	trace-linking
UI_DESC=		User Interface
USB_DESC=		USB UHCI support
USB_CONFIGURE_ENABLE=	usb
USB_IMPLIES=		PCI
USB_OHCI_DESC=		USB OHCI support
USB_OHCI_CONFIGURE_ENABLE=	usb-ohci
USB_OHCI_IMPLIES=	PCI
USB_XHCI_DESC=		USB xHCI support (experimental)
USB_XHCI_CONFIGURE_ENABLE=	usb-xhci
USB_XHCI_IMPLIES=	PCI
VMX_DESC=		Virtialization extensions
VMX_VARS=		WITH_CPU_LEVEL=6
VMX_IMPLIES=		FPU
VNCSERVER_DESC=		LibVNCServer support (works with VNC viewer)
VNCSERVER_LIB_DEPENDS=	libvncserver.so:net/libvncserver
VNCSERVER_CONFIGURE_WITH=	vncsrv
VOODOO_DESC=		3dfx Voodoo Graphics emulation
VOODOO_CONFIGURE_ENABLE=	voodoo
VOODOO_IMPLIES=		PCI
WXGTK_USES=		compiler:c++11-lib
WXGTK_USE=		WX=3.0
WXGTK_CONFIGURE_WITH=	wx
WXGTK_CXXFLAGS_OFF=	-fno-rtti
WXGTK_CPPFLAGS=		$$(pkg-config --cflags gdk-2.0)
WXGTK_IMPLIES=		X11
X11_USE=		XORG=xrandr
X11_CONFIGURE_WITH=	x11
X86_64_DESC=		Support for x86-64 instructions
X86_64_CONFIGURE_ENABLE=	x86-64
X86_64_VARS=		WITH_CPU_LEVEL=6
X86_64_IMPLIES=		FPU
XPM_USE=		XORG=xpm
XPM_CONFIGURE_ENABLE=	xpm
XPM_IMPLIES=		X11

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUGGER_GUI} && empty(PORT_OPTIONS:MSDL1) && \
	empty(PORT_OPTIONS:MSDL2) && empty(PORT_OPTIONS:MX11)
IGNORE=		option DEBUGGER_GUI requires SDL1, SDL2, or X11 support
.endif

.if ${PORT_OPTIONS:MGAMEPORT} && empty(PORT_OPTIONS:MES1370) && \
	empty(PORT_OPTIONS:MSB16)
IGNORE=		option GAMEPORT requires SB16 or ES1370 soundcard support
.endif

.if ${PORT_OPTIONS:MVMX} && ${PORT_OPTIONS:MX86_64}
CONFIGURE_ARGS+=--enable-vmx=2
.endif

.if ${PORT_OPTIONS:MVMX} && empty(PORT_OPTIONS:MX86_64)
CONFIGURE_ARGS+=--enable-vmx=1
.endif

.if defined(WITH_CPU_LEVEL)
.if ${WITH_CPU_LEVEL} < 3 || ${WITH_CPU_LEVEL} > 6
IGNORE=		cannot install: WITH_CPU_LEVEL must be an integer value between 3 and 6
.endif
CONFIGURE_ARGS+=--enable-cpu-level=${WITH_CPU_LEVEL}
.endif

pre-everything::
.if !defined(WITH_CPU_LEVEL)
	@${ECHO_CMD}
	@${ECHO_CMD} "If you want to change the processor level to emulate (default is 5, aka Pentium), set WITH_CPU_LEVEL to the desired value. Choices are 3, 4, 5 and 6 which mean target 386, 486, Pentium or Pentium Pro emulation." | ${FMT}
	@${ECHO_CMD}
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		'/DEFAULT_GUI=/s|x11|nogui|' \
		 ${WRKSRC}/configure
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
	@${REINPLACE_CMD} -Ee \
		's|(@GUI_.+FLAGS@)$$|\1 @CPPFLAGS@|' \
		 ${WRKSRC}/bx_debug/Makefile.in
	@${REINPLACE_CMD} -e \
		's|/usr/local/share/bochs|${DATADIR}|; \
		 s|/usr/local/share/doc/bochs|${DOCSDIR}|' \
		 ${WRKSRC}/doc/docbook/user/user.dbk ${WRKSRC}/doc/man/*.[15]
	@${REINPLACE_CMD} -e 's|</usr/include/|<|' \
		 ${WRKSRC}/gui/svga.cc
	@${REINPLACE_CMD} -Ee \
		's|(^LOCAL_CXXFLAGS.+=)|\1 @CPPFLAGS@|; \
		 s|(-lvgagl)$$|\1 @LDFLAGS@|' \
		 ${WRKSRC}/gui/Makefile.in

post-build:
	@${LN} -sf .bochsrc ${WRKSRC}/bochsrc-sample.txt

post-install:
.for f in bochs bxhub bximage
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor

post-install-PLUGINS-on:
	@${FIND} ${STAGEDIR}${PREFIX}/lib/bochs -name "libbx_*.so*" \
		-type f -print0 | ${XARGS} -0 ${STRIP_CMD}
	@${FIND} ${STAGEDIR}${PREFIX}/lib/bochs ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${PREFIX}/lib/bochs -type d -empty | ${SORT} -r | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,@dir ,' >> ${TMPPLIST}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in CHANGES README TODO bochsrc-sample.txt
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${DOCSDIR})
.endfor
	(cd ${WRKSRC}/docs-html && ${INSTALL_DATA} *.txt \
		${STAGEDIR}${DOCSDIR})
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	(cd ${WRKSRC}/docs-html && ${INSTALL_DATA} *.html \
		${STAGEDIR}${DOCSDIR}/html)

.include <bsd.port.mk>
