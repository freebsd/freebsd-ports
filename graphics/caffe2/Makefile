# $FreeBSD$

PORTNAME=	caffe2
PORTVERSION=	0.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	graphics

MAINTAINER=	eric@camachat.org
COMMENT=	Caffe2 is a lightweight, modular, and scalable deep learning framework

CONFLICTS_INSTALL=	caffe-*

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS= ${PYNUMPY} \
		${LOCALBASE}/bin/cython:lang/cython \
		${PYTHON_INCLUDEDIR}/pybind11/common.h:devel/py-pybind11 \
		${LOCALBASE}/include/eigen3/Eigen/Eigen:math/eigen3
LIB_DEPENDS=	libsnappy.so:archivers/snappy \
		libleveldb.so:databases/leveldb \
		liblmdb.so:databases/lmdb \
		libgflags.so:devel/gflags \
		libglog.so:devel/glog \
		libprotobuf.so:devel/protobuf \
		libopencv_highgui.so:graphics/opencv \
		libopencv_core.so:graphics/opencv-core
RUN_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}protobuf>=2.5.0:devel/py-protobuf \
		${PYTHON_PKGNAMEPREFIX}pydot>=1.2.3:graphics/py-pydot \
		${PYTHON_PKGNAMEPREFIX}six>=1.10:devel/py-six

USES=		cmake python pkgconfig
USE_LDCONFIG=	yes
USE_GITHUB=	yes

# Those are Linux only
CMAKE_ARGS+=	-DUSE_NCCL=OFF -DUSE_CUDA=OFF -DUSE_NNPACK=OFF -DUSE_GLOO=OFF -DBUILD_TEST=OFF

OPTIONS_DEFINE=	OPENMP OPENMPI ROCKSDB ZEROMQ
OPTIONS_DEFAULT=	OPENMP OPENMPI
OPTIONS_SUB=	YES

OPENMP_LLVMVER=	50
OPENMP_CMAKE_ON=	-DUSE_OPENMP=ON
OPENMP_CMAKE_OFF=	-DUSE_OPENMP=OFF
OPENMP_CFLAGS=	-I${LOCALBASE}/llvm${OPENMP_LLVMVER}/include
OPENMP_BUILD_DEPENDS=	llvm${OPENMP_LLVMVER}>=5.0:devel/llvm${OPENMP_LLVMVER}
OPENMP_RUN_DEPENDS=	llvm${OPENMP_LLVMVER}>=5.0:devel/llvm${OPENMP_LLVMVER}
OPENMP_VARS=	CPP=clang-cpp${OPENMP_LLVMVER} CC=clang${OPENMP_LLVMVER} CXX=clang++${OPENMP_LLVMVER}
OPENMP_VARS_OFF=	USES+=compiler:c++11-lib

OPENMPI_LIB_DEPENDS=	libmpi.so:net/openmpi2
OPENMPI_CMAKE_ON=	-DUSE_MPI=ON
OPENMPI_CMAKE_OFF=	-DUSE_MPI=OFF
OPENMPI_VARS=	CONFIGURE_ENV+=PATH=$${PATH}:${LOCALBASE}/mpi/openmpi2/bin	MAKE_ENV+=PATH=$${PATH}:${LOCALBASE}/mpi/openmpi2/bin

ROCKSDB_DESC=	Use RocksDB
ROCKSDB_LIB_DEPENDS=	librocksdb.so:databases/rocksdb
ROCKSDB_CMAKE_ON=	-DUSE_ROCKSDB=ON
ROCKSDB_CMAKE_OFF=	-DUSE_ROCKSDB=OFF

ZEROMQ_DESC=	Use ZeroMQ
ZEROMQ_LIB_DEPENDS=	libzmq.so:net/libzmq4
ZEROMQ_CMAKE_ON=	-DUSE_ZMQ=ON
ZEROMQ_CMAKE_OFF=	-DUSE_ZMQ=OFF

post-patch:
	@${REINPLACE_CMD} -e 's,%%PYTHON_SITELIBDIR%%,${PYTHON_SITELIBDIR},g' \
		${WRKSRC}/CMakeLists.txt \
		${WRKSRC}/caffe2/CMakeLists.txt
	@${RMDIR} ${WRKSRC}/third_party/eigen && ${LN} -fs ${LOCALBASE}/include/eigen3 ${WRKSRC}/third_party/eigen

.include <bsd.port.mk>
