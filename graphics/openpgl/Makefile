PORTNAME=	openpgl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.1
DISTVERSIONSUFFIX=	-beta
CATEGORIES=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Intel Open Path Guiding Library
WWW=		http://www.openpgl.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# supported processors -
# arm with NEON/NEON2X and x86_64 with SSE4/AVX2/AVX512
ONLY_FOR_ARCHS=		amd64 armv6 armv7
ONLY_FOR_ARCHS_REASON=	requires supported SIMD ISA

LIB_DEPENDS=	libembree3.so:graphics/embree

USES=		cmake compiler:c++11-lib
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	OpenPathGuidingLibrary

OPTIONS_DEFINE=		TBB
OPTIONS_DEFAULT=	TBB

TBB_DESC=		Use Intels TBB instead of openMP
# we disable TBB by enabling use of OpenMP
TBB_CMAKE_BOOL_OFF=	OPENPGL_USE_OMP_THREADING
TBB_LIB_DEPENDS=	libtbb.so:devel/onetbb

.include <bsd.port.mk>
