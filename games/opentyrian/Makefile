PORTNAME=	opentyrian
PORTVERSION=	2.1.20130907
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://bitbucket.org/opentyrian/opentyrian/get/ \
		http://mirror.amdmi3.ru/distfiles/${DIST_SUBDIR}/
DISTNAME=	${PORTVERSION}
DIST_SUBDIR=	opentyrian

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Arcade-style vertical scrolling shooter

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		gmake sdl tar:bzip2
USE_SDL=	sdl

MAKE_ENV=	ALL_CFLAGS="${CFLAGS}"

DATADIR=	${PREFIX}/share/tyrian
PORTSCOUT=	skipv:11402-phase-0.8
SUB_FILES=	pkg-message

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-77a8715634e3

PORTDOCS=	CREDITS NEWS README

OPTIONS_DEFINE=	NETWORK DOCS

NETWORK_DESC=	Enable network support
NETWORK_USE=		SDL=net
NETWORK_MAKE_ARGS=	WITH_NETWORK=true
NETWORK_MAKE_ARGS_OFF=	WITH_NETWORK=false

post-patch:
	@${REINPLACE_CMD} -e '/custom_data_dir/ s|"."|"${DATADIR}"|' ${WRKSRC}/src/file.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	${INSTALL_DATA} ${WRKSRC}/linux/${PORTNAME}.desktop ${STAGEDIR}${PREFIX}/share/applications/
	${INSTALL_DATA} ${WRKSRC}/linux/icons/tyrian-32.png ${STAGEDIR}${PREFIX}/share/pixmaps/${PORTNAME}.png
	${INSTALL_MAN} ${WRKSRC}/linux/man/${PORTNAME}.6 ${STAGEDIR}${MAN6PREFIX}/man/man6/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${TOUCH} ${STAGEDIR}${DATADIR}/.keepme

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}/
.endfor

.include <bsd.port.mk>
