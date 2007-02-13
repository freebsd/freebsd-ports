# New ports collection makefile for:	cutecom
# Date created:			Thu Jul 15 02:07:06 CEST 2004
# Whom:				Markus Brueffer <markus@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	cutecom
PORTVERSION=	0.14.1
CATEGORIES=	comms
MASTER_SITES=	http://cutecom.sourceforge.net/

MAINTAINER=	markus@FreeBSD.org
COMMENT=	Graphical serial terminal

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
RUN_DEPENDS=	lsz:${PORTSDIR}/comms/lrzsz

USE_QT_VER=	3
USE_GMAKE=	yes

MAKE_ENV+=	QTDIR="${QT_PREFIX}"

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} qmake \
		-spec ${LOCALBASE}/share/qt/mkspecs/freebsd-g++ cutecom.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/cutecom ${PREFIX}/bin
	${MKDIR} ${PREFIX}/share/applnk/Utilities
	${INSTALL_DATA} ${WRKSRC}/cutecom.desktop ${PREFIX}/share/applnk/Utilities

.include <bsd.port.mk>
