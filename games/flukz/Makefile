# $FreeBSD$

PORTNAME=	flukz
PORTVERSION=	0.4
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://download.tuxfamily.org/${PORTNAME}/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Vertically scrolling shoot'em up

DEPRECATED=		Qt4 has been EOL since december 2015
EXPIRATION_DATE=	2019-03-15

USES=		qmake qt:4
USE_QT=		corelib gui multimedia network moc_build rcc_build

DESKTOP_ENTRIES=	Flukz "" ${PORTNAME} \
			${PORTNAME} "Game;ArcadeGame;" true

PLIST_FILES=	bin/flukz \
		share/pixmaps/flukz.png

post-patch:
	${REINPLACE_CMD} 's,flukz_debug,flukz,' ${WRKSRC}/flukz.pro
	${REINPLACE_CMD} 's,malloc.h,stdlib.h,' \
		${WRKSRC}/src/soundengine/stb_vorbis.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bin/flukz ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/images/flukz-24x32.png \
		${STAGEDIR}${PREFIX}/share/pixmaps/flukz.png

.include <bsd.port.mk>
