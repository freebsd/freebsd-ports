# ex:ts=8
# Ports collection makefile for:  bochs
# Date created:			  16 December 1997
# Whom:				  alex
#
# $FreeBSD$
#

PORTNAME=	bochs
PORTVERSION=	1.2.1
PORTREVISION=	1
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.bochs.com/bochs/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clefevre@citeweb.net

.if ${XFREE86_VERSION} == 4
BUILD_DEPENDS+=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
RUN_DEPENDS+=	mkfontdir:${PORTSDIR}/x11/XFree86-4-clients
.endif

# Global variables
#

USE_XLIB=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--enable-cdrom \
		--disable-split-hd
CFLAGS+=	-fno-rtti -fno-exceptions -fomit-frame-pointer

# PREFIX isn't honored. force it w/ prefix.
MAKE_ARGS=	prefix=${PREFIX}

.if defined(WITH_BOCHS_PROCESSORS)
.if ${WITH_BOCHS_CPU_LEVEL} < 1 || ${WITH_BOCHS_CPU_LEVEL} > 15
.error "WITH_BOCHS_CPU_LEVEL must be an integer value between 1 and 15."
.endif
CONFIGURE_ARGS+=	--enable-processors=${WITH_BOCHS_PROCESSORS}
WITH_BOCHS_CPU_LEVEL=	6
.endif

.if defined(WITH_BOCHS_CPU_LEVEL)
.if ${WITH_BOCHS_CPU_LEVEL} < 3 || ${WITH_BOCHS_CPU_LEVEL} > 6
.error "WITH_BOCHS_CPU_LEVEL must be an integer value between 3 and 6."
.endif
CONFIGURE_ARGS+=	--enable-cpu-level=${WITH_BOCHS_CPU_LEVEL}
.endif

.if defined(WITH_BOCHS_DEBUGGER)
CONFIGURE_ARGS+=	--enable-debugger --enable-disasm
.endif

.if defined(WITH_BOCHS_X86_DEBUGGER)
CONFIGURE_ARGS+=	--enable-x86-debugger
.endif

.if defined(WITH_SOUND)
CONFIGURE_ARGS+=	--enable-sb16=linux
.endif

MAN1=		bochs.1 bochsrc.1 bximage.1

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

# Local variables
#

BIOS_DIR=	${DATADIR}/bios
FONT_DIR=	${DATADIR}/font

MKFONTDIR?=	mkfontdir

# Pre-everything
#

pre-everything::
.if !defined(WITH_BOCHS_CPU_LEVEL) || !defined(WITH_BOCHS_PROCESSORS) || \
    !defined(WITH_BOCHS_DEBUGGER) || !defined(WITH_BOCHS_X86_DEBUGGER) || \
    !defined(WITH_SOUND)
	@${ECHO_MSG}
.if !defined(WITH_BOCHS_CPU_LEVEL)
	@${ECHO_MSG} "If you want to change the processor level to emulate (default is 5, aka Pentium)"
	@${ECHO_MSG} "Choices are 3,4,5,6 which mean target 386, 486, Pentium or Pentium Pro emulation"
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_CPU_LEVEL=<cpu level>\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_BOCHS_PROCESSORS)
	@${ECHO_MSG} "If you want to compile with SMP support (implies WITH_BOCHS_CPU_LEVEL=6)."
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_PROCESSORS=<number of processors>\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_BOCHS_DEBUGGER)
	@${ECHO_MSG} "If you want to compile with builtin debugger and disassembler support."
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_DEBUGGER=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_BOCHS_X86_DEBUGGER)
	@${ECHO_MSG} "If you want to compile with x86 hardware debugger support."
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_BOCHS_X86_DEBUGGER=yes\""
	@${ECHO_MSG}
.endif
.if !defined(WITH_SOUND)
	@${ECHO_MSG} "If you want to compile with sound (blaster 16) support."
	@${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_SOUND=yes\""
.endif
	@${ECHO_MSG}
.endif

# Post-configure
#

post-patch: patch-bochsrc patch-mans patch-wrapper patch-message

patch-bochsrc:
	@${PERL} -pi.fbsd -e ' \
		s|^vgaromimage:\sbios/|vgaromimage: ${BIOS_DIR}/|; \
		s|^romimage:\sfile=bios/|romimage: file=${BIOS_DIR}/|; \
		' ${WRKSRC}/.bochsrc

patch-mans:
	@${PERL} -pi.fbsd -e ' \
		s|/usr/local/bochs|${DATADIR}|; \
		s|\@VERSION\@|${PORTVERSION}|; \
		' ${WRKSRC}/doc/man/*.1

patch-wrapper:
	@${SED} 's|%%PREFIX%%|${PREFIX}|;s|%%X11BASE%%|${X11BASE}|; \
		 s|%%FONT_DIR%%|${FONT_DIR}| \
		' ${FILESDIR}/bochs.sh > ${WRKDIR}/bochs.sh

patch-message:
	@${SED} 's|%%DATADIR%%|${DATADIR}|g' ${MSG_FILE} > ${PKGMESSAGE}

# Post-build
#

post-build: compress-font-file

compress-font-file:
	@${GZIP_CMD} < ${WRKSRC}/font/vga.pcf > ${WRKSRC}/font/vga.pcf.gz

# Install
#

do-install: install-bins install-mans install-bochsrc \
	    install-bios install-fonts install-docs

install-bins:
	@${INSTALL_PROGRAM} ${WRKSRC}/bochs ${PREFIX}/libexec/bochs.bin
	@${INSTALL_PROGRAM} ${WRKSRC}/bximage ${PREFIX}/bin

install-mans:
.for mansect in 1
.for man in ${MAN${mansect}}
	@${INSTALL_MAN} ${WRKSRC}/doc/man/${man} \
		${MAN${mansect}PREFIX}/man/man${mansect}
.endfor
.endfor

install-bochsrc:
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/.bochsrc ${DATADIR}/bochsrc.sample

install-bios:
	@${MKDIR} ${BIOS_DIR}
	@${INSTALL_DATA} ${WRKSRC}/bios/VGABIOS-* ${BIOS_DIR}
	@${INSTALL_DATA} ${WRKSRC}/bios/BIOS-* ${BIOS_DIR}

install-fonts:
	@${MKDIR} ${FONT_DIR}
	@${INSTALL_DATA} ${WRKSRC}/font/vga.pcf.gz ${FONT_DIR}
	@${MKFONTDIR} ${FONT_DIR}

install-docs:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}/html
	@${INSTALL_MAN} ${WRKSRC}/docs-html/* ${DOCSDIR}/html
	@${MV} ${DOCSDIR}/html/*.txt ${DOCSDIR}
.endif

# Post-install
#

post-install: install-script display-message

install-script:
	@${INSTALL_SCRIPT} ${WRKDIR}/bochs.sh ${PREFIX}/bin/bochs

display-message:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
