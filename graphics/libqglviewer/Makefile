# ex:ts=8
# Ports collection makefile for:	libQGLViewer
# Date created:			Jun 8, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libqglviewer
PORTVERSION=	2.2.4.1
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://artis.imag.fr/Members/Gilles.Debunne/QGLViewer/src/
DISTNAME=	libQGLViewer-${PORTVERSION:R}-${PORTVERSION:E}

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	A C++ library helps development of 3D applications

BUILD_DEPENDS=	${QMAKE}:${PORTSDIR}/devel/qmake

WRKSRC=		${WRKDIR}/${DISTNAME}/QGLViewer

USE_QT_VER=	3
MAKE_ENV=	QTDIR="${QT_PREFIX}"
USE_GL=		yes
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/share/doc/QGLViewer

QMAKE?=		${LOCALBASE}/bin/qmake
QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

do-configure:
	@cd ${CONFIGURE_WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} \
		-spec ${QMAKESPEC} QGLViewer.pro PREFIX="${PREFIX}"

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKDIR}/${DISTNAME}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
.endif
.include <bsd.port.mk>
