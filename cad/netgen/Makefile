# Created by: Thierry Thomas <thierry@FreeBSD.org>

PORTNAME=	netgen
PORTVERSION=	6.2.2103
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	cad

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	Automatic 3D tetrahedral mesh generator

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=		amd64 i386
ONLY_FOR_ARCHS_REASON=	relies on rdtsc() call and the TSC is specific to x86

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pytest>=0:devel/py-pytest@${PY_FLAVOR} \
		git:devel/git

USES=		cmake python tcl tk gl xorg

USE_GITHUB=	yes
GH_ACCOUNT=	NGSolve
GH_TUPLE=	NGSolve:pybind11:v2.4.3:pybind11/external_dependencies/pybind11

USE_GL=		gl glu
USE_XORG=	x11 xmu xi
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include -I${TK_INCLUDEDIR}/generic -I${TK_INCLUDEDIR}/unix
CXXFLAGS+=	-I${LOCALBASE}/include -I${TK_INCLUDEDIR}/generic -I${TK_INCLUDEDIR}/unix
LDFLAGS+=	-lexecinfo

OPTIONS_DEFINE=	JPEG MPEG CGNS

JPEG_DESC=	Enable snapshots using jpeg
MPEG_DESC=	Enable recording with FFmpeg
CGNS_DESC=	Enable CGNS file read/write support

JPEG_CMAKE_BOOL=	USE_JPEG
JPEG_USES=		jpeg
MPEG_CMAKE_BOOL=	USE_MPEG
MPEG_LIB_DEPENDS=	libavcodec.so:multimedia/libav
CGNS_CMAKE_BOOL=	USE_CGNS
CGNS_LIB_DEPENDS=	libcgns.so:science/cgnslib

.include <bsd.port.mk>
