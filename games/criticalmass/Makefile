# New ports collection makefile for: criticalmass
# Date created:		30 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	criticalmass
PORTVERSION=	0.98
PORTREVISION=	0
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	criticalmass
DISTNAME=	CriticalMass-${PORTVERSION}

MAINTAINER=	nbm@FreeBSD.org
COMMENT=	An SDL/OpenGL space shoot\'em up game

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

USE_BZIP2=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="${LDFLAGS} -L${X11BASE}/lib" \
		CPPFLAGS="${CFLAGS} -I${X11BASE}/include"

MAN6=		critter.6

SDLINCPFILES=	utilssdl/PNG.hpp utilsgl/GLTexture.hpp \
		utilsgl/GLBitmapCollection.cpp utilsgl/GLExtension.hpp

.include <bsd.port.pre.mk>

post-patch:
	${REINPLACE_CMD} -e 's#sdl-config#sdl11-config#; s#-lSDL # #;' ${WRKSRC}/configure
	${REINPLACE_CMD} -e 's#SDL/#SDL11/#;' ${SDLINCPFILES:S#^#${WRKSRC}/#}

.include <bsd.port.post.mk>
