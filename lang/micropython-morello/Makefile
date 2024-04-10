PORTNAME=	micropython-morello
PORTVERSION=	1.17
DISTVERSIONPREFIX=	v
PORTREVISION=	2
CATEGORIES=	lang python

MAINTAINER=	Duncan.Lowther@glasgow.ac.uk
COMMENT=	Implementation of the Python language for microcontrollers ported to Arm Morello
WWW=		https://www.micropython.org/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=	fails to assemble: error: invalid operand for instruction
BROKEN_armv7=	fails to assemble: error: invalid operand for instruction

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		gmake pkgconfig python:,build
USE_GITHUB=	yes
GH_ACCOUNT=	glasgowPLI
GH_TAGNAME=	201951645afb7cd0990c95144e204e1f536761db
GH_TUPLE=	micropython:axtls:531cab9:axtls \
		Mbed-TLS:mbedtls:v2.28.3:mtls \
		pfalcon:berkeley-db-1.xx:35aaec4:bdb \
		micropython:micropython-lib:v1.22.2:mpylib \

MAKE_ARGS+=	CC="${CC}" CPP="${CC} -E" V=1
MAKE_ENV+=	CFLAGS_EXTRA="${CPPFLAGS} ${CFLAGS} -Wno-float-conversion" COPT=""

# With aarch64 (QEMU) the float_parse and the float_parse_doubleprec tests
# fail as they give a different output.
TEST_TARGET=	test

BINARY_ALIAS=	python3=${PYTHON_CMD}

BUILD_WRKSRC=	${WRKSRC}/ports/unix
TEST_WRKSRC=	${WRKSRC}/ports/unix

PLIST_FILES=	bin/micropython

post-extract:
	@${RM} -r ${WRKSRC}/lib/axtls ${WRKSRC}/lib/mbedtls ${WRKSRC}/lib/berkeley-db-1.xx ${WRKSRC}/lib/micropython-lib
	@${RLN} ${WRKSRC_axtls} ${WRKSRC}/lib/axtls
	@${RLN} ${WRKSRC_mtls}	${WRKSRC}/lib/mbedtls
	@${RLN} ${WRKSRC_bdb} ${WRKSRC}/lib/berkeley-db-1.xx
	@${RLN} ${WRKSRC_mpylib} ${WRKSRC}/lib/micropython-lib

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/build-standard/micropython ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
