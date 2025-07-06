PORTNAME=	netgen
PORTVERSION=	6.2.2501
DISTVERSIONPREFIX=	v
CATEGORIES=	cad

PATCH_SITES=	https://github.com/alexxy/netgen/commit/

MAINTAINER=	alven@FreeBSD.org
COMMENT=	Automatic 3D tetrahedral mesh generator
WWW=		https://ngsolve.org/ \
		https://github.com/NGSolve/ngsolve/

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=			i386
NOT_FOR_ARCHS_REASON_i386=	unsupported CPU architecture

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		git:devel/git

USES=		cmake gl localbase:ldflags python tcl tk xorg

# Patch to fix build with JPEG enabled
# Issue https://github.com/NGSolve/netgen/issues/210
# Bug https://bugs.gentoo.org/947728
PATCHFILES+=	3d82bf88360b9d032671a72a31cd9c351bf674f8.patch:-p1
# Patch to fix build with MPEG enabled
# Issue https://github.com/NGSolve/netgen/issues/192
PATCHFILES+=	8737bff2bfec303b4affd06be9f44acd4b13f34d.patch:-p1

USE_GITHUB=	yes
GH_ACCOUNT=	NGSolve
GH_TUPLE=	NGSolve:pybind11:v2.11.1:pybind11/external_dependencies/pybind11

USE_GL=		gl glu
USE_LDCONFIG=	yes
USE_XORG=	x11 xi xmu

CMAKE_OFF=	USE_NATIVE_ARCH USE_OCC

CFLAGS+=	-I${TK_INCLUDEDIR}/generic -I${TK_INCLUDEDIR}/unix
CXXFLAGS+=	-I${TK_INCLUDEDIR}/generic -I${TK_INCLUDEDIR}/unix
LDFLAGS+=	-lexecinfo

CONFLICTS_INSTALL=	libvisual pybind11 # bin/netgen include/pybind11/attr.h lib/libvisual.so

OPTIONS_DEFINE=	CGNS JPEG MPEG

CGNS_DESC=	Enable CGNS file read/write support
JPEG_DESC=	Enable snapshots using jpeg
MPEG_DESC=	Enable recording with FFmpeg

CGNS_BROKEN=	compiler errors
CGNS_LIB_DEPENDS=	libcgns.so:science/cgnslib
CGNS_CMAKE_BOOL=	USE_CGNS
JPEG_USES=		jpeg
JPEG_CMAKE_BOOL=	USE_JPEG
MPEG_LIB_DEPENDS=	libavcodec.so:multimedia/ffmpeg
MPEG_CMAKE_BOOL=	USE_MPEG

post-install:
	(cd ${STAGEDIR}${PREFIX}/bin && ${STRIP_CMD} netgen)
	(cd ${STAGEDIR}${PREFIX}/lib && ${STRIP_CMD} libngcore.so libnggui.so libnglib.so)
	(cd ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/${PORTNAME} && ${STRIP_CMD} libngguipy.so libngpy.so)

.include <bsd.port.mk>
