PORTNAME=	maxr
DISTVERSIONPREFIX=	release-
DISTVERSION=	0.2.11
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Mechanized Assault and Exploration Reloaded
WWW=		https://www.maxr.org/ \
		https://github.com/maxr-dot-org/maxr/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/data/COPYING

USES=		cmake compiler:c++17-lang sdl
USE_GITHUB=	yes
GH_ACCOUNT=	maxr-dot-org
USE_SDL=	sdl2 mixer2 net2

PLIST_FILES=	bin/${PORTNAME}
PORTDATA=	*

DESKTOP_ENTRIES="M.A.X.R." \
		"" \
		"${DATADIR}/maxr.png" \
		"maxr" \
		"Game;StrategyGame;" \
		false

.include <bsd.port.mk>
