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

USE_QT_VER=	3
MAKE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		QTDIR=${X11BASE}
MAKE_ARGS=	PREFIX=${PREFIX}
QMAKE=		${LOCALBASE}/bin/qmake
INSTALLS_SHLIB=	yes

DOCSDIR=	${PREFIX}/share/doc/QGLViewer
PORTDOCS=	*

do-build:
	@(cd ${WRKSRC}/QGLViewer && ${SETENV} ${MAKE_ENV} ${QMAKE} ${MAKE_ARGS} && \
	  ${SETENV} ${MAKE_ENV} ${MAKE})

do-install:
	@(cd ${WRKSRC}/QGLViewer && ${SETENV} ${MAKE_ENV} ${MAKE} install)

post-install:
	@${FIND} ${PREFIX}/include/QGLViewer ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/QGLViewer -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.mk>
