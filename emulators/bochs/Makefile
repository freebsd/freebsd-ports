# Created by: alex
# $FreeBSD$

PORTNAME=	bochs
PORTVERSION=	2.6.2
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
X86_64_DESC=	Enable x86-64 instructions support

USES=		gmake pkgconfig
USE_AUTOTOOLS=	libtool
CONFIGURE_ENV=	ac_cv_header_alsa_asoundlib_h=no
CONFIGURE_ARGS=	--disable-docbook --disable-instrumentation

CFLAGS+=	-fno-exceptions -fomit-frame-pointer ${CPPFLAGS}
CXXFLAGS+=	-fno-rtti
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

SUB_FILES=	pkg-message

A20_PIN_CONFIGURE_ENABLE=	a20-pin

ALIGN_CHECK_CONFIGURE_ENABLE=	alignment-check

ASSERT_CHECK_CONFIGURE_ENABLE=	assert-checks

AVX_CONFIGURE_ENABLE=	avx

CDROM_CONFIGURE_ENABLE=	cdrom

CHAINING_CONFIGURE_ENABLE=	handlers-chaining

CLGD54XX_CONFIGURE_ENABLE=	clgd54xx

CONF_MSRS_CONFIGURE_ENABLE=	configurable-msrs

CPP_SUFX_CONFIGURE_ENABLE=	cpp

DEBUGGER_CONFIGURE_ENABLE=	debugger

DEBUGGER_X86_CONFIGURE_ENABLE=	x86-debugger

DISASM_CONFIGURE_ENABLE=	disasm

E1000_CONFIGURE_ENABLE=		e1000

ES1370_CONFIGURE_ENABLE=	es1370

FAST_FUNCCALL_CONFIGURE_ENABLE=	fast-function-calls

FPU_CONFIGURE_ENABLE=		fpu

GAMEPORT_CONFIGURE_ENABLE=	gameport

GDB_STUB_CONFIGURE_ENABLE=	gdb-stub

IDLE_HACK_CONFIGURE_ENABLE=	idle-hack

IODEBUG_CONFIGURE_ENABLE=	iodebug

LARGE_RAMFILE_CONFIGURE_ENABLE=	large-ramfile

LOGGING_CONFIGURE_ENABLE=	logging

LONG_PHY_ADDR_CONFIGURE_ENABLE=	long-phy-address

MWAIT_CONFIGURE_ENABLE=		monitor-mwait

NE2000_CONFIGURE_ENABLE=	ne2000

OPTIMIZATIONS_CONFIGURE_ENABLE=	all-optimizations

PCI_CONFIGURE_ENABLE=		pci

PLUGINS_CONFIGURE_ENABLE=	plugins

PNIC_CONFIGURE_ENABLE=		pnic

RAW_SERIAL_CONFIGURE_ENABLE=	raw-serial

READLINE_USES=			readline
READLINE_CONFIGURE_ENABLE=	readline

REPEAT_SPEED_CONFIGURE_ENABLE=	repeat-speedups

RFB_CONFIGURE_WITH=		rfb

SB16_CONFIGURE_ENABLE=		sb16

SDL_USE=			SDL=sdl
SDL_CONFIGURE_WITH=		sdl

SHOW_IPS_CONFIGURE_ENABLE=	show-ips

SMP_CONFIGURE_ENABLE=		smp

SVGALIB_LIB_DEPENDS=		libvga.so:${PORTSDIR}/graphics/svgalib
SVGALIB_CONFIGURE_WITH=		svga

SVM_CONFIGURE_ENABLE=		svm

TERM_CONFIGURE_WITH=		term

USB_CONFIGURE_ENABLE=		usb

USB_OHCI_CONFIGURE_ENABLE=	usb-ohci

USB_XHCI_CONFIGURE_ENABLE=	usb-xhci

VOODOO_CONFIGURE_ENABLE=	voodoo

WXGTK_USE=			WX=2.4+
WXGTK_CONFIGURE_WITH=		wx
WXGTK_CONFIGURE_OFF=		--disable-debugger-gui

X11_USE=			XORG=xrandr
X11_CONFIGURE_WITH=		x11

X86_64_CONFIGURE_ENABLE=	x86-64

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

.if ${PORT_OPTIONS:MES1370} && empty(PORT_OPTIONS:MGAMEPORT)
IGNORE=		ES1370 soundcard support requires GAMEPORT support
.endif

.if ${PORT_OPTIONS:MES1370} && empty(PORT_OPTIONS:MPCI)
IGNORE=		ES1370 soundcard support requires PCI support
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
	@${FIND} ${STAGEDIR}${PREFIX}/lib/bochs ! -type d | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${STAGEDIR}${PREFIX}/lib/bochs -type d | ${SORT} -r | \
		${SED} 's,^${STAGEDIR}${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}/CHANGES
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}/README
	${INSTALL_DATA} ${WRKSRC}/TODO ${STAGEDIR}${DOCSDIR}/TODO
	${INSTALL_DATA} ${WRKSRC}/.bochsrc ${STAGEDIR}${DOCSDIR}/bochsrc-sample.txt
	${INSTALL_DATA} ${WRKSRC}/docs-html/*.txt ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/html
	${INSTALL_DATA} ${WRKSRC}/docs-html/*.html ${STAGEDIR}${DOCSDIR}/html

.include <bsd.port.mk>
