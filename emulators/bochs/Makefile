# Ports collection makefile for:  bochs
# Date created:			  16 December 1997
# Whom:				  alex
#
# $FreeBSD$
#

PORTNAME=	bochs
PORTVERSION=	2.3.6
PORTREVISION=	1
PORTEPOCH=	2
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IA-32 (x86) PC emulator that runs DOS, Win 95, and more

BUILD_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS=	mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-docbook
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LDFLAGS="-L${LOCALBASE}/lib"

OPTIONS=	CDROM "Enable CDROM support" on \
		CLGD54XX "Enable Cirrus Logic GD54xx video card" off \
		DEBUGGER "Enable debugger and disassembler support" off \
		DEBUGGER_X86 "Enable x86 hardware debugger" off \
		FPU "Enable FPU emulator" on \
		IDLE_HACK "Keep Bochs from using all CPU time" off \
		IGNORE_BAD_MSR "Ignore unknown MSR references (don't panic)" off \
		MTRR "Enable MTRR emulation (CPU level >= 6)" off \
		MWAIT "Enable experimental MONITOR/MWAIT support" off \
		NE2000 "Enable limited ne2000 support" on \
		NEW_PIT "Enable use of the new PIT model" on \
		OPTIMIZATIONS "Enable all safe speeed optimizations" on \
		PCI "Enable limited i440FX PCI support" on \
		PLUGINS "Enable building dynamic loadable plugins" off \
		PNIC "Enable PCI pseudo NIC (network card) support" off \
		PORT_E9_HACK "Writes to port e9 go to console" on \
		READLINE "Enable readline support in debugger" off \
		RFB "Enable VNC server support in display" off \
		SB16 "Enable Sound Blaster 16 emulation" on \
		SDL "Enable SDL display interface" off \
		SHOW_IPS "Enable logging of measured IPS" off \
		SMP "Enable SMP simulation support (CPU level 6)" off \
		SSE4 "Enable emulation of SSE4.2 instruction set" off \
		SVGA "Enable SVGAlib support" off \
		TCACHE "Enable trace cache" on \
		TERM "Use text only, console based interface" off \
		USB "Enable limited i440FX PCI USB support" off \
		VBE "Enable VGA BIOS Extensions" on \
		WX "Use WxWidgets display interface" off \
		X11 "Use X11 display interface" on \
		X86_64 "Enable AMD x86-64 support" off \
		XPM "Enable XPM library support" off

CFLAGS+=	-fno-rtti -fno-exceptions -fomit-frame-pointer

MANCOMPRESSED=	yes
MAN1=		bochs.1 bochs-dlx.1 bxcommit.1 bximage.1
MAN5=		bochsrc.5

SUB_FILES=	pkg-message

.include <bsd.port.pre.mk>

.if defined(WITHOUT_TERM) && defined(WITHOUT_WX) && defined(WITHOUT_X11)
CONFIGURE_ARGS+=--with-nogui
.endif

.if defined(WITHOUT_CDROM)
CONFIGURE_ARGS+=--disable-cdrom
.endif

.if defined(WITH_CLGD54XX)
CONFIGURE_ARGS+=--enable-clgd54xx
.endif

.if defined(WITH_DEBUGGER)
CONFIGURE_ARGS+=--enable-debugger --enable-disasm
.endif

.if defined(WITH_DEBUGGER_X86)
CONFIGURE_ARGS+=--enable-x86-debugger
.endif

.if defined(WITH_FPU)
CONFIGURE_ARGS+=--enable-fpu
.endif

.if defined(WITH_IDLE_HACK)
CONFIGURE_ARGS+=--enable-idle-hack
.endif

.if defined(WITH_IGNORE_BAD_MSR)
CONFIGURE_ARGS+=--enable-ignore-bad-msr
.endif

.if defined(WITH_MTRR)
CONFIGURE_ARGS+=--enable-mtrr
.endif

.if defined(WITH_MWAIT)
CONFIGURE_ARGS+=--enable-monitor-mwait
.endif

.if defined(WITH_NE2000)
CONFIGURE_ARGS+=--enable-ne2000
.endif

.if defined(WITHOUT_NEW_PIT)
CONFIGURE_ARGS+=--disable-new-pit
.endif

