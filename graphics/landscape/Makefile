# New ports collection makefile for:	landscape
# Date created:			1 May 2001
# Whom:				jon@witchspace.com
#
# $FreeBSD$
#

PORTNAME=		landscape
PORTVERSION=		0.7
PORTREVISION=	3
CATEGORIES=		graphics kde
MASTER_SITES=		http://www.witchspace.com/files/

MAINTAINER=		jon@witchspace.com
COMMENT=		A program for generating and rendering fractal landscapes

BUILD_DEPENDS=		qmake:${PORTSDIR}/devel/qmake

PLIST_FILES=		bin/landscape
USE_MESA=		yes
USE_KDELIBS_VER=	3
QTDIR?=			${X11BASE}
MAKE_ENV=		QTDIR="${QTDIR}"

pre-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ landscape.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/landscape ${PREFIX}/bin

.include <bsd.port.mk>
