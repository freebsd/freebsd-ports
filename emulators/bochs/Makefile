# Ports collection makefile for:  bochs
# Date created:			  16 December 1997
# Whom:				  alex
#
# $FreeBSD$
#

PORTNAME=	bochs
PORTVERSION=	2.4.5
PORTEPOCH=	2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IA-32 (x86) PC emulator that runs DOS, Win 95, and more

USE_GMAKE=	yes
USE_AUTOTOOLS=	libtool:22
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-docbook

OPTIONS=	A20_PIN "Enable support for A20 pin" on \
		ACPI "Enable ACPI emulation" off \
		ALIGN_CHECK "Enable alignment check support" on \
		ASSERT_CHECK "Enable BX_ASSERT checks" off \
		CDROM "Enable CDROM support" on \
		CLGD54XX "Enable Cirrus Logic GD54xx video card" off \
		CONF_MSRS "Enable configurable MSR registers support" on \
		DEBUGGER "Enable debugger support" off \
		DEBUGGER_X86 "Enable x86 hardware debugger" off \
		DISASM "Enable disassemler support " on \
		FAST_FUNCCALL "Enable fast function calls support (x86 only)" off \
		FPU "Enable FPU emulator" on \
		GAMEPORT "Enable standard PC gameport support" off \
		GDB_STUB "Enable GDB stub support" off \
		IDLE_HACK "Keep Bochs from using all CPU time" off \
		INSTRUMENT "Enable support for instrumentation" off \
		IODEBUG "Enable I/O interface to debugger" off \
		LOGGING "Enable logging" on \
		LONG_PHY_ADDR "Enable support for physical address >= 32bit" off \
		MISALIGNEDSSE "Enable misaligned SSE support" off \
		MWAIT "Enable experimental MONITOR/MWAIT support" off \
		NE2000 "Enable limited ne2000 support" on \
		NEW_PIT "Enable use of the new PIT model" on \
		OPTIMIZATIONS "Enable all safe speeed optimizations" on \
		PCI "Enable limited i440FX PCI support" on \
		PLUGINS "Enable building dynamic loadable plugins" off \
		PNIC "Enable PCI pseudo NIC (network card) support" off \
		RAW_SERIAL "Use raw serial port access" off \
		READLINE "Enable readline support in debugger" off \
		REPEAT_SPEED "Enable repeated IO and mem copy speedups" off \
		RFB "Enable VNC server support in display" off \
		SB16 "Enable Sound Blaster 16 emulation" on \
		SDL "Enable SDL display interface" off \
		SHOW_IPS "Enable logging of measured IPS" off \
		SMP "Enable SMP simulation support (CPU level 6)" off \
		SVGA "Enable SVGAlib support" off \
		TCACHE "Enable trace cache" on \
		TERM "Use text only, console based interface" off \
		USB "Enable limited USB UHCI support" off \
		USB_OHCI "Enable limited USB OHCI support" off \
		VBE "Enable VGA BIOS Extensions" on \
		VMX "Enable Virtialization extensions" off \
		WX "Use WxWidgets display interface" off \
		X11 "Use X11 display interface" on \
		X86_64 "Enable AMD x86-64 support" off \
		XPM "Enable XPM library support" off

CFLAGS+=	-fno-exceptions -fomit-frame-pointer
CXXFLAGS+=	-fno-rtti
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

MANCOMPRESSED=	yes
MAN1=		bochs.1 bochs-dlx.1 bxcommit.1 bximage.1
MAN5=		bochsrc.5

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITHOUT_TERM) && defined(WITHOUT_WX) && defined(WITHOUT_X11)
CONFIGURE_ARGS+=--with-nogui
.endif

.if !defined(WITH_A20_PIN)
CONFIGURE_ARGS+=--disable-a20-pin
.else
CONFIGURE_ARGS+=--enable-a20-pin
.endif

.if defined(WITH_ACPI)
CONFIGURE_ARGS+=--enable-acpi
.else
CONFIGURE_ARGS+=--disable-acpi
.endif

