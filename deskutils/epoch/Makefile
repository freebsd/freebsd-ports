# New ports collection makefile for:	epoch
# Date created:		2010-06-15
# Whom:			Gvozdikov Veniamin <g.veniamin@googlemail.com>
#
# $FreeBSD$
#

PORTNAME=	epoch
PORTVERSION=	1.4
CATEGORIES=	deskutils
MASTER_SITES=	GOOGLE_CODE
DISTNAME=	Epoch${PORTVERSION}

MAINTAINER=	g.veniamin@googlemail.com
COMMENT=	Epoch is small and handy timeline application

LINCENSE=	GPLv3
PROJECTHOST=	gepoch

USE_ZIP=	yes
USE_QT_VER=	4
QT_COMPONENTS=	gui qmake_build moc_build rcc_build

PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.png

WRKSRC=		${WRKDIR}/${DISTNAME}/src

DESKTOP_ENTRIES="Epoch" "Timeline application" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.png" "${PORTNAME}" \
		"" false

do-configure:
	cd ${WRKSRC} && ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/epoch ${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/images/epoha.png ${PREFIX}/share/pixmaps/${PORTNAME}.png

.include <bsd.port.mk>
