PORTNAME=	mold
DISTVERSIONPREFIX=  v
DISTVERSION=	2.31.0
PORTREVISION=	2
CATEGORIES=	devel

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modern Linker
WWW=		https://github.com/rui314/mold

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

NOT_FOR_ARCHS=	armhf armv7 i386

LIB_DEPENDS=	libmimalloc.so:devel/mimalloc \
		libtbb.so:devel/onetbb \
		libzstd.so:archivers/zstd

USES=		cmake ssl localbase:ldflags

USE_GITHUB=	yes
GH_ACCOUNT=	rui314

CMAKE_ON=	MOLD_USE_MIMALLOC \
		MOLD_USE_SYSTEM_MIMALLOC \
		MOLD_USE_SYSTEM_TBB

CMAKE_OFF=	MOLD_USE_MOLD \
		MOLD_USE_TSAN \
		MOLD_MOSTLY_STATIC \
		BUILD_TESTING \
		MOLD_LTO

OPTIONS_DEFINE= ASAN

ASAN_DESC= 	Enable Address Sanitizer
ASAN_CMAKE_BOOL=MOLD_USE_ASAN

PLIST_FILES=	bin/ld.mold \
		bin/mold \
		lib/mold/mold-wrapper.so \
		libexec/mold/ld \
		share/man/man1/ld.mold.1.gz \
		share/man/man1/mold.1.gz

.include <bsd.port.mk>
