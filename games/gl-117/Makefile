# ex:ts=8
# Ports collection makefile for:	gl-117
# Date created:			Aug 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gl-117
PORTVERSION=	0.6
CATEGORIES=	games
MASTER_SITES=	http://home.t-online.de/home/Primetime./gl-117/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL-1.1:${PORTSDIR}/devel/sdl12 \
		SDL_mixer:${PORTSDIR}/audio/sdl_mixer

USE_REINPLACE=	yes
USE_MESA=	yes
GNU_CONFIGURE=	yes
CFLAGS+=	${PTHREAD_CFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS}" \
		LDFLAGS="${PTHREAD_LIBS} -L${LOCALBASE}/lib -L${X11BASE}/lib -lGL -lGLU -lglut -lstdc++"

post-patch:
.for file in configure src/audio.h src/main.h src/net.h
	@${REINPLACE_CMD} -e "s|SDL/|SDL11/|g" -e "s|-lSDL |-lSDL-1.1 |g" \
		-e "s|-lSDLmain|-lSDLmain-1.1|g" ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