.if !defined(WITH_ALIGN_CHECK)
CONFIGURE_ARGS+=--disable-alignment-check
.else
CONFIGURE_ARGS+=--enable-alignment-check
.endif

.if defined(WITH_ASSERT_CHECK)
CONFIGURE_ARGS+=--enable-assert-checks
.else
CONFIGURE_ARGS+=--disable-assert-checks
.endif

.if !defined(WITH_CDROM)
CONFIGURE_ARGS+=--disable-cdrom
.else
CONFIGURE_ARGS+=--enable-cdrom
.endif

.if defined(WITH_CLGD54XX)
CONFIGURE_ARGS+=--enable-clgd54xx
.else
CONFIGURE_ARGS+=--disable-clgd54xx
.endif

.if !defined(WITH_CONF_MSRS)
CONFIGURE_ARGS+=--disable-configurable-msrs
.else
CONFIGURE_ARGS+=--enable-configurable-msrs
.endif

.if defined(WITH_DEBUGGER)
CONFIGURE_ARGS+=--enable-debugger
.else
CONFIGURE_ARGS+=--disable-debugger
.endif

.if defined(WITH_DEBUGGER_X86)
CONFIGURE_ARGS+=--enable-x86-debugger
.else
CONFIGURE_ARGS+=--disable-x86-debugger
.endif

.if !defined(WITH_DISASM)
CONFIGURE_ARGS+=--disable-disasm
.else
CONFIGURE_ARGS+=--enable-disasm
.endif

.if defined(WITH_FAST_FUNCCALL)
CONFIGURE_ARGS+=--enable-fast-function-calls
.else
CONFIGURE_ARGS+=--disable-fast-function-calls
.endif

.if !defined(WITH_FPU)
CONFIGURE_ARGS+=--disable-fpu
.else
CONFIGURE_ARGS+=--enable-fpu
.endif

.if defined(WITH_GAMEPORT)
CONFIGURE_ARGS+=--enable-gameport
.else
CONFIGURE_ARGS+=--disable-gameport
.endif

.if defined(WITH_GDB_STUB)
CONFIGURE_ARGS+=--enable-gdb-stub
.else
CONFIGURE_ARGS+=--disable-gdb-stub
.endif

.if defined(WITH_IDLE_HACK)
CONFIGURE_ARGS+=--enable-idle-hack
.else
CONFIGURE_ARGS+=--disable-idle-hack
.endif

.if defined(WITH_INSTRUMENT)
CONFIGURE_ARGS+=--enable-instrumentation
.else
CONFIGURE_ARGS+=--disable-instrumentation
.endif

.if defined(WITH_IODEBUG)
CONFIGURE_ARGS+=--enable-iodebug
.else
CONFIGURE_ARGS+=--disable-iodebug
.endif

.if !defined(WITH_LOGGING)
CONFIGURE_ARGS+=--disable-logging
.else
CONFIGURE_ARGS+=--enable-logging
.endif

.if defined(WITH_LONG_PHY_ADDR)
CONFIGURE_ARGS+=--enable-long-phy-address
.else
CONFIGURE_ARGS+=--disable-long-phy-address
.endif

.if defined(WITH_MISALIGNDSSE)
CONFIGURE_ARGS+=--enable-misaligned-sse
.else
CONFIGURE_ARGS+=--disable-misaligned-sse
.endif

.if defined(WITH_MWAIT)
CONFIGURE_ARGS+=--enable-monitor-mwait
.else
CONFIGURE_ARGS+=--disable-monitor-mwait
.endif

.if defined(WITH_NE2000)
CONFIGURE_ARGS+=--enable-ne2000
.else
CONFIGURE_ARGS+=--disable-ne2000
.endif

.if !defined(WITH_NEW_PIT)
CONFIGURE_ARGS+=--disable-new-pit
.else
CONFIGURE_ARGS+=--enable-new-pit
.endif

.if defined(WITH_OPTIMIZATIONS)
CONFIGURE_ARGS+=--enable-all-optimizations
.else
CONFIGURE_ARGS+=--disable-all-optimizations
.endif