.if defined(WITH_OPTIMIZATIONS)
CONFIGURE_ARGS+=--enable-all-optimizations
.endif

.if defined(WITH_PCI)
CONFIGURE_ARGS+=--enable-pci
.endif

.if defined(WITH_PLUGINS)
CONFIGURE_ARGS+=--enable-plugins
.endif

.if defined(WITH_PNIC)
CONFIGURE_ARGS+=--enable-pnic
.endif

.if defined(WITHOUT_PORT_E9_HACK)
CONFIGURE_ARGS+=--disable-port-e9-hack
.endif

.if defined(WITH_READLINE)
CONFIGURE_ARGS+=--enable-readline
.else
CONFIGURE_ARGS+=--disable-readline
.endif

.if defined(WITH_RFB)
CONFIGURE_ARGS+=--with-rfb
.endif

.if defined(WITH_SB16)
CONFIGURE_ARGS+=--enable-sb16=freebsd
.endif

.if defined(WITH_SMP)
CONFIGURE_ARGS+=--enable-smp
WITH_CPU_LEVEL=	6
.endif

.if defined(WITH_SDL)
USE_SDL=	sdl
CONFIGURE_ARGS+=--with-sdl
.endif

.if defined(WITH_SHOW_IPS)
CONFIGURE_ARGS+=--enable-show-ips
.endif

.if defined(WITH_SSE4)
CONFIGURE_ARGS+=--enable-sse=4 --enable-sse-extension
.endif

.if defined(WITH_SVGA)
LIB_DEPENDS+=	vga.1:${PORTSDIR}/graphics/svgalib
CONFIGURE_ARGS+=--with-svga
.endif

.if defined(WITH_TERM)
CONFIGURE_ARGS+=--with-term
.endif

.if defined(WITHOUT_TCACHE)
CONFIGURE_ARGS+=--disable-trace-cache
.else
CONFIGURE_ARGS+=--enable-trace-cache
.endif

.if defined(WITH_USB)
CONFIGURE_ARGS+=--enable-usb
.endif

.if defined(WITH_VBE)
CONFIGURE_ARGS+=--enable-vbe
.endif

.if defined(WITH_WX)
USE_WX=		2.4-2.6
CONFIGURE_ARGS+=--with-wx
.endif

.if defined(WITH_X11)
USE_XORG=	xext xt
CONFIGURE_ARGS+=--with-x11
.endif

.if defined(WITH_X86_64)
CONFIGURE_ARGS+=--enable-x86-64
.endif

.if defined(WITH_XPM)
USE_XPM=	yes
CONFIGURE_ARGS+=--with-xpm
.endif

.if defined(WITH_CPU_LEVEL)
.if ${WITH_CPU_LEVEL} < 3 || ${WITH_CPU_LEVEL} > 6
IGNORE=		can not install: WITH_CPU_LEVEL must be an integer value between 3 and 6
.endif
CONFIGURE_ARGS+=--enable-cpu-level=${WITH_CPU_LEVEL}
.if ${WITH_CPU_LEVEL} < 5
CONFIGURE_ARGS+=--disable-mmx
.endif
.endif

.if defined(WITH_SSE_LEVEL)
.if ${WITH_SSE_LEVEL} >= 1 && ${WITH_SSE_LEVEL} <= 3
CONFIGURE_ARGS+=--enable-sse=${WITH_SSE_LEVEL}
.else
IGNORE=		can not install: WITH_SSE_LEVEL must be an integer value between 1 and 3
.endif
.endif

pre-everything::
	@${ECHO_CMD}
.if !defined(WITH_CPU_LEVEL)
	@${ECHO_CMD} "If you want to change the processor level to emulate (default is 5, aka Pentium), set WITH_CPU_LEVEL to the desired value. Choices are 3, 4, 5 and 6 which mean target 386, 486, Pentium or Pentium Pro emulation." | ${FMT}
.endif
.if !defined(WITH_SSE_LEVEL)
	@${ECHO_CMD} "If you want to enable SSE you have to set WITH_SSE_LEVEL to 1, 2 or 3." | ${FMT}
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
.if defined(WITH_SVGA)
	@${REINPLACE_CMD} -e 's|-lvga -lvgagl|@LDFLAGS@ &|' \
		${WRKSRC}/gui/Makefile.in
.endif

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
