# New ports collection makefile for:	gltron
# Date created:				24 July 1999
# Whom:					Andrey Zakhvatov
#
# $FreeBSD$
#

PORTNAME=	gltron
PORTVERSION=	0.61
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE} \
		http://gltron.sourceforge.net/download/
MASTER_SITE_SUBDIR=	${PORTNAME}
EXTRACT_SUFX=	-source.tar.gz

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer \
		SDL_net.0:${PORTSDIR}/net/sdl_net \
		png.5:${PORTSDIR}/graphics/png

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_X_PREFIX=	yes
USE_MESA=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
CONFIGURE_ENV=	X11BASE="${X11BASE}" \
		LOCALBASE="${LOCALBASE}" \
		PTHREAD_LIBS="${PTHREAD_LIBS}" \
		SDL_CONFIG="${SDL_CONFIG}"

pre-build:
	${PERL} -pi -e "s+#include <SDL\/+#include <+g" ${WRKSRC}/*.[ch]

do-install:
	@${MKDIR} ${PREFIX}/share/gltron
	(cd ${WRKSRC} && ${TAR} -c -f - art data sounds) \
		| (cd ${PREFIX}/share/gltron && ${TAR} --unlink -x -f -)
	${INSTALL_PROGRAM} ${WRKSRC}/gltron ${PREFIX}/bin

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${PREFIX}/share/doc/gltron
.for file in CHANGELOG CREDITS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/share/doc/gltron
.endfor
.endif

.include <bsd.port.mk>
