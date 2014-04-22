# Created by: Bartosz Fabianowski <freebsd@chillt.de>
# $FreeBSD$

PORTNAME=	widelands
DISTVERSION=	build18
CATEGORIES=	games
MASTER_SITES=	https://launchpadlibrarian.net/167260749/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Realtime strategy game inspired by Settlers II

LIB_DEPENDS=	libpng.so:${PORTSDIR}/graphics/png \
		libGLEW.so:${PORTSDIR}/graphics/glew \
		libexecinfo.so:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USES=		tar:bzip2 cmake:outsource gettext compiler:c++11-lib
CMAKE_ARGS=	-DWL_INSTALL_PREFIX="${PREFIX}" \
		-DWL_INSTALL_DATADIR="share/widelands" \
		-DWL_INSTALL_BINDIR="bin" \
		-DWL_VERSION="${DISTVERSION}" \
		-DWL_COMPILERFLAG_OPTIMIZATIONS=""
USE_LUA=	5.1
USE_SDL=	sdl mixer image net ttf gfx
USE_PYTHON_BUILD=yes

PLIST_FILES=	bin/widelands
PORTDATA=	*

DESKTOP_ENTRIES="Widelands" \
		"" \
		"${DATADIR}/pics/wl-ico-64.png" \
		"widelands" \
		"Game;StrategyGame;" \
		""

.include <bsd.port.options.mk>

.if ${OSVERSION} < 900000
IGNORE=		doesn't build on 8.x
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

.include <bsd.port.mk>
