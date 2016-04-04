# Created by: alex
# $FreeBSD$

PORTNAME=	bochs
PORTVERSION=	2.6.7
PORTEPOCH=	2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IA-32 (x86) PC emulator that runs DOS, Win 95, and more

LICENSE=	LGPL21

USES=		gmake libtool:keepla pkgconfig
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	ac_cv_header_alsa_asoundlib_h=no
CONFIGURE_ARGS=	--disable-docbook --disable-instrumentation

SUB_FILES=	pkg-message

CFLAGS+=	-fno-exceptions -fomit-frame-pointer
CXXFLAGS+=	-fno-rtti
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=		A20_PIN ALIGN_CHECK ASSERT_CHECK AVX BUSMOUSE \
			CDROM CHAINING CLGD54XX CONF_MSRS \
			DISASM DOCS \
			E1000 ES1370 EVEX FPU \
			GAMEPORT IDLE_HACK IODEBUG \
			LARGE_RAMFILE LOGGING LONG_PHY_ADDR \
			MWAIT NE2000 OPTIMIZATIONS PCI PLUGINS PNIC \
			RAW_SERIAL READLINE REPEAT_SPEED RFB \
			SB16 SDL SHOW_IPS SMP SVGALIB SVM \
			TERM TRACE_LINK \
			USB USB_OHCI USB_XHCI \
			VMX VNCSERVER VOODOO WXGTK X11 X86_64 XPM
OPTIONS_DEFINE_i386=	FAST_FUNCCALL
OPTIONS_RADIO=		DEBUG
OPTIONS_RADIO_DEBUG=	DEBUGGER GDB_STUB
OPTIONS_DEFAULT=	A20_PIN ALIGN_CHECK CDROM CONF_MSRS DISASM FPU \
			LOGGING NE2000 OPTIMIZATIONS SB16 X11

