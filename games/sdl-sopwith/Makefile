PORTNAME=	sdl-sopwith
DISTVERSIONPREFIX=	${PORTNAME}-
DISTVERSION=	2.9.0
CATEGORIES=	games

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Classic WW1 biplane game
WWW=		https://github.com/fragglet/sdl-sopwith \
		https://sdl-sopwith.sourceforge.net/

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING.md

USES=		autoreconf pkgconfig sdl
USE_GITHUB=	yes
GH_ACCOUNT=	fragglet
GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-hiscores-path=
USE_SDL=	sdl2

PORTDOCS=	*
OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
