# New ports collection makefile for:	landscape
# Date created:			1 May 2001
# Whom:				jon@witchspace.com
#
# $FreeBSD$
#

PORTNAME=		landscape
PORTVERSION=		0.7
PORTREVISION=		13
CATEGORIES=		graphics kde
MASTER_SITES=		http://homepage.ntlworld.com/jon.belson/files/

MAINTAINER=		jon@witchspace.com
COMMENT=		A program for generating and rendering fractal landscapes

BUILD_DEPENDS=		qmake:${PORTSDIR}/devel/qmake

USE_GL=			glut
PLIST_FILES=		bin/landscape
USE_KDELIBS_VER=	3
QTDIR?=			${QT_PREFIX}
MAKE_ENV=		QTDIR="${QTDIR}"

pre-build:
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ landscape.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/landscape ${PREFIX}/bin

.include <bsd.port.mk>
