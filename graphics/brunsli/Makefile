PORTNAME=	brunsli
PORTVERSION=	0.1
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	graphics

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lossless JPEG repacking library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libbrotlidec.so:archivers/brotli \
		libgtest_main.so:devel/googletest \
		libhighwayhash.so:security/highwayhash

USES=		cmake compiler:c++11-lang localbase:ldflags

USE_CXXSTD=	c++11

GH_ACCOUNT=	google
USE_GITHUB=	yes

post-patch:
# Clean up bundled libraries
	@${RM} -r ${WRKSRC}/third_party/

.include <bsd.port.mk>
