# New ports collection makefile for:	Shaaft
# Date created:				02 Jan 2004
# Whom:					Kirill Ponomarew <krion@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	shaaft
PORTVERSION=	0.5.0
PORTREVISION=	7
CATEGORIES=	games
MASTER_SITES=	SF/criticalmass
DISTNAME=	Shaaft-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An OpenGL 3D falling block game similar to Blockout

CONFLICTS=	criticalmass-*

USE_BZIP2=	yes
USE_SDL=	mixer image sdl
USE_GL=		yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
CONFIGURE_ARGS=	--disable-optimize
DATADIR=	${PREFIX}/share/Shaaft

PLIST_FILES=	bin/Packer bin/shaaft %%DATADIR%%/resource.dat
PLIST_DIRS=	%%DATADIR%%

MAN6=		${PORTNAME}.6

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|sdl-config|${SDL_CONFIG:T}|g ; \
		s|^CXXFLAGS|#CXXFLAGS|g ; \
		s|/usr/X11R6|${LOCALBASE}|g ; \
		s|-lSDL | |g ; \
		s|-lpng12|-lpng|g' ${WRKSRC}/configure
	@${GREP} -lR "SDL/SDL" ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e \
		's|SDL/SDL|SDL|g'
	@${REINPLACE_CMD} -e 's|== 3|>= 3|' ${WRKSRC}/utils/hashMap.hpp

.include <bsd.port.post.mk>
