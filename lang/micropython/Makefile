PORTNAME=	micropython
PORTVERSION=	1.28.0
DISTVERSIONPREFIX=	v
CATEGORIES=	lang python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Implementation of the Python language for microcontrollers
WWW=		https://www.micropython.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		gmake pkgconfig python:,build
USE_GCC=	yes
USE_GITHUB=	yes
GH_TUPLE=	micropython:axtls:531cab9:axtls \
		micropython:berkeley-db-1.xx:0f3bb69:bdb \
		ARMmbed:mbedtls:107ea89:mbedtls \
		micropython:micropython-lib:8380c7b:mpylib

MAKE_ARGS+=	CC=${CC} CPP="${CC} -E" V=1
MAKE_ENV+=	CFLAGS_EXTRA="${CPPFLAGS} ${CFLAGS} -Wno-float-conversion" COPT=""

# required for _Float16 support
CFLAGS_i386=	-msse2

# With aarch64 (QEMU) the float_parse and the float_parse_doubleprec tests
# fail as they give a different output.
TEST_TARGET=	test

BINARY_ALIAS=	python3=${PYTHON_CMD}

BUILD_WRKSRC=	${WRKSRC}/ports/unix
TEST_WRKSRC=	${WRKSRC}/ports/unix

PLIST_FILES=	bin/micropython

post-extract:
	@${RM} -r ${WRKSRC}/lib/axtls ${WRKSRC}/lib/berkeley-db-1.xx ${WRKSRC}/lib/mbedtls \
		${WRKSRC}/lib/micropython-lib
	@${RLN} ${WRKSRC_axtls} ${WRKSRC}/lib/axtls
	@${RLN} ${WRKSRC_bdb} ${WRKSRC}/lib/berkeley-db-1.xx
	@${RLN} ${WRKSRC_mbedtls} ${WRKSRC}/lib/mbedtls
	@${RLN} ${WRKSRC_mpylib} ${WRKSRC}/lib/micropython-lib

post-patch:
	${CP} ${FILESDIR}/mpthreadport.h ${WRKSRC}/mpy-cross/

pre-test:
	${CC} -shared -o ${WRKSRC}/tests/ports/unix/ffi_lib.so \
		${WRKSRC}/tests/ports/unix/ffi_lib.c

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/build-standard/micropython ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
