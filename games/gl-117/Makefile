# ex:ts=8
# Ports collection makefile for:	gl-117
# Date created:			Aug 8, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	gl-117
PORTVERSION=	0.7
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_MESA=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"

CPPFLAGS=	`${SDL_CONFIG} --cflags` -I${X11BASE}/include
LDFLAGS=	`${SDL_CONFIG} --libs` -L${X11BASE}/lib

post-patch:
.for file in configure src/audio.h src/glland.h src/main.h src/net.h
	@${REINPLACE_CMD} -e 's|^CPPFLAGS="-D|CPPFLAGS="\$$CPPFLAGS -D|g ; \
		 s|SDL/||g ; \
		 s|-lSDL |-lSDL-1.1 |g ; \
		 s|-lSDLmain|-lSDLmain-1.1|g' ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
