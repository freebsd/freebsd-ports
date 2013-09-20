# Created by: Klaus Goger <klaus.goger@reflex.at>
# $FreeBSD$

PORTNAME=	SDL
PORTVERSION=	2.2.6
PORTREVISION=	4
CATEGORIES=	devel perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=SDL
PKGNAMEPREFIX=	p5-
DISTNAME=	SDL_Perl-v${PORTVERSION}

MAINTAINER=	ak@FreeBSD.org
COMMENT=	Perl Bindings for SDL

BUILD_DEPENDS=	p5-YAML>=0.62:${PORTSDIR}/textproc/p5-YAML
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg:${PORTSDIR}/graphics/jpeg

USES=		perl5
USE_PERL5=	modbuild
USE_SDL=	sdl

OPTIONS_DEFINE=	GFX IMAGE MIXER NET TTF

GFX_DESC=	Enable GFX support
IMAGE_DESC=	Enable IMAGE support
MIXER_DESC=	Enable MIXER support
NET_DESC=	Enable NET support
TTF_DESC=	Enable TTF support

OPTIONS_DEFAULT=	GFX IMAGE MIXER NET TTF

NO_STAGE=	yes
.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MGFX}
USE_SDL+=	gfx
.endif

.if ${PORT_OPTIONS:MIMAGE}
USE_SDL+=	image
.endif

.if ${PORT_OPTIONS:MMIXER}
USE_SDL+=	mixer
.endif

.if ${PORT_OPTIONS:MNET}
USE_SDL+=	net
.endif

.if ${PORT_OPTIONS:MTTF}
USE_SDL+=	ttf
.endif

USE_LDCONFIG=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VER}

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
