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
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}" \
		SDL_CONFIG="${SDL_CONFIG}"

CPPFLAGS=	-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}
LDFLAGS=	-L${LOCALBASE}/lib -L${X11BASE}/lib -lXext ${PTHREAD_LIBS}

post-patch:
	${REINPLACE_CMD} -e "s+#include <SDL/+#include <+g" ${WRKSRC}/*.[ch]

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/gltron ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC} -cf - art data sounds | \
		${TAR} -C ${DATADIR} --unlink -xf -
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in CHANGELOG CREDITS README
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
