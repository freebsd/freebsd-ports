# Created by: Bartosz Fabianowski <freebsd@chillt.de>
# $FreeBSD$

PORTNAME=	widelands
DISTVERSION=	build18
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	https://launchpadlibrarian.net/167260749/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Realtime strategy game inspired by Settlers II

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:graphics/png
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:devel/boost-libs

USES=		cmake:outsource compiler:c++11-lib execinfo gettext \
		lua:51 tar:bzip2 python:build
CMAKE_ARGS=	-DWL_INSTALL_PREFIX="${PREFIX}" \
		-DWL_INSTALL_DATADIR="share/widelands" \
		-DWL_INSTALL_BINDIR="bin" \
		-DWL_VERSION="${DISTVERSION}" \
		-DWL_COMPILERFLAG_OPTIMIZATIONS=""
USE_GL=		glew
USE_SDL=	sdl mixer image net ttf gfx

PLIST_FILES=	bin/widelands
PORTDATA=	*
PLIST_DIRS=	%%DATADIR%%/maps/Desert\ Tournament.wmf/scripting \
		%%DATADIR%%/maps/Swamp\ Monks.wmf/scripting

DESKTOP_ENTRIES="Widelands" \
		"" \
		"${DATADIR}/pics/wl-ico-64.png" \
		"widelands" \
		"Game;StrategyGame;" \
		""

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

.include <bsd.port.mk>
