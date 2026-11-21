PORTNAME=	dethrace
DISTVERSIONPREFIX=	v
DISTVERSION=	0.11.0
CATEGORIES=	games

MAINTAINER=	eduardo@FreeBSD.org
COMMENT=	Reverse engineering the 1997 game "Carmageddon"
WWW=		https://github.com/dethrace-labs/dethrace

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cmake sdl
USE_GITHUB=	yes
GH_ACCOUNT=	dethrace-labs
GH_TUPLE=	dethrace-labs:BRender-v1.3.2:d874c6f7946ba7aaf492928b212e022c4cece1a4:brender/lib/BRender-v1.3.2
USE_SDL=	sdl3

CMAKE_ON=	DETHRACE_INSTALL DETHRACE_PLATFORM_SDL3
CMAKE_OFF=	DETHRACE_PLATFORM_SDL1 DETHRACE_PLATFORM_SDL2 \
		DETHRACE_PLATFORM_SDL_DYNAMIC

LDFLAGS+=	-lexecinfo

PLIST_FILES=	bin/${PORTNAME}

post-extract:
	@${ECHO_CMD} "${DISTVERSION}" > ${WRKSRC}/VERSION

.include <bsd.port.mk>
