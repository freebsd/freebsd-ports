PORTNAME=	endless-sky
PORTVERSION=	0.10.10
PORTREVISION=	1
DISTVERSIONPREFIX=	v
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Space exploration and combat game similar to Escape Velocity
WWW=		https://endless-sky.github.io/

LICENSE=	GPLv3+ GPLv2 CC-BY-2.0 CC-BY-3.0 CC-BY-4.0 CC-BY-SA-3.0 CC-BY-SA-4.0 PD CC0-1.0
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/copyright
LICENSE_FILE_GPLv3+ =	${WRKSRC}/license.txt

LIB_DEPENDS=	libpng.so:graphics/png \
		libmad.so:audio/libmad \
		libuuid.so:misc/libuuid

USE_GITHUB=	yes

USES=		cmake compiler:c++11-lang gl jpeg openal sdl
USE_SDL=	sdl2
USE_GL=		gl glew
CMAKE_OFF=	ES_USE_VCPKG CMAKE_CXX_SCAN_FOR_MODULES
CMAKE_ARGS=	-DCMAKE_INSTALL_DOCDIR="${DOCSDIR}"
# https://github.com/endless-sky/endless-sky/issues/10714#issuecomment-2448722018
TEST_ENV=	ASAN_OPTIONS=detect_container_overflow=0

LDFLAGS_i386=	-Wl,-znotext

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS TEST

TEST_CMAKE_BOOL=	BUILD_TESTING
TEST_BUILD_DEPENDS=	catch2>=0:devel/catch2

post-build:
	@${REINPLACE_CMD} -e 's|/usr/local/|${PREFIX}/|; s|share/games|share|' \
		${WRKSRC}/source/Files.cpp

do-test-TEST-on:
	@cd ${TEST_WRKSRC} && ${SETENV} ${TEST_ENV} ${LOCALBASE}/bin/ctest -V

.include <bsd.port.mk>
