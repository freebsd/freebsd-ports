# $FreeBSD$

PORTNAME=	libcelero
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.0
CATEGORIES=	benchmarks

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	C++ benchmark authoring library/framework

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/license.txt

BUILD_DEPENDS=	${LOCALBASE}/include/sys/sysinfo.h:devel/libsysinfo
LIB_DEPENDS=	libsysinfo.so:devel/libsysinfo
TEST_DEPENDS=	googletest>0:devel/googletest

USES=		cmake compiler:c++14-lang localbase:ldflags
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	DigitalInBlue
GH_PROJECT=	Celero

LDFLAGS+=	-lsysinfo

.include <bsd.port.pre.mk>

.if ${CHOSEN_COMPILER_TYPE} == gcc
USE_GCC=	yes
.else
.  if ${ARCH:Mpowerpc64*}
CFLAGS+=	-mabi=elfv2
.  endif
.endif

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DCELERO_ENABLE_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${BUILD_WRKSRC}/celero-test

.include <bsd.port.post.mk>
