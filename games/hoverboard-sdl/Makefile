# Created by: Dmitry Marakasov <amdmi3@FreeBSD.org>
# $FreeBSD$

PORTNAME=	hoverboard
PORTVERSION=	0.7.3
PORTREVISION=	5
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Standalone version of xkcd 1608 "Hoverboard" game

LICENSE=	GPLv3+ CC-BY-NC-2.5
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3+ =	${WRKSRC}/COPYING

LIB_DEPENDS=	libSDL2pp.so:devel/sdl2pp

USE_GITHUB=	yes
GH_ACCOUNT=	AMDmi3
GH_PROJECT=	${PORTNAME}-sdl

USES=		cmake compiler:c++11-lib
CMAKE_ARGS=	-DSYSTEMWIDE=ON
USE_SDL=	sdl2 image2 ttf2 mixer2

PORTDATA=	*
PORTDOCS=	*
PLIST_FILES=	bin/${PORTNAME} \
		share/applications/${PORTNAME}.desktop

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
