# New Ports Collection Makefile for:	p5-sdl
# Date created:				2002-10-06
# Whom:					Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	SDL
PORTVERSION=	2.2.6
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=SDL
PKGNAMEPREFIX=	p5-
DISTNAME=	SDL_Perl-v${PORTVERSION}

MAINTAINER=	spam@rm-rf.kiev.ua
COMMENT=	Perl Bindings for SDL

BUILD_DEPENDS=	p5-YAML>=0.62:${PORTSDIR}/textproc/p5-YAML
LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_SDL=	sdl
PERL_MODBUILD=	yes

OPTIONS=	SDL_TTF "Enable TTF support" on \
		SDL_NET "Enable NET support" on \
		SDL_GFX "Enable GFX support" on \
		SDL_IMAGE "Enable IMAGE support" on \
		SDL_MIXER "Enable MIXER support" on

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

USE_LDCONFIG=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=	SDL.3		\
	SDL::App.3	\
	SDL::Cdrom.3	\
	SDL::Color.3	\
	SDL::Cursor.3	\
	SDL::Event.3	\
	SDL::Font.3	\
	SDL::Game::Rect.3	\
	SDL::MPEG.3	\
	SDL::Mixer.3	\
	SDL::Music.3	\
	SDL::OpenGL.3	\
	SDL::Palette.3	\
	SDL::Rect.3	\
	SDL::SFont.3	\
	SDL::Sound.3	\
	SDL::Surface.3	\
	SDL::TTFont.3	\
	SDL::Timer.3	\
	SDL::Tool::Font.3	\
	SDL::Tool::Graphic.3	\
	SDL::Tutorial.3	\
	SDL::Tutorial::Animation.3	\
	SDL::Tutorial::Drawing.3	\
	SDL::Tutorial::Images.3		\
	SDL::Tutorial::LunarLander.3	\
	SDL::Video.3

post-install:
	@if [ -n "${PERL}" ]; then \
		PERL_THREADED=`${PERL} -V | ${GREP} -- -Dusethreads=y || ${TRUE}`; \
		if [ -z ${PERL_THREADED} ]; then \
			${ECHO_MSG}; \
			${ECHO_MSG} "SDL_PERL must be built with a threaded Perl, reinstall Perl with WITH_THREADS=yes"; \
			${ECHO_MSG}; \
		fi; \
	fi

.include <bsd.port.post.mk>
