PORTNAME=	maxr
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.2.16
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Mechanized Assault and Exploration Reloaded
WWW=		https://www.maxr.org/ \
		https://github.com/maxr-dot-org/maxr/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/data/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/nlohmann/json.hpp:devel/nlohmann-json
BUILD_DEPENDS+=	${LOCALBASE}/lib/libvorbis.so:audio/libvorbis  # used to build a binary which is not installed

USES=		cmake compiler:c++17-lang sdl
USE_GITHUB=	yes
GH_ACCOUNT=	maxr-dot-org
GH_TUPLE=	oo13:spiritless_po:5d729be:spiritless_po/submodules/spiritless_po
USE_SDL=	sdl2 mixer2 net2
CMAKE_OFF=	BUILD_TESTING

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

DESKTOP_ENTRIES="M.A.X.R." \
		"" \
		"${DATADIR}/maxr.png" \
		"maxr" \
		"Game;StrategyGame;" \
		false

.include <bsd.port.mk>
