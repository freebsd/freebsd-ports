PORTNAME=	openpgl
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.1
CATEGORIES=	graphics devel

MAINTAINER=	FreeBSD@Shaneware.biz
COMMENT=	Intel Open Path Guiding Library
WWW=		http://www.openpgl.org

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# supported processors -
# arm with NEON/NEON2X and x86_64/x86 with SSE/AVX/AVX2/AVX512
ONLY_FOR_ARCHS=		aarch64 amd64 i386
ONLY_FOR_ARCHS_REASON=	requires supported SIMD ISA

LIB_DEPENDS=	libtbb.so:devel/onetbb

USES=		cmake compiler:c++11-lib
USE_GITHUB=	yes
GH_ACCOUNT=	RenderKit
USE_LDCONFIG=	yes

PLIST_SUB=	VERSION="${PORTVERSION}"

.include <bsd.port.mk>
