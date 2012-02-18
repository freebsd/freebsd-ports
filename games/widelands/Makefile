# Ports collection makefile for:        widelands
# Date created:                         8 April 2007
# Whom:                                 Bartosz Fabianowski <freebsd@chillt.de>
#
# $FreeBSD$
#

PORTNAME=	widelands
DISTVERSION=	build16
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://launchpadlibrarian.net/69520494/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Realtime strategy game inspired by Settlers II

LIB_DEPENDS=	ggzcore.9:${PORTSDIR}/games/ggz-client-libs \
		png.6:${PORTSDIR}/graphics/png \
		GLEW.1:${PORTSDIR}/graphics/glew
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USE_CMAKE=	yes
CMAKE_OUTSOURCE=yes
CMAKE_ARGS=	-DWL_INSTALL_PREFIX="${PREFIX}" \
		-DWL_INSTALL_DATADIR="share/widelands" \
		-DWL_INSTALL_BINDIR="bin" \
		-DWL_VERSION="${DISTVERSION}"
USE_LUA=	5.1+
USE_SDL=	sdl mixer image net ttf gfx
USE_PYTHON_BUILD=2.4+
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/widelands

DESKTOP_ENTRIES="Widelands" \
		"Realtime strategy game inspired by Settlers II" \
		"${DATADIR}/pics/wl-ico-64.png" \
		"widelands" \
		"Game;StrategyGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e '/ifndef/ s|__APPLE__|__FreeBSD__|' \
		${WRKSRC}/src/backtrace.cc
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

post-install:
	@${FIND} ${DATADIR} -type f | \
		${SED} -e 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} -e 's|^${PREFIX}/|@dirrm |' >> ${TMPPLIST}

.include <bsd.port.mk>
