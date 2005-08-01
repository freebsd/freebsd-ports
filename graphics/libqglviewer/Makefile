# ex:ts=8
# Ports collection makefile for:	libQGLViewer
# Date created:			Jun 8, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libqglviewer
PORTVERSION=	2.0.0.3
CATEGORIES=	graphics
MASTER_SITES=	http://artis.imag.fr/Members/Gilles.Debunne/QGLViewer/src/
DISTNAME=	libQGLViewer-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library helps development of 3D applications

BUILD_DEPENDS=	${QMAKE}:${PORTSDIR}/devel/qmake

WRKSRC=		${WRKDIR}/${DISTNAME}/QGLViewer

USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes

DOCSDIR=	${PREFIX}/share/doc/QGLViewer

QMAKE?=		${LOCALBASE}/bin/qmake
QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

do-configure:
	cd ${CONFIGURE_WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		-spec ${QMAKESPEC} QGLViewer.pro PREFIX="${PREFIX}"

.include <bsd.port.mk>
