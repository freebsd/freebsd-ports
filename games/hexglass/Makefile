# New ports collection makefile for:	hexglass
# Date created:		2010-12-17
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	hexglass
PORTVERSION=	1.2.0
CATEGORIES=	games
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	makc@FreeBSD.org
COMMENT=	Tetris-like puzzle game based on a hexagonal grid

USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build moc_build rcc_build
HAS_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/pixmaps/${PORTNAME}.xpm

DESKTOP_ENTRIES=	"HexGlass" "${COMMENT}" \
			"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
			"${PORTNAME}" "Application;BlocksGame;Game;" false

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA} ${WRKSRC}/resources/logo512x512.xpm \
		${PREFIX}/share/pixmaps/${PORTNAME}.xpm

.include <bsd.port.mk>
