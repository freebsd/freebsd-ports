# $FreeBSD$

PORTNAME=	caffe
PORTVERSION=	1.0
PORTREVISION=	5
CATEGORIES=	graphics

MAINTAINER=	eric@camachat.org
COMMENT=	Fast open framework for deep learning

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

CONFLICTS_INSTALL=	caffe2-*

BUILD_DEPENDS=	${PYNUMPY} \
		${LOCALBASE}/bin/cython:lang/cython \
		${LOCALBASE}/include/cblas.h:math/cblas \
		bash:shells/bash
LIB_DEPENDS=	libsnappy.so:archivers/snappy \
		libleveldb.so:databases/leveldb \
		liblmdb.so:databases/lmdb \
		libboost_system.so:devel/boost-libs \
		libboost_python.so:devel/boost-python-libs \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libprotobuf.so:devel/protobuf \
		libopencv_highgui.so:graphics/opencv \
		libopencv_core.so:graphics/opencv-core \
		libopenblas.so:math/openblas \
		libhdf5.so:science/hdf5
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.5.0:devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}scikit-image>=0.12:graphics/py-scikit-image \
		${PYTHON_PKGNAMEPREFIX}pillow>=1.7:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}networkx>=1.8:math/py-networkx \
		${PYTHON_PKGNAMEPREFIX}matplotlib>=1.1:math/py-matplotlib \
		${PYTHON_PKGNAMEPREFIX}PyWavelets>=0.4:math/py-PyWavelets

USE_LDCONFIG=	yes
USES=		gmake python fortran compiler:c++11-lib pkgconfig

CXXFLAGS+=	-DGTEST_USE_OWN_TR1_TUPLE=1
LDFLAGS+=	-DGTEST_USE_OWN_TR1_TUPLE=1
LDFLAGS+=	-lboost_thread
MAKE_ARGS+=	DISTRIBUTE_DIR=${STAGEDIR}${PREFIX}
ALL_TARGET=	all py
INSTALL_TARGET=	dist
TEST_TARGET=	runtest
PLIST_SUB=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} DATADIR=${DATADIR}

GH_ACCOUNT=	BVLC
USE_GITHUB=	yes

post-extract:
	@${CP} -v ${.CURDIR}/files/Makefile.config ${WRKSRC}/

post-patch:
	@${REINPLACE_CMD} \
	-e "s|%%CXX%%|clang++|g" \
	-e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
	-e "s|%%DATADIR%%|${DATADIR}|g" \
	-e "s|%%PYTHON_INCLUDEDIR%%|${PYTHON_INCLUDEDIR}|g" \
	-e "s|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g" \
	-e "s|%%STAGEDIR%%|${STAGEDIR}|g" \
	${WRKSRC}/Makefile.config ${WRKSRC}/Makefile

pre-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}

post-install:
	@${STRIP_CMD} ${STAGEDIR}/${PREFIX}/bin/* ${STAGEDIR}/${PREFIX}/lib/*.so.* \
	${STAGEDIR}/${PYTHON_SITELIBDIR}/${PORTNAME}/*.so

.include <bsd.port.mk>
