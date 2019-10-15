# $FreeBSD$

PORTNAME=			pocl
PORTVERSION=		1.4
DISTVERSIONPREFIX=	v
CATEGORIES=			lang

MAINTAINER=			ohartmann@walstatt.org
COMMENT=			POrtable Computing Language (POCL)

LICENSE=			MIT
LICENSE_FILE=		${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	only tested on x86

BUILD_DEPENDS=	llvm${LLVM_VERSION}>=0:devel/llvm${LLVM_VERSION} \
				opencl>=2.1:devel/opencl
LIB_DEPENDS=	libhwloc.so:devel/hwloc \
				libOpenCL.so:devel/ocl-icd \
				libltdl.so:devel/libltdl
RUN_DEPENDS=	${BUILD_DEPENDS}

LLVM_VERSION=	${MESA_LLVM_VER:U90}

USES=			cmake localbase:ldflags ncurses pkgconfig

USE_GITHUB=		yes
USE_LDCONFIG=	yes

CMAKE_ARGS=		-DWITH_LLVM_CONFIG="${LOCALBASE}/llvm${LLVM_VERSION}/bin/llvm-config" \
				-DPOCL_INSTALL_PKGCONFIG_DIR="${PREFIX}/libdata/pkgconfig" \
				-DKERNELLIB_HOST_CPU_VARIANTS="distro" \
				-DSINGLE_LLVM_LIB=OFF

PLIST_SUB=		CONFIGURE_TARGET=${CONFIGURE_TARGET:S/amd64/x86_64/}

OPTIONS_DEFINE=	DOCS

DOCS_DESC=		Build documentation (needs sphinx)
DOCS_CMAKE_OFF=	-DENABLE_DOCS=OFF
DOCS_CMAKE_ON=	-DENABLE_DOCS=ON
DOCS_USES=		python
DOCS_BUILD_DEPENDS=	${PY_FLAVOR}-sphinx>0:textproc/py-sphinx@${PY_FLAVOR}

.include <bsd.port.mk>
