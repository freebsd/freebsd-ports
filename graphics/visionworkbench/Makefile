# New ports collection makefile for:	visionworkbench
# Date created:		2010-01-03
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	visionworkbench
PORTVERSION=	2.1.0
PORTREVISION=	1
CATEGORIES=	graphics
MASTER_SITES=	http://ti.arc.nasa.gov/m/project/nasa-vision-workbench/
DISTNAME=	VisionWorkbench-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A general purpose image processing and computer vision library

LICENSE=	NOSA
LICENSE_NAME=	NASA Open Source Agreement version 1.3
LICENSE_GROUPS=	OSI
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept
LICENSE_FILE=	${WRKSRC}/COPYING

GNU_CONFIGURE=	yes
USE_QT_VER=	4
QT_COMPONENTS=	moc_build qmake_build
USE_GCC=	4.5+
USE_LDCONFIG=	yes
USE_PYTHON=	2.4+

LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	png.6:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	boost_thread.4:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS+=	boost_python.4:${PORTSDIR}/devel/boost-python-libs
LIB_DEPENDS+=	gdal:${PORTSDIR}/graphics/gdal
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	IlmImf.6:${PORTSDIR}/graphics/OpenEXR
LIB_DEPENDS+=	cairomm-1.0.1:${PORTSDIR}/graphics/cairomm

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800025
CFLAGS+=	-Dsqrtl=sqrt
. if ${OSVERSION} < 800022
CFLAGS+=	-Dtgammaf=tgamma
. endif
.endif

pre-configure:
	echo "HAVE_PKG_FLAPACK=yes" >> ${WRKSRC}/config.options
	echo "PKG_FLAPACK_LDFLAGS=-L${LOCALBASE}/lib/${CC}" >> ${WRKSRC}/config.options
	echo "HAVE_PKG_PYTHON=yes" >> ${WRKSRC}/config.options
	echo "PYTHON_LDFLAGS=-L${PYTHON_LIBDIR} -lboost_python -l${PYTHON_VERSION} ${PTHREAD_LIBS}" >> ${WRKSRC}/config.options
	echo "PYTHON_CPPFLAGS=-I${PYTHON_INCLUDEDIR}" >> ${WRKSRC}/config.options
	echo "HAVE_PKG_QT=yes" >> ${WRKSRC}/config.options
	echo "PKG_QT_LDFLAGS=-L${QT_LIBDIR}" >> ${WRKSRC}/config.options
	echo "PKG_QT_CPPFLAGS=-I${QT_INCDIR}" >> ${WRKSRC}/config.options
	echo "HAVE_PKG_BOOST=yes" >> ${WRKSRC}/config.options
	echo "PKG_BOOST_THREAD_MORE_LIBS=${PTHREAD_LIBS}" >> ${WRKSRC}/config.options
	echo "PKG_PATHS=${LOCALBASE}" >> ${WRKSRC}/config.options

regression-test: build
	@(cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} check)

.include <bsd.port.post.mk>
