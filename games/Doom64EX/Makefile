PORTNAME=	Doom64EX
PORTVERSION=	g20180824
CATEGORIES=	games

MAINTAINER=	pkubaj@FreeBSD.org
COMMENT=	Project aimed to recreate Doom64

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfluidsynth.so:audio/fluidsynth \
		libpng.so:graphics/png

USES=		cmake sdl
USE_GITHUB=	yes
GH_ACCOUNT=	svkaiser
GH_TAGNAME=	03a5e6a5a3a14d66886f62b72431b37ef7336706
USE_SDL=	net2 sdl2

CMAKE_ON=	ENABLE_SYSTEM_FLUIDSYNTH
PLIST_FILES=	bin/doom64ex \
		share/games/doom64ex/doom64ex.pk3

.include <bsd.port.mk>
