PORTNAME=	netgen
DISTVERSIONPREFIX=	v
DISTVERSION=	6.2.2607
CATEGORIES=	cad

PATCH_SITES=	https://github.com/alexxy/netgen/commit/
# Patch to fix build with JPEG enabled
# Issue https://github.com/NGSolve/netgen/issues/210
# Bug https://bugs.gentoo.org/947728
PATCHFILES+=	3d82bf88360b9d032671a72a31cd9c351bf674f8.patch:-p1
# Patch to fix build with MPEG enabled
# Issue https://github.com/NGSolve/netgen/issues/192
PATCHFILES+=	8737bff2bfec303b4affd06be9f44acd4b13f34d.patch:-p1

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Automatic 3D tetrahedral mesh generator
WWW=		https://ngsolve.org/ \
		https://github.com/NGSolve/ngsolve/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	i386
NOT_FOR_ARCHS_REASON_i386=	unsupported CPU architecture

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pybind11>=0:devel/py-pybind11@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytest>0:devel/py-pytest@${PY_FLAVOR} \
		git:devel/git

USES=		cmake gl localbase:ldflags pkgconfig python tcl tk xorg
USE_GITHUB=	yes
GH_ACCOUNT=	NGSolve
USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_XORG=	x11 xi xmu

CMAKE_ARGS=	-Dpybind11_DIR=${PYTHON_SITELIBDIR}/pybind11/share/cmake/pybind11
CMAKE_ON=	PREFER_SYSTEM_PYBIND11 USE_PYTHON
CMAKE_OFF=	BUILD_STUB_FILES USE_NATIVE_ARCH USE_OCC USE_SUPERBUILD

CFLAGS+=	-I${TK_INCLUDEDIR}/generic -I${TK_INCLUDEDIR}/unix
CXXFLAGS+=	-I${TK_INCLUDEDIR}/generic -I${TK_INCLUDEDIR}/unix
LDFLAGS+=	-lexecinfo

CONFLICTS_INSTALL=	netgen-lvs # bin/netgen

OPTIONS_DEFINE=	CGNS JPEG MPEG

CGNS_DESC=	Enable CGNS file read/write support
JPEG_DESC=	Enable snapshots using jpeg
MPEG_DESC=	Enable recording with FFmpeg

CGNS_BROKEN=		compiler errors
CGNS_LIB_DEPENDS=	libcgns.so:science/cgnslib
CGNS_CMAKE_BOOL=	USE_CGNS
JPEG_USES=		jpeg
JPEG_CMAKE_BOOL=	USE_JPEG
MPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
MPEG_CMAKE_BOOL=	USE_MPEG

.include <bsd.port.mk>
