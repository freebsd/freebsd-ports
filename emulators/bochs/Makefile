# ex:ts=8
# Ports collection makefile for:  bochs
# Date created:			  16 December 1997
# Whom:				  alex
#
# $FreeBSD$
#

PORTNAME=	bochs
PORTVERSION=	2.2.6
PORTEPOCH=	2
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An IA-32 (x86) PC emulator that runs DOS, Win 95, and more

BUILD_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}
RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}

USE_XLIB=	yes
USE_GMAKE=	yes

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-split-hd \
		--enable-all-optimizations \
		--with-x11 \
		--enable-pci \
		--enable-sb16=freebsd \
		--enable-ne2000 \
		--enable-vbe

CFLAGS+=	-fno-rtti -fno-exceptions -fomit-frame-pointer

MANCOMPRESSED=	yes
MAN1=		bochs.1 bochs-dlx.1 bxcommit.1 bximage.1
MAN5=		bochsrc.5

SUB_FILES=	pkg-message

.if defined(WITH_BOCHS_SMP)
CONFIGURE_ARGS+=	--enable-smp
WITH_BOCHS_CPU_LEVEL=	6
.endif

.if defined(WITH_BOCHS_CPU_LEVEL)
.if ${WITH_BOCHS_CPU_LEVEL} < 3 || ${WITH_BOCHS_CPU_LEVEL} > 6
IGNORE=	cannot install: WITH_BOCHS_CPU_LEVEL must be an integer value between 3 and 6
.endif
CONFIGURE_ARGS+=	--enable-cpu-level=${WITH_BOCHS_CPU_LEVEL}
.if ${WITH_BOCHS_CPU_LEVEL} < 5
CONFIGURE_ARGS+=	--disable-mmx
.endif
.endif

.if defined(WITH_BOCHS_GUI_TERM)
CONFIGURE_ARGS+=	--with-term
.endif

.if defined(WITH_BOCHS_GUI_NOGUI)
CONFIGURE_ARGS+=	--with-nogui
.endif

.if defined(WITH_BOCHS_AMD64)
CONFIGURE_ARGS+=	--enable-x86-64
.endif

.if defined(WITH_BOCHS_DEBUGGER)
CONFIGURE_ARGS+=	--enable-debugger --enable-disasm
.endif

.if defined(WITH_BOCHS_X86_DEBUGGER)
CONFIGURE_ARGS+=	--enable-x86-debugger
.endif

.if defined(WITH_BOCHS_PORT_E9_HACK)
CONFIGURE_ARGS+=	--enable-port-e9-hack
.endif

pre-patch::
	@${ECHO_MSG}
.if !defined(WITH_BOCHS_CPU_LEVEL)
	@${ECHO_MSG} "If you want to change the processor level to emulate (default is 5, aka Pentium)"
	@${ECHO_MSG} "Choices are 3,4,5,6 which mean target 386, 486, Pentium or Pentium Pro emulation"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_CPU_LEVEL=<cpu level>\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_BOCHS_GUI_TERM)
	@${ECHO_MSG} "If you want to enable the plain text, console-based bochs interface"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_GUI_TERM=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_BOCHS_GUI_NOGUI)
	@${ECHO_MSG} "If you want the bochs display"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_GUI_NOGUI=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_BOCHS_SMP)
	@${ECHO_MSG} "If you want to compile with SMP support (implies WITH_BOCHS_CPU_LEVEL=6),"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_SMP\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_BOCHS_DEBUGGER)
	@${ECHO_MSG} "If you want to compile with builtin debugger and disassembler support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_DEBUGGER=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_BOCHS_X86_DEBUGGER)
	@${ECHO_MSG} "If you want to compile with x86 hardware debugger support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_X86_DEBUGGER=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_BOCHS_AMD64)
	@${ECHO_MSG} "If you want to compile with AMD x86-64 support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_AMD64=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_BOCHS_PORT_E9_HACK)
	@${ECHO_MSG} "If you want to compile with port e9 hack support,"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_PORT_E9_HACK=yes\""
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -E ' \
		s|file=bios/|file=${DATADIR}/|; \
		s|bios/VGABIOS|${DATADIR}/VGABIOS|; \
		' ${WRKSRC}/.bochsrc
	@${REINPLACE_CMD} -E ' \
		s|(^sharedir.+=).+|\1 ${DATADIR}|; \
		s|(^docdir.+=).+|\1 ${DOCSDIR}|; \
		' ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e ' \
		s|/usr/local/share/bochs|${DATADIR}|; \
		s|/usr/local/share/doc/bochs|${DOCSDIR}|; \
		' ${WRKSRC}/doc/docbook/user/user.dbk ${WRKSRC}/doc/man/*.1 \
		${WRKSRC}/doc/man/*.5

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs-html/*.txt ${DOCSDIR}
	@${MKDIR} ${DOCSDIR}/html
	@${INSTALL_DATA} ${WRKSRC}/docs-html/*.html ${DOCSDIR}/html
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
