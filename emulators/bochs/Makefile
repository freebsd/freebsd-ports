# ex:ts=8
# Ports collection makefile for:  bochs
# Date created:			  16 December 1997
# Whom:				  alex
#
# $FreeBSD$
#

PORTNAME=	bochs
PORTVERSION=	1.2
PORTEPOCH=	1
CATEGORIES=	emulators
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		ftp://ftp.bochs.com/bochs/
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	clefevre@citeweb.net

USE_XLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-cpu-level=5 \
		--enable-cdrom \
		--disable-split-hd
CFLAGS+=	-fno-rtti -fno-exceptions -fomit-frame-pointer
PKGMESSAGE=	${WRKDIR}/pkg-message

.ifdef(WITH_BOCHS_DEBUGGER)
CONFIGURE_ARGS+=	--enable-debugger --enable-disasm
.endif
.ifdef(WITH_BOCHS_X86_DEBUGGER)
CONFIGURE_ARGS+=	--enable-x86-debugger
.endif
.ifdef(WITH_SOUND)
CONFIGURE_ARGS+=	--enable-sb16=linux
.endif

pre-configure:
	@${PERL} -pi.fbsd \
		 -e 's|^vgaromimage:\sbios/|vgaromimage: ${PREFIX}/share/bochs/bios/| ;' \
		 -e 's|^romimage:\sfile=bios/|romimage: file=${PREFIX}/share/bochs/bios/|' \
		${WRKSRC}/.bochsrc

post-build:
	${GZIP_CMD} < ${WRKSRC}/font/vga.pcf > ${WRKSRC}/font/vga.pcf.gz
	(${ECHO} '#!/bin/sh'; \
	 ${ECHO} '${X11BASE}/bin/xset fp+ ${PREFIX}/share/bochs/font'; \
	 ${ECHO} 'exec ${PREFIX}/bin/bochs-bin "$$@"') > ${WRKDIR}/bochs.sh

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bochs ${PREFIX}/bin/bochs-bin
	${INSTALL_PROGRAM} ${WRKSRC}/bximage ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKDIR}/bochs.sh ${PREFIX}/bin/bochs
	@${MKDIR} ${PREFIX}/share/bochs
	${INSTALL_DATA} ${WRKSRC}/.bochsrc ${PREFIX}/share/bochs/dot.bochsrc
	@${MKDIR} ${PREFIX}/share/bochs/bios
	${INSTALL_DATA} ${WRKSRC}/bios/VGABIOS-* \
		${PREFIX}/share/bochs/bios
	${INSTALL_DATA} ${WRKSRC}/bios/BIOS-* \
		${PREFIX}/share/bochs/bios
	@${MKDIR} ${PREFIX}/share/bochs/font
	${INSTALL_DATA} ${WRKSRC}/font/vga.pcf.gz ${WRKSRC}/font/fonts.dir \
		${PREFIX}/share/bochs/font
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/bochs
	${INSTALL_MAN} ${WRKSRC}/docs-html/* ${PREFIX}/share/doc/bochs
.endif

post-install:
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > \
		${PKGMESSAGE}
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