.if defined(WITH_PCI)
CONFIGURE_ARGS+=--enable-pci
.else
CONFIGURE_ARGS+=--disable-pci
.endif

.if defined(WITH_PLUGINS)
CONFIGURE_ARGS+=--enable-plugins
.else
CONFIGURE_ARGS+=--disable-plugins
.endif

.if defined(WITH_PNIC)
CONFIGURE_ARGS+=--enable-pnic
.else
CONFIGURE_ARGS+=--disable-pnic
.endif

.if defined(WITH_RAW_SERIAL)
CONFIGURE_ARGS+=--enable-raw-serial
.else
CONFIGURE_ARGS+=--disable-raw-serial
.endif

.if defined(WITH_READLINE)
CONFIGURE_ARGS+=--enable-readline
.else
CONFIGURE_ARGS+=--disable-readline
.endif

.if defined(WITH_REPEAT_SPEED)
CONFIGURE_ARGS+=--enable-repeat-speedups
.else
CONFIGURE_ARGS+=--disable-repeat-speedups
.endif

.if defined(WITH_RFB)
CONFIGURE_ARGS+=--with-rfb
.else
CONFIGURE_ARGS+=--without-rfb
.endif

.if defined(WITH_SB16)
CONFIGURE_ARGS+=--enable-sb16=freebsd
.endif

.if defined(WITH_SDL)
USE_SDL=	sdl
CONFIGURE_ARGS+=--with-sdl
.endif

.if defined(WITH_SHOW_IPS)
CONFIGURE_ARGS+=--enable-show-ips
.else
CONFIGURE_ARGS+=--disable-show-ips
.endif

.if defined(WITH_SMP)
CONFIGURE_ARGS+=--enable-smp
WITH_CPU_LEVEL=	6
.endif

.if defined(WITH_SVGA)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--with-svga
.endif

.if defined(WITH_TERM)
CONFIGURE_ARGS+=--with-term
.endif

.if !defined(WITH_TCACHE)
CONFIGURE_ARGS+=--disable-trace-cache
.else
CONFIGURE_ARGS+=--enable-trace-cache
.endif

.if defined(WITH_USB)
CONFIGURE_ARGS+=--enable-usb
.else
CONFIGURE_ARGS+=--disable-usb
.endif

.if defined(WITH_USB_OHCI)
CONFIGURE_ARGS+=--enable-usb-ohci
.else
CONFIGURE_ARGS+=--disable-usb-ohci
.endif

.if !defined(WITH_VBE)
CONFIGURE_ARGS+=--disable-vbe
.else
CONFIGURE_ARGS+=--enable-vbe
.endif

.if defined(WITH_VMX)
CONFIGURE_ARGS+=--enable-vmx
WITH_CPU_LEVEL=	6
.else
CONFIGURE_ARGS+=--disable-vmx
.endif

.if defined(WITH_WX)
USE_WX=		2.4+
CONFIGURE_ENV=	WX_CONFIG="${WX_CONFIG}"
CONFIGURE_ARGS+=--with-wx
.else
CONFIGURE_ARGS+=--disable-debugger-gui
.endif

.if defined(WITH_X11)
USE_XORG=	xext xt
CONFIGURE_ARGS+=--with-x11
.endif

.if defined(WITH_X86_64)
CONFIGURE_ARGS+=--enable-x86-64
.else
CONFIGURE_ARGS+=--disable-x86-64
.endif

.if defined(WITH_XPM)
USE_XORG=	xpm
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

pre-everything::
	@${ECHO_CMD}
.if !defined(WITH_CPU_LEVEL)
	@${ECHO_CMD} "If you want to change the processor level to emulate (default is 5, aka Pentium), set WITH_CPU_LEVEL to the desired value. Choices are 3, 4, 5 and 6 which mean target 386, 486, Pentium or Pentium Pro emulation." | ${FMT}
.endif
	@${ECHO_CMD}

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
.if defined(WITH_PLUGINS)
	@${FIND} ${PREFIX}/lib/bochs ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/lib/bochs -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}
.endif
.if !defined(NOPORTDOCS)
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

.include <bsd.port.post.mk>
