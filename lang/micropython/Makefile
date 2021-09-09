PORTNAME=	micropython
PORTVERSION=	1.17
DISTVERSIONPREFIX=	v
CATEGORIES=	lang python

MAINTAINER=	python@FreeBSD.org
COMMENT=	Implementation of the Python language for microcontrollers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_armv6=	fails to assemble: error: invalid operand for instruction
BROKEN_armv7=	fails to assemble: error: invalid operand for instruction

LIB_DEPENDS=	libffi.so:devel/libffi

USES=		gmake pkgconfig python:,build
USE_GCC=	yes
USE_GITHUB=	yes
GH_TUPLE=	micropython:axtls:531cab9:axtls \
		pfalcon:berkeley-db-1.xx:35aaec4:bdb

MAKE_ARGS+=	CC=${CC} CPP="${CC} -E" V=1
MAKE_ENV+=	CFLAGS_EXTRA="${CPPFLAGS} ${CFLAGS} -Wno-float-conversion" COPT=""

# With aarch64 (QEMU) the float_parse and the float_parse_doubleprec tests
# fail as they give a different output.
TEST_TARGET=	test

BINARY_ALIAS=	python3=${PYTHON_CMD}

BUILD_WRKSRC=	${WRKSRC}/ports/unix
TEST_WRKSRC=	${WRKSRC}/ports/unix

PLIST_FILES=	bin/micropython

post-extract:
	@${RM} -r ${WRKSRC}/lib/axtls ${WRKSRC}/lib/berkeley-db-1.xx
	@${RLN} ${WRKSRC_axtls} ${WRKSRC}/lib/axtls
	@${RLN} ${WRKSRC_bdb} ${WRKSRC}/lib/berkeley-db-1.xx

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/micropython ${STAGEDIR}${PREFIX}/bin

.include <bsd.port.mk>