A20_PIN_DESC=		Enable support for A20 pin
A20_PIN_CONFIGURE_ENABLE=	a20-pin
ALIGN_CHECK_DESC=	Enable alignment check support
ALIGN_CHECK_CONFIGURE_ENABLE=	alignment-check
ASSERT_CHECK_DESC=	Enable BX_ASSERT checks
ASSERT_CHECK_CONFIGURE_ENABLE=	assert-checks
AVX_DESC=		Enable AVX instructions support
AVX_CONFIGURE_ENABLE=	avx
BUSMOUSE_DESC=		Enable Busmouse support
BUSMOUSE_CONFIGURE_ENABLE=	busmouse
CDROM_DESC=		Enable CDROM support
CDROM_CONFIGURE_ENABLE=	cdrom
CHAINING_DESC=		Enable handlers-chaining emulation speedups
CHAINING_CONFIGURE_ENABLE=	handlers-chaining
CLGD54XX_DESC=		Enable Cirrus Logic GD54xx video card
CLGD54XX_CONFIGURE_ENABLE=	clgd54xx
CONF_MSRS_DESC=		Enable configurable MSR registers support
CONF_MSRS_CONFIGURE_ENABLE=	configurable-msrs
DEBUG_DESCR=		Enable Debugging, select this and one of DEBUGGER or GDB_STUB (or none)
DEBUGGER_DESC=		Enable debugger support
DEBUGGER_CONFIGURE_ENABLE=	debugger
DEBUGGER_X86_DESC=	Enable x86 hardware debugger
DEBUGGER_X86_CONFIGURE_ENABLE=	x86-debugger
DISASM_DESC=		Enable disassemler support
DISASM_CONFIGURE_ENABLE=	disasm
E1000_DESC=		Enable Intel(R) Gigabit Ethernet support
E1000_CONFIGURE_ENABLE=		e1000
ES1370_DESC=		Enable ES1370 soundcard support
ES1370_CONFIGURE_ENABLE=	es1370
EVEX_DESC=		Enable EVEX prefix and AVX-512 extensios support
EVEX_CONFIGURE_ENABLE=	evex
FAST_FUNCCALL_DESC=	Enable fast function calls support (x86 only)
FAST_FUNCCALL_CONFIGURE_ENABLE=	fast-function-calls
FPU_DESC=		Enable FPU emulator
FPU_CONFIGURE_ENABLE=		fpu
GAMEPORT_DESC=		Enable standard PC gameport support
GAMEPORT_CONFIGURE_ENABLE=	gameport
GDB_STUB_DESC=		Enable GDB stub support
GDB_STUB_CONFIGURE_ENABLE=	gdb-stub
IDLE_HACK_DESC=		Keep Bochs from using all CPU time
IDLE_HACK_CONFIGURE_ENABLE=	idle-hack
IODEBUG_DESC=		Enable I/O interface to debugger
IODEBUG_CONFIGURE_ENABLE=	iodebug
LARGE_RAMFILE_DESC=	Enable large ramfile support
LARGE_RAMFILE_CONFIGURE_ENABLE=	large-ramfile
LOGGING_DESC=		Enable logging
LOGGING_CONFIGURE_ENABLE=	logging
LONG_PHY_ADDR_DESC=	Enable support for physical address >= 32bit
LONG_PHY_ADDR_CONFIGURE_ENABLE=	long-phy-address
MWAIT_DESC=		Enable experimental MONITOR/MWAIT support
MWAIT_CONFIGURE_ENABLE=		monitor-mwait
NE2000_DESC=		Enable ne2000 support
NE2000_CONFIGURE_ENABLE=	ne2000
OPTIMIZATIONS_DESC=	Enable all safe speed optimizations
OPTIMIZATIONS_CONFIGURE_ENABLE=	all-optimizations
PCI_DESC=		Enable i440FX PCI support
PCI_CONFIGURE_ENABLE=		pci
PLUGINS_DESC=		Enable building dynamic loadable plugins
PLUGINS_CONFIGURE_ENABLE=	plugins
PNIC_DESC=		Enable PCI pseudo NIC (network card) support
PNIC_CONFIGURE_ENABLE=		pnic
RAW_SERIAL_DESC=	Use raw serial port access
RAW_SERIAL_CONFIGURE_ENABLE=	raw-serial
READLINE_DESC=		Enable readline support in debugger
READLINE_USES=		readline
READLINE_CONFIGURE_ENABLE=	readline
REPEAT_SPEED_DESC=	Enable repeated IO and mem copy speedups
REPEAT_SPEED_CONFIGURE_ENABLE=	repeat-speedups
RFB_DESC=		Use RFB protocol (works with VNC viewer)
RFB_CONFIGURE_WITH=	rfb
SB16_DESC=		Enable Sound Blaster 16 emulation
SB16_CONFIGURE_ENABLE=	sb16
SDL_USE=		SDL=sdl
SDL_CONFIGURE_WITH=	sdl
SHOW_IPS_DESC=		Enable logging of measured IPS
SHOW_IPS_CONFIGURE_ENABLE=	show-ips
SMP_DESC=		Enable SMP simulation support (CPU level 6)
SMP_CONFIGURE_ENABLE=	smp
SVGALIB_LIB_DEPENDS=	libvga.so:graphics/svgalib
SVGALIB_CONFIGURE_WITH=	svga
SVM_DESC=		Enable SVM (AMD: secure virtual machine) emulation
SVM_CONFIGURE_ENABLE=	svm
TERM_DESC=		Use text only, console based interface
TERM_CONFIGURE_WITH=	term
TRACE_LINK_DESC=	Enable trace linking speedups
TRACE_LINK_CONFIGURE_ENABLE=	trace-linking
USB_DESC=		Enable USB UHCI support
USB_CONFIGURE_ENABLE=	usb
USB_OHCI_DESC=		Enable USB OHCI support
USB_OHCI_CONFIGURE_ENABLE=	usb-ohci
USB_XHCI_DESC=		Enable experimental USB xHCI support
USB_XHCI_CONFIGURE_ENABLE=	usb-xhci
VMX_DESC=		Enable Virtialization extensions
VNCSERVER_DESC= 		Use LibVNCServer (works with VNC viewer)
VNCSERVER_LIB_DEPENDS=	libvncserver.so:net/libvncserver
VNCSERVER_CONFIGURE_WITH=	vncsrv
VOODOO_DESC=		Enable 3dfx Voodoo Graphics emulation
VOODOO_CONFIGURE_ENABLE=	voodoo
WXGTK_USE=		WX=2.8
WXGTK_CONFIGURE_WITH=	wx
WXGTK_CONFIGURE_OFF=	--disable-debugger-gui
X11_USE=		XORG=xrandr
X11_CONFIGURE_WITH=	x11
X86_64_DESC=		Enable x86-64 instructions support
X86_64_CONFIGURE_ENABLE=	x86-64
XPM_USE=		XORG=xpm
XOM_CONFIGURE_ENABE=	xpm

