# New ports collection makefile for: criticalmass
# Date created:		30 Aug 2002
# Whom:			nbm
#
# $FreeBSD$
#

PORTNAME=	criticalmass
PORTVERSION=	0.9.10
PORTEPOCH=	1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	CriticalMass-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An SDL/OpenGL space shoot\'em up game

CONFLICTS=	shaaft-*

USE_BZIP2=	yes
USE_SDL=	image mixer sdl
USE_GL=		yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--disable-optimize

MAN6=		critter.6
PLIST_FILES=	bin/Packer \
		bin/critter \
		share/Critical_Mass/lg-criti.xm \
		share/Critical_Mass/resource.dat
PLIST_DIRS=	share/Critical_Mass

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		"Does not compile on sparc64"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG:T}|g ; \
		 s|^CXXFLAGS|#CXXFLAGS|g ; \
		 s|-lSDL | |g' ${WRKSRC}/configure
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'

.include <bsd.port.post.mk>
