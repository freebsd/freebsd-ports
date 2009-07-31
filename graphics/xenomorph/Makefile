# ex:ts=8
# Ports collection makefile for:	xenomorph
# Date created:			Apr 3, 2003
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	xenomorph
PORTVERSION=	0.6
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	http://xenomorph.sourceforge.net/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An image filter system based on volterra and morphologic filters

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake

USE_BZIP2=	yes
USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"

PLIST_FILES=	bin/xenomorph

do-configure:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ xenomorph.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xenomorph ${PREFIX}/bin

.include <bsd.port.mk>
