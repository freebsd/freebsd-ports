# New ports collection makefile for:	gltron
# Date created:				24 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gltron
PORTVERSION=	0.59
CATEGORIES=	games
MASTER_SITES=	http://gltron.sourceforge.net/download/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		png.4:${PORTSDIR}/graphics/png

.if defined(NO_SOUND)
SOUND=""
.else
SOUND="-DSOUND"
.endif

USE_X_PREFIX=	yes
USE_MESA=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
MAKE_ENV+=	OPT="${CFLAGS}" SOUND="${SOUND}"

pre-build:
	${PERL} -pi -e "s+#include <SDL\/+#include <+g" ${WRKSRC}/*.[ch]

do-install:
	@${MKDIR} ${PREFIX}/share/gltron/ ${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/data/*tx* ${WRKSRC}/data/*.png ${WRKSRC}/data/*.obj \
			${WRKSRC}/data/*mtl ${WRKSRC}/data/*.it ${WRKSRC}/sounds/*wav \
			${PREFIX}/share/gltron
	${INSTALL_PROGRAM} ${WRKSRC}/gltron ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gltron
.for file in CHANGELOG CREDITS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gltron
.endfor
.endif

.include <bsd.port.mk>
