# New ports collection makefile for:	colorcode
# Date created:		2010-10-16
# Whom:			Max Brazhnikov <makc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	colorcode
PORTVERSION=	0.7.1
CATEGORIES=	games
MASTER_SITES=	http://colorcode.laebisch.com/download/
DISTNAME=	ColorCode-${PORTVERSION}

MAINTAINER=	makc@FreeBSD.org
COMMENT=	A free advanced MasterMind game and solver

USE_QT_VER=	4
QT_COMPONENTS=	gui moc_build qmake_build rcc_build uic_build
HAS_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/ColorCode-${PORTVERSION}

DESKTOP_ENTRIES=	"ColorCode" "Advanced MasterMind game and solver" \
			"${PREFIX}/share/pixmaps/colorcode.png" "colorcode" \
			"Application;LogicGame;Game;" false

PLIST_FILES=	bin/colorcode \
		share/pixmaps/colorcode.png

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} ${QMAKE_ARGS}

do-install:
	${MKDIR} ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/colorcode ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/pixmaps
	${INSTALL_DATA}	${WRKSRC}/img/cc64.png	${PREFIX}/share/pixmaps/colorcode.png

.include <bsd.port.mk>
