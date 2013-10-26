# Created by: Steve Wills <steve@mouf.net>
# $FreeBSD$

PORTNAME=	visionworkbench
PORTVERSION=	2.2.0
PORTREVISION=	6
CATEGORIES=	graphics
MASTER_SITES=	http://ti.arc.nasa.gov/m/project/nasa-vision-workbench/
DISTNAME=	VisionWorkbench-${PORTVERSION}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	A general purpose image processing and computer vision library

LICENSE=	NOSA
LICENSE_GROUPS=	OSI
LICENSE_NAME=	NASA Open Source Agreement version 1.3
LICENSE_FILE=	${WRKSRC}/COPYING
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

GNU_CONFIGURE=	yes
USES=		pkgconfig
USE_QT4=	moc_build qmake_build
USE_FORTRAN=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	2.4+

LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg
LIB_DEPENDS+=	png15:${PORTSDIR}/graphics/png
LIB_DEPENDS+=	boost_thread:${PORTSDIR}/devel/boost-libs
LIB_DEPENDS+=	boost_python:${PORTSDIR}/devel/boost-python-libs
LIB_DEPENDS+=	gdal:${PORTSDIR}/graphics/gdal
LIB_DEPENDS+=	lapack.4:${PORTSDIR}/math/lapack
LIB_DEPENDS+=	IlmImf:${PORTSDIR}/graphics/OpenEXR
LIB_DEPENDS+=	cairomm-1.0.1:${PORTSDIR}/graphics/cairomm

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${OSVERSION} < 800025
CFLAGS+=	-Dsqrtl=sqrt
. if ${OSVERSION} < 800022
CFLAGS+=	-Dtgammaf=tgamma
. endif
.endif

CFLAGS+=	${PTHREAD_CFLAGS}
LDFLAGS+=	${PTHREAD_LIBS}

CONFIGURE_ENV=	CFLAGS="-I${LOCALBASE}/include ${CFLAGS}" \
		LIBS="-L${LOCALBASE}/lib ${LDFLAGS}"

post-patch:
	@${REINPLACE_CMD} -e "s,-DBOOST_FILESYSTEM_VERSION=2,,g" ${WRKSRC}/configure

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
