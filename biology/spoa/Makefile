# $FreeBSD$

PORTNAME=	spoa
DISTVERSION=	4.0.7
PORTREVISION=	2
CATEGORIES=	biology

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ implementation of the partial order alignment (POA) algorithm

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bioparser>0:biology/bioparser \
		${LOCALBASE}/include/biosoup/nucleic_acid.hpp:biology/biosoup \
		cereal>0:devel/cereal \
		simde>0:devel/simde
LIB_DEPENDS=	libcpu_features.so:devel/cpu_features
RUN_DEPENDS=	cereal>0:devel/cereal
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake compiler:c++11-lang localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	rvaser

CMAKE_ON=	BUILD_SHARED_LIBS spoa_optimize_for_portability spoa_build_executable spoa_use_simde spoa_use_simde_nonvec spoa_use_simde_openmp
CMAKE_OFF=	spoa_optimize_for_native

LDFLAGS+=	-lz -lcpu_features

.include <bsd.port.options.mk>

.if ${ARCH} == amd64 || ${ARCH} == i386
CMAKE_ARGS+=	-Dspoa_generate_dispatch:BOOL=ON
.endif

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -D${PORTNAME}_build_tests:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${BUILD_WRKSRC}/bin/${PORTNAME}_test

.include <bsd.port.mk>
