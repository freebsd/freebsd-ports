# New Ports Collection Makefile for:	p5-sdl
# Date created:				2002-10-06
# Whom:					Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	1.20.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	http://bloodgate.com/perl/sdl/pub/
PKGNAMEPREFIX=	p5-
DISTNAME=	SDL_perl-${PORTVERSION}

MAINTAINER=	philip@FreeBSD.org
COMMENT=	Perl Bindings for SDL

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_SDL=	sdl

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SDL_TTF)
USE_SDL+=	ttf
.endif

.if !defined(WITHOUT_SDL_NET)
USE_SDL+=	net
.endif

.if !defined(WITHOUT_SDL_GFX)
USE_SDL+=	gfx
.endif

.if !defined(WITHOUT_SDL_IMAGE)
USE_SDL+=	image
.endif

.if !defined(WITHOUT_SDL_MIXER)
USE_SDL+=	mixer
.endif

.if ${PERL_LEVEL} < 500600
IGNORE=		This port requires perl 5.6 or newer
.endif

.if ${PERL_LEVEL} < 500800
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
RUN_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple
.endif

USE_PERL5=	yes
INSTALLS_SHLIB=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		SDL.3		\
		SDL::App.3	\
		SDL::Cdrom.3	\
		SDL::Color.3	\
		SDL::Console.3	\
		SDL::Cursor.3	\
		SDL::Event.3	\
		SDL::Font.3	\
		SDL::Mixer.3	\
		SDL::Music.3	\
		SDL::OpenGL.3	\
		SDL::OpenGL::Cube.3	\
		SDL::OpenGL::Model.3	\
		SDL::Palette.3	\
		SDL::Rect.3	\
		SDL::Shell.3	\
		SDL::Sound.3	\
		SDL::Surface.3	\
		SDL::TTFont.3	\
		SDL::Timer.3	\
		SDL::Tool::Font.3	\
		SDL::Tool::Graphic.3

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
