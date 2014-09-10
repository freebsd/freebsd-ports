# Created by: Yukihiro Nakai <nakai@FreeBSD.org>
# $FreeBSD$

PORTNAME=	gngb
PORTVERSION=	20060309
PORTREVISION=	6
CATEGORIES=	emulators
MASTER_SITES=	http://m.peponas.free.fr/gngb/download/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GameBoy(tm) emulator

USE_SDL=	sdl
USES=	gmake
GNU_CONFIGURE=	yes
USE_CSTD=	gnu89

PLIST_FILES=	bin/gngb \
		man/man1/gngb.1.gz

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib


.if defined(WITH_GL)
USE_GL=		gl
.else
CONFIGURE_ARGS+=	--disable-gl
.endif

pre-everything::
.if !defined(WITH_GL)
	@${ECHO_MSG}
	@${ECHO_MSG} "You can enable OpenGL support by defining WITH_GL"
	@${ECHO_MSG}
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lpthread|${PTHREAD_LIBS}|g ; \
		 s|"$$SDL_CONFIG" = yes|-n "$$SDL_CONFIG"|g ; \
		 s|sdl-config |$$SDL_CONFIG |g ; \
		 s|$$OPT||g' ${WRKSRC}/configure

.include <bsd.port.mk>
