# Created by: Bartosz Fabianowski <freebsd@chillt.de>
# $FreeBSD$

PORTNAME=	widelands
DISTVERSION=	build18
PORTREVISION=	6
CATEGORIES=	games
MASTER_SITES=	https://launchpadlibrarian.net/167260749/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Realtime strategy game inspired by Settlers II

LICENSE=	GPLv2 # or later
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USES=		cmake:outsource compiler:c++11-lib gettext lua:51 tar:bzip2 python:build
CMAKE_ARGS=	-DWL_INSTALL_PREFIX="${PREFIX}" \
		-DWL_INSTALL_DATADIR="share/widelands" \
		-DWL_INSTALL_BINDIR="bin" \
		-DWL_VERSION="${DISTVERSION}" \
		-DWL_COMPILERFLAG_OPTIMIZATIONS=""
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

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 900000
IGNORE=		doesn't build on 8.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

.include <bsd.port.mk>
