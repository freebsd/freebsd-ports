# $FreeBSD$

PORTNAME=	fp16
PORTVERSION=	g20181128
CATEGORIES=	devel

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Conversion to/from half-precision floating point formats

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	${LOCALBASE}/include/psimd.h:devel/psimd

USES=		cmake
USE_GITHUB=	yes
GH_ACCOUNT=	Maratyszcza
GH_PROJECT=	${PORTNAME:tu}
GH_TAGNAME=	febbb1c

CMAKE_OFF=	FP16_BUILD_TESTS FP16_BUILD_BENCHMARKS

NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	include/fp16.h \
		include/fp16/__init__.py \
		include/fp16/avx.py \
		include/fp16/avx2.py \
		include/fp16/bitcasts.h \
		include/fp16/fp16.h

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DFP16_BUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.mk>
