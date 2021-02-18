# $FreeBSD$

PORTNAME=	opengv
DISTVERSION=	g20200806
CATEGORIES=	graphics

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Collection of methods for solving geometric vision problems

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/License.txt

USES=		cmake compiler:c++11-lib eigen:3
USE_LDCONFIG=	yes

USE_GITHUB=	yes
GH_ACCOUNT=	laurentkneip
GH_TAGNAME=	91f4b19

CMAKE_ON=	BUILD_SHARED_LIBS
CMAKE_OFF=	BUILD_TESTS

do-test:
	@cd ${BUILD_WRKSRC} && \
		${SETENV} ${CONFIGURE_ENV} ${CMAKE_BIN} ${CMAKE_ARGS} -DBUILD_TESTS:BOOL=ON ${CMAKE_SOURCE_PATH} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} ${ALL_TARGET} && \
		${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_ARGS} test

.include <bsd.port.pre.mk>

# disable march-native on non-x86 archs
.if ${ARCH} != amd64 && ${ARCH} != i386
EXTRA_PATCHES+=	${PATCHDIR}/extra-patch-CMakeLists.txt
.endif

.include <bsd.port.post.mk>
