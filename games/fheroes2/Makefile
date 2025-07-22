PORTNAME=	fheroes2
PORTVERSION=	1.1.10
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Free implementation of Heroes of Might and Magic II engine
WWW=		https://ihhub.github.io/fheroes2/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	timidity:audio/timidity

USES=		cmake sdl
USE_GITHUB=	yes
GH_ACCOUNT=	ihhub
USE_SDL=	mixer2 sdl2

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