.include <bsd.port.options.mk>

.if empty(PORT_OPTIONS:MTERM) && empty(PORT_OPTIONS:MWXGTK) && empty(PORT_OPTIONS:MX11)
CONFIGURE_ARGS+=--with-nogui
.endif

.if ! ${PORT_OPTIONS:MFPU}
WITH_CPU_LEVEL=	3
.endif

.if ${PORT_OPTIONS:MSMP}
WITH_CPU_LEVEL=	6
.endif

.if ${PORT_OPTIONS:MVMX} && ${PORT_OPTIONS:MX86_64}
CONFIGURE_ARGS+=--enable-vmx=2
WITH_CPU_LEVEL=	6
.endif

.if ${PORT_OPTIONS:MVMX} && empty(PORT_OPTIONS:MX86_64)
CONFIGURE_ARGS+=--enable-vmx=1
WITH_CPU_LEVEL=	6
.endif

.if ${PORT_OPTIONS:MX86_64}
WITH_CPU_LEVEL=	6
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

.if ${PORT_OPTIONS:ME1000} && empty(PORT_OPTIONS:MPCI)
IGNORE=		E1000 network adapter support requires PCI support
.endif

.if ${PORT_OPTIONS:MES1370} && empty(PORT_OPTIONS:MGAMEPORT)
IGNORE=		ES1370 soundcard support requires GAMEPORT support
.endif

.if ${PORT_OPTIONS:MES1370} && empty(PORT_OPTIONS:MPCI)
IGNORE=		ES1370 soundcard support requires PCI support
.endif

.if ${PORT_OPTIONS:MEVEX} && empty(PORT_OPTIONS:MAVX)
IGNORE=		EVEX instructions support requires AVX support
.endif

.if ${PORT_OPTIONS:MPNIC} && empty(PORT_OPTIONS:MPCI)
IGNORE=		PCI pseudo NIC support requires PCI support
.endif

.if ${PORT_OPTIONS:MVOODOO} && empty(PORT_OPTIONS:MPCI)
IGNORE=		3dfx Voodoo Graphics emulation requires PCI support
.endif

.if ${PORT_OPTIONS:MAVX} && empty(PORT_OPTIONS:MX86_64)
IGNORE=		AVX instructions support requires X86-64 support
.endif

.if ${PORT_OPTIONS:MSVM} && empty(PORT_OPTIONS:MX86_64)
IGNORE=		SVM emulation requires X86-64 support
.endif

.if ${PORT_OPTIONS:MXPM} && empty(PORT_OPTIONS:MX11)
IGNORE=		XPM support requires X11 support
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

post-build:
	@${LN} -sf .bochsrc ${WRKSRC}/bochsrc-sample.txt

post-install:
.for f in bochs bximage
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${f}
.endfor
.if ${PORT_OPTIONS:MPLUGINS}
	@${FIND} ${STAGEDIR}${PREFIX}/lib/bochs ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${PREFIX}/lib/bochs -type d -empty | ${SORT} -r | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,@dir ,' >> ${TMPPLIST}
.endif
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
