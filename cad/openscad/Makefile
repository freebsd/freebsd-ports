# New ports collection makefile for:	openscad
# Date created:				17 August 2011
# Whom:					Michael Reifenberger <mr@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	openscad
PORTVERSION=	2011.06
#PORTREVISION=	0
CATEGORIES=	cad
MASTER_SITES=	https://cloud.github.com/downloads/openscad/openscad/
DISTNAME=	openscad-${PORTVERSION}.src

MAINTAINER=	mr@FreeBSD.org
COMMENT=	The programmer's solid 3D CAD modeller

BUILD_DEPENDS=	bison:${PORTSDIR}/devel/bison \
		flex:${PORTSDIR}/textproc/flex \
		eigen>=2.0.3:${PORTSDIR}/math/eigen2 \
		${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
#RUN_DEPENDS=	${LOCALBASE}/include/boost/tuple/tuple.hpp:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS=	GLU.1:${PORTSDIR}/graphics/libGLU \
		gmp.10:${PORTSDIR}/math/gmp \
		mpfr.4:${PORTSDIR}/math/mpfr \
		CGAL.5:${PORTSDIR}/math/cgal \
		opencsg:${PORTSDIR}/graphics/opencsg

USE_GL=		glew
USE_QT_VER=     4
QT_COMPONENTS=  qmake_build
PLIST_SUB=      PORTVERSION=${PORTVERSION}
#MAKE_JOBS_UNSAFE=yes
QMAKE_ENV =		EIGEN2DIR=${LOCALBASE}/include/eigen2
QMAKE_FLAGS =		VERSION=${PORTVERSION}
MAKE_ENV =		INSTALL_ROOT=${DESTDIR}
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

pre-configure:
	${REINPLACE_CMD} -e 's,XXXFLEXXX,"${LOCALBASE}/bin/flex",' \
		${WRKSRC}/openscad.pro
	${REINPLACE_CMD} -e 's,XXXBISONXXX,"${LOCALBASE}/bin/bison",' \
		${WRKSRC}/openscad.pro

do-configure:
	cd ${WRKSRC} && \
	${SETENV} ${QMAKE_ENV} ${QMAKE} ${QMAKE_FLAGS} openscad.pro

.include <bsd.port.mk>
