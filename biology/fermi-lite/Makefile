PORTNAME=	fermi-lite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1-13
DISTVERSIONSUFFIX=	-g85f159e
PORTREVISION=	2
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and tool for assembling Illumina short reads in small regions
WWW=		https://github.com/lh3/fermi-lite

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

ONLY_FOR_ARCHS=		aarch64 amd64 armv7 i386 powerpc64le
ONLY_FOR_ARCHS_REASON=	Use of the <emmintrin.h> header in ksw.c which is only for SSE2

armv7_BUILD_DEPENDS=	${LOCALBASE}/include/sse2neon.h:devel/sse2neon
aarch64_BUILD_DEPENDS=	${armv7_BUILD_DEPENDS}
BUILD_DEPENDS+=	${${ARCH}_BUILD_DEPENDS}

USES=		gmake localbase
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	lh3

CFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS # not sure if it was really ever built on powerpc64le - from pkubaj: yes, it builds
CFLAGS_i386=	-msse2
MAKE_ARGS=	CFLAGS="${CFLAGS}"

BINARY_ALIAS=	gcc=${CC}

PLIST_FILES=	bin/fml-asm \
		include/fml.h \
		lib/libfml.a \
		lib/libfml.so

post-build:
		@cd ${WRKSRC} && \
			${CC} ${CFLAGS} -fPIC ${LDFLAGS} -shared $$(ls *.c | grep -v example.c) -o libfml.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/fml-asm ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/fml.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libfml.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_LIB} ${WRKSRC}/libfml.so ${STAGEDIR}${PREFIX}/lib

.include <bsd.port.mk>
