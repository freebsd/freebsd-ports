PORTNAME=	openpgl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.6.0
PORTREVISION=	1
#DISTVERSIONSUFFIX=	-beta
CATEGORIES=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Intel Open Path Guiding Library
WWW=		http://www.openpgl.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# supported processors -
# arm with NEON/NEON2X and x86_64/x86 with SSE/AVX/AVX2/AVX512
ONLY_FOR_ARCHS=		aarch64 amd64 armv6 armv7 i386
ONLY_FOR_ARCHS_REASON=	requires supported SIMD ISA

LIB_DEPENDS=	libtbb.so:devel/onetbb

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	OpenPathGuidingLibrary
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.mk>
