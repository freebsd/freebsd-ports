# New ports collection makefile for: criticalmass
# Date created:		30 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	criticalmass
PORTVERSION=	1.0.0
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Critical%20Mass/${PORTVERSION}
DISTNAME=	CriticalMass-${PORTVERSION}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	An SDL/OpenGL space shoot\'em up game

CONFLICTS=	shaaft-[0-9]*

USE_BZIP2=	yes
USE_SDL=	image mixer sdl
USE_GL=		gl
USE_XORG=	x11
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-optimize

MAN6=		critter.6
PLIST_FILES=	bin/Packer \
		bin/critter \
		share/Critical_Mass/lg-criti.xm \
		share/Critical_Mass/resource.dat
PLIST_DIRS=	share/Critical_Mass

.include <bsd.port.pre.mk>

post-patch:
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG:T}|g ; \
		 s|^CXXFLAGS|#CXXFLAGS|g ; \
		 s|/usr/X11R6|${LOCALBASE}|g ; \
		 s|-lSDL | |g ; \
		 s|-lpng12|-lpng|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|and def|\&\& def|g' ${WRKSRC}/utils/OSName.hpp

.include <bsd.port.post.mk>
