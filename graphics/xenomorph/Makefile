# ex:ts=8
# Ports collection makefile for:	xenomorph
# Date created:			Apr 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xenomorph
PORTVERSION=	0.5.1
CATEGORIES=	graphics
MASTER_SITES=	http://xenomorph.sourceforge.net/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image filter system based on volterra and morphologic filters

USE_BZIP2=	yes
USE_QT_VER=	3
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR=${X11BASE}
MAKE_ENV=	QTDIR=${X11BASE}

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ xenomorph.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xenomorph ${PREFIX}/bin

.include <bsd.port.mk>
