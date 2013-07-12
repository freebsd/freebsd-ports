# Created by: Bartosz Fabianowski <freebsd@chillt.de>
# $FreeBSD$

PORTNAME=	widelands
DISTVERSION=	build17
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	https://launchpadlibrarian.net/102893896/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	${PORTNAME}-${DISTVERSION}-src

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Realtime strategy game inspired by Settlers II

LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		GLEW:${PORTSDIR}/graphics/glew \
		execinfo:${PORTSDIR}/devel/libexecinfo
BUILD_DEPENDS=	${LOCALBASE}/include/boost/shared_ptr.hpp:${PORTSDIR}/devel/boost-libs

USE_BZIP2=	yes
USES=		cmake:outsource gettext
CMAKE_ARGS=	-DWL_INSTALL_PREFIX="${PREFIX}" \
		-DWL_INSTALL_DATADIR="share/widelands" \
		-DWL_INSTALL_BINDIR="bin" \
		-DWL_VERSION="${DISTVERSION}"
USE_LUA=	5.1+
USE_SDL=	sdl mixer image net ttf gfx
USE_PYTHON_BUILD=2.5+
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/widelands

DESKTOP_ENTRIES="Widelands" \
		"Realtime strategy game inspired by Settlers II" \
		"${DATADIR}/pics/wl-ico-64.png" \
		"widelands" \
		"Game;StrategyGame;" \
		false

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|' \
		${WRKSRC}/cmake/Modules/*.cmake

post-install:
	@${FIND} ${DATADIR} -type f | \
		${SED} -e 's|^${PREFIX}/||' >> ${TMPPLIST}
	@${FIND} ${DATADIR} -type d | ${SORT} -r | \
		${SED} -e 's|^${PREFIX}/|@dirrm |' >> ${TMPPLIST}

.include <bsd.port.mk>
