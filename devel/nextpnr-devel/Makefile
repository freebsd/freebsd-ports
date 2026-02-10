PORTNAME=	nextpnr
PORTVERSION=	g20250208
CATEGORIES=	devel
PKGNAMESUFFIX=	-devel

MAINTAINER=	jbo@FreeBSD.org
COMMENT=	Portable FPGA place and route tool
WWW=		https://github.com/YosysHQ/nextpnr

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/COPYING

NOT_FOR_ARCHS=		i386
NOT_FOR_ARCHS_REASON=	clang segfault

BUILD_DEPENDS=	${LOCALBASE}/share/trellis/database:devel/trellis \
		${LOCALBASE}/share/icebox:devel/icestorm
LIB_DEPENDS=	libboost_thread.so:devel/boost-libs \
		libboost_program_options.so:devel/boost-libs

USES=		compiler:c++17-lang cmake llvm:min=20 qt:6 eigen:3 python
USE_QT=		base
USE_GITHUB=	yes
GH_ACCOUNT=	YosysHQ
GH_TUPLE=	YosysHQ:nextpnr-tests:ce15412:tests/tests
GH_TAGNAME=	35f14336c042a9aa86cc66221434262fbb02034e

CONFLICTS_INSTALL=	nextpnr

BINARY_ALIAS=	python3=${PYTHON_CMD}

CMAKE_ARGS=	-DARCH="ice40;ecp5" \
		-DTRELLIS_ROOT=${LOCALBASE}/share/trellis/
CMAKE_OFF=	BUILD_GUI

PLIST_FILES=	bin/nextpnr-ecp5 \
		bin/nextpnr-ice40

# Don't create __pycache__ directory when executing blueprint-compiler
# This is a workaround to avoid filesystem violations during poudriere build
MAKE_ENV=	PYTHONDONTWRITEBYTECODE=1

.if exists(/usr/include/omp.h)
CMAKE_ON+=	USE_OPENMP
.else
CMAKE_OFF+=	USE_OPENMP
.endif

.include <bsd.port.mk>
