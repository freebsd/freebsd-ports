# $FreeBSD$

PORTNAME=	frodo
PORTVERSION=	4.1b
PORTREVISION=	11
CATEGORIES=	emulators tk
MASTER_SITES=	http://frodo.cebix.net/downloads/
DISTNAME=	FrodoV4_1b.Src

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Emulates a Commodore 64

BROKEN_FreeBSD_12=	Regression C++

USES=		shebangfix tk:run
USE_XORG=	x11 xt xext sm ice
ALL_TARGET=	Frodo
INSTALL_WRKSRC=	${WRKDIR}/Frodo-4.1b
WRKSRC=		${INSTALL_WRKSRC}/Src
GNU_CONFIGURE=	yes
SHEBANG_FILES=	../TkGui.tcl

ROM=		1541 Basic Char Kernal

OPTIONS_DEFINE=	SDL DOCS
OPTIONS_DEFAULT=SDL

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
.endif

pre-configure:
	${REINPLACE_CMD} -e 's|wish|wish${TK_VER}|' \
		${WRKSRC}/C64_x.i

do-install:
	${SED} -e 's=\$${PREFIX}=${PREFIX}=g' \
		 < ${FILESDIR}/frodo > ${WRKDIR}/frodo
	${INSTALL_SCRIPT} ${WRKDIR}/frodo ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/frodo
	${INSTALL_PROGRAM} ${INSTALL_WRKSRC}/Frodo ${STAGEDIR}${PREFIX}/libexec/frodo/
.for i in ${ROM}
	${INSTALL_DATA} "${INSTALL_WRKSRC}/${i} ROM" ${STAGEDIR}${PREFIX}/libexec/frodo/
.endfor
	${INSTALL_DATA} "${INSTALL_WRKSRC}/Frodo Logo" ${STAGEDIR}${PREFIX}/libexec/frodo/
	${INSTALL_SCRIPT} "${INSTALL_WRKSRC}/TkGui.tcl" ${STAGEDIR}${PREFIX}/libexec/frodo/
	${MKDIR} ${STAGEDIR}${PREFIX}/libexec/frodo/64prgs
	${TAR} -C ${INSTALL_WRKSRC}/64prgs -cf - . | \
		${TAR} -C ${STAGEDIR}${PREFIX}/libexec/frodo/64prgs -xf -

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${INSTALL_WRKSRC}/CHANGES ${STAGEDIR}${DOCSDIR}/
	${TAR} -C ${INSTALL_WRKSRC}/Docs -cf - . | \
		${TAR} -C ${STAGEDIR}${DOCSDIR} -xf -

.include <bsd.port.mk>
