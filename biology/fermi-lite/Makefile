PORTNAME=	fermi-lite
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1-13
DISTVERSIONSUFFIX=	-g85f159e
CATEGORIES=	biology devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library and tool for assembling Illumina short reads in small regions
WWW=		https://github.com/lh3/fermi-lite

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gmake
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	lh3

CFLAGS_powerpc64le=	-DNO_WARN_X86_INTRINSICS
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
