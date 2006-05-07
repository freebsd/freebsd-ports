# ex:ts=8
# Ports collection makefile for:	ggz-sdl-games
# Date created:			Nov 7, 2005
# Whom:				yinjieh
#
# $FreeBSD$
#

PORTNAME=	ggz-sdl-games
PORTVERSION=	0.0.12
CATEGORIES=	games
MASTER_SITES=	http://mirrors.dotsrc.org/ggzgamingzone/ggz/%SUBDIR%/ \
		http://ftp.ggzgamingzone.org/pub/ggz/%SUBDIR%/
MASTER_SITE_SUBDIR=	${PORTVERSION}

MAINTAINER=	yinjieh@csie.nctu.edu.tw
COMMENT=	The GGZ Gaming Zone - SDL-based games

LIB_DEPENDS=	ggzcore.8:${PORTSDIR}/games/ggz-client-libs

USE_GETOPT_LONG=	yes
USE_GETTEXT=	yes
USE_SDL=	image mixer sdl ttf
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--disable-debug

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}

post-patch:
	@${REINPLACE_CMD} -e \
		's|SDL/SDL.h|SDL11/SDL.h|;	\
		 s|SDL/SDL_image.h|SDL11/SDL_image.h|;	\
		 s|SDL/SDL_mixer.h|SDL11/SDL_mixer.h|;	\
		 s|SDL/SDL_syswm.h|SDL11/SDL_syswm.h|;	\
		 s|SDL/SDL_ttf.h|SDL11/SDL_ttf.h|'	\
		 ${WRKSRC}/configure		\
		 ${WRKSRC}/geekgame/intro.c	\
		 ${WRKSRC}/geekgame/main.c	\
		 ${WRKSRC}/ttt3d/display.c	\
		 ${WRKSRC}/ttt3d/main.c

.include <bsd.port.mk>
