# Created by: ijliao
# $FreeBSD$

PORTNAME=	sdl_gfx
PORTVERSION=	2.0.26
CATEGORIES=	graphics
MASTER_SITES=	http://www.ferzkopp.net/Software/SDL_gfx-${PORTVERSION:R}/
DISTNAME=	SDL_gfx-${PORTVERSION}

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	SDL graphics drawing primitives and other support functions

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		autoreconf gmake libtool pathfix sdl
USE_SDL=	sdl
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE_i386=	MMX
OPTIONS_DEFINE_amd64=	MMX
OPTIONS_DEFAULT_amd64=	MMX

MMX_CONFIGURE_ENABLE=	mmx
MMX_CFLAGS=		-DUSE_MMX

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MMMX}
# Every platform not supporting the MMX knob must disable
# MMX support explicitly
CONFIGURE_ARGS+=	--disable-mmx
.endif

post-patch:
#	angled includes changed in 2.0.26 break some of dependent ports:
#	- multimedia/mjpegtools
#	- games/qonk
#	- games/hyperrogue
	@${REINPLACE_CMD} -e 's|<SDL.h>|"SDL.h"|; s|<SDL_video.h>|"SDL_video.h"|' \
		${WRKSRC}/*.h

.include <bsd.port.mk>
