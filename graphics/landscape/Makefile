# New ports collection makefile for:	landscape
# Date created:			1 May 2001
# Whom:				jon@witchspace.com
#
# $FreeBSD$
#

PORTNAME=		landscape
PORTVERSION=		0.7
CATEGORIES=		graphics kde
MASTER_SITES=		http://www.witchspace.com/files/

MAINTAINER=		jon@witchspace.com
COMMENT=		A program for generating and rendering fractal landscapes

BROKEN=			"failed dependency (qt32 and/or qmake?)"
USE_MESA=		yes
USE_KDELIBS_VER=	3
QTDIR?=			${X11BASE}
MAKE_ENV=		QTDIR="${QTDIR}"

pre-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${X11BASE}/share/qt/mkspecs/freebsd-g++ landscape.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/landscape ${PREFIX}/bin

.include <bsd.port.mk>
