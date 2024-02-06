PORTNAME=	mold
DISTVERSIONPREFIX=  v
DISTVERSION=	2.4.0
CATEGORIES=	devel

# See https://github.com/rui314/mold/pull/1187
PATCHFILES=	8c99dd0f2c165e36efd4fad762158ec13004b86a.patch:-p1
PATCH_SITES=	https://github.com/rui314/mold/commit/

MAINTAINER=	ashish@FreeBSD.org
COMMENT=	Modern Linker
WWW=		https://github.com/rui314/mold

LICENSE=	AGPLv3
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
