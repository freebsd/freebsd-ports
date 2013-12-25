# Created by: neuroworker@gmail.com
# $FreeBSD$

PORTNAME=	instead
PORTVERSION=	1.9.1
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/instead/instead/${PORTVERSION}/ \
		http://mirror.amdmi3.ru/distfiles/
DISTNAME=	instead_${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Simple Text Adventure, The Interpreter

HAS_CONFIGURE=	yes
USES=		pkgconfig iconv gmake
USE_GNOME=	gtk20
USE_LUA=	5.1
LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

CONFIGURE_SCRIPT=	configure.sh
CONFIGURE_ENV=	PREFIX="${PREFIX}"

WRKSRC=		${WRKDIR}/instead-${PORTVERSION}

PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=SDL
OPTIONS_SINGLE=	SDL_VERSION
OPTIONS_SINGLE_SDL_VERSION=	SDL SDL2

SDL_VERSION_DESC=SDL version
SDL_DESC=	Use SDL 1.2
SDL2_DESC=	Use SDL 2.0

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSDL2}
USE_SDL=	sdl2 image2 ttf2 mixer2

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|&-nonexistent|' ${WRKSRC}/configure.sh
.else
USE_SDL=	sdl image ttf mixer

post-patch:
	@${REINPLACE_CMD} -e 's|sdl2-config|&-nonexistent|' ${WRKSRC}/configure.sh
.endif

.include <bsd.port.mk>
