# New Ports Collection Makefile for:	p5-sdl
# Date created:				2002-10-06
# Whom:					Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	1.18.7
CATEGORIES=	devel
MASTER_SITES=	http://www.sdlperl.org/downloads/ \
		ftp://sdlperl.org/SDL_perl/old/
PKGNAMEPREFIX=	p5-
DISTNAME=	SDL_perl-${PORTVERSION}

MAINTAINER=	klaus.goger@reflex.at

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SDL_TTF)
LIB_DEPENDS+=	SDL_ttf.3:${PORTSDIR}/graphics/sdl_ttf
.endif

.if !defined(WITHOUT_SDL_NET)
LIB_DEPENDS+=	SDL_net.0:${PORTSDIR}/net/sdl_net
.endif

.if !defined(WITHOUT_SDL_GFX)
LIB_DEPENDS+=	SDL_gfx.0:${PORTSDIR}/graphics/sdl_gfx
.endif

.if !defined(WITHOUT_SDL_IMAGE)
LIB_DEPENDS+=	SDL_image.10:${PORTSDIR}/graphics/sdl_image
.endif

.if !defined(WITHOUT_SDL_MIXER)
LIB_DEPENDS+=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer
.endif

USE_PERL5=	yes
INSTALLS_SHLIB=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		SDL::Cursor.3 SDL::Rect.3 SDL::Color.3 SDL::TTFont.3 \
		SDL::App.3 SDL::Timer.3 SDL::Event.3 SDL::Console.3 \
		SDL::Mixer.3 SDL::Cdrom.3 SDL::Font.3 SDL::Surface.3 \
		SDL.3

pre-extract:
.if !defined(WITHOUT_SDL_GFX)
	@${ECHO_MSG} "You can disable support for mikmod by defining WITHOUT_SDL_GFX."
.endif
.if !defined(WITHOUT_SDL_IMAGE)
	@${ECHO_MSG} "You can disable support for mikmod by defining WITHOUT_SDL_IMAGE."
.endif
.if !defined(WITHOUT_SDL_MIXER)
	@${ECHO_MSG} "You can disable support for mikmod by defining WITHOUT_SDL_MIXER."
.endif
.if !defined(WITHOUT_SDL_NET)
	@${ECHO_MSG} "You can disable support for mikmod by defining WITHOUT_SDL_NET."
.endif
.if !defined(WITHOUT_SDL_TTF)
	@${ECHO_MSG} "You can disable support for mikmod by defining WITHOUT_SDL_TTF."
.endif

do-configure:
	cd ${WRKSRC}; ${PERL} ${WRKSRC}/Makefile.freebsd

.include <bsd.port.post.mk>
