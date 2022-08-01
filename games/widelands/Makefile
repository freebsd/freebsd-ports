PORTNAME=	widelands
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Realtime strategy game inspired by Settlers II

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png \
		libicuuc.so:devel/icu \
		libboost_system.so:devel/boost-libs \
		libcurl.so:ftp/curl

USES=		cmake compiler:c++11-lib cpe gettext gl python:build sdl
USE_GITHUB=	yes
USE_GL=		gl glew
USE_SDL=	sdl2 mixer2 image2 ttf2
CMAKE_ARGS=	-DWL_INSTALL_BASEDIR="${PREFIX}" \
		-DWL_INSTALL_DATADIR="${DATADIR}" \
		-DWL_INSTALL_DOCDIR="${DOCSDIR}" \
		-DWL_VERSION="${DISTVERSION}" \
		-DWL_OPTIMIZE_FLAGS="" \
		-Wno-dev

PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS LTO NLS TEST
OPTIONS_DEFAULT=LTO
OPTIONS_EXCLUDE_powerpc64=	LTO
OPTIONS_EXCLUDE_riscv64=	LTO

LTO_CMAKE_ON=	-DUSE_FLTO_IF_AVAILABLE:STRING="yes"
NLS_CMAKE_BOOL=	OPTION_BUILD_TRANSLATIONS
TEST_CMAKE_BOOL=OPTION_BUILD_TESTS

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

.include <bsd.port.mk>
