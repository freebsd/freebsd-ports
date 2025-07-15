PORTNAME=	widelands
DISTVERSIONPREFIX=	v
DISTVERSION=	1.2
PORTREVISION=	4
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Realtime strategy game inspired by Settlers II
WWW=		https://wl.widelands.org/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libicuuc.so:devel/icu \
		libboost_system.so:devel/boost-libs \
		libminizip.so:archivers/minizip
BUILD_DEPENDS=	${PREFIX}/include/asio.hpp:net/asio

USES=		cmake compiler:c++11-lib cpe gettext gl pkgconfig \
		python:build sdl
USE_GITHUB=	yes
USE_GL=		gl glew
USE_SDL=	sdl2 mixer2 image2 ttf2
CMAKE_ARGS=	-DWL_INSTALL_BINDIR=bin \
		-DWL_INSTALL_BASEDIR="${PREFIX}" \
		-DWL_INSTALL_DATADIR="${DATADIR}" \
		-DWL_INSTALL_DOCDIR="${DOCSDIR}" \
		-DWL_VERSION="${DISTVERSION}" \
		-DWL_OPTIMIZE_FLAGS="" \
		-Wno-dev
CMAKE_BUILD_TYPE=None

PORTSCOUT=	limit:^[0-9]+\.

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS LTO NLS TEST
OPTIONS_DEFAULT=LTO
OPTIONS_EXCLUDE_riscv64=	LTO

LTO_CMAKE_ON=	-DUSE_FLTO_IF_AVAILABLE:STRING="yes"
NLS_CMAKE_BOOL=	OPTION_BUILD_TRANSLATIONS
TEST_CMAKE_BOOL=OPTION_BUILD_TESTS

post-extract:
	@${RM} -r ${WRKSRC}/src/third_party/minizip

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

.include <bsd.port.mk>
