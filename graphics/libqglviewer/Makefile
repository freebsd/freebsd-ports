# ex:ts=8
# Ports collection makefile for:	libQGLViewer
# Date created:			Jun 8, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libqglviewer
PORTVERSION=	1.3.7
CATEGORIES=	graphics
MASTER_SITES=	http://artis.imag.fr/Members/Gilles.Debunne/QGLViewer/src/
DISTNAME=	libQGLViewer-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A C++ library helps development of 3D applications

BUILD_DEPENDS=	${QMAKE}:${PORTSDIR}/devel/qmake

USE_BZIP2=	yes
USE_QT_VER=	3
MAKE_ENV=	QMAKESPEC=${LOCALBASE}/share/qt/mkspecs/freebsd-g++ \
		QTDIR=${X11BASE}
QMAKE=		${LOCALBASE}/bin/qmake
INSTALLS_SHLIB=	yes

DOCSDIR=	${PREFIX}/share/doc/QGLViewer
PORTDOCS=	*

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
BROKEN=		"Does not compile on 4.x"
.endif

do-build:
	@(cd ${WRKSRC}/QGLViewer && ${SETENV} ${MAKE_ENV} ${QMAKE} && \
	  ${SETENV} ${MAKE_ENV} ${MAKE})

do-install:
	@(cd ${WRKSRC}/QGLViewer && ${SETENV} ${MAKE_ENV} ${MAKE} install)

post-install:
	@${FIND} ${PREFIX}/include/QGLViewer ! -type d | \
		${SED} 's,^${PREFIX}/,,' >> ${TMPPLIST}
	@${FIND} ${PREFIX}/include/QGLViewer -type d | ${SORT} -r | \
		${SED} 's,^${PREFIX}/,@dirrm ,' >> ${TMPPLIST}

.include <bsd.port.post.mk>
