# New ports collection makefile for:  	barrage
# Date created:       	23 April 2003
# Whom:  	Kirill Ponomarew <ponomarew@oberon.net>
#
# $FreeBSD$
#

PORTNAME=	barrage
PORTVERSION=	1.0.1
CATEGORIES=	games
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	lgames
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	krion@FreeBSD.org
COMMENT=	Destroy as many targets as possible

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG=	${LOCALBASE}/bin/sdl11-config

USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-profile-path=/var/games
USE_REINPLACE=	yes

CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}" \
		CPPFLAGS="-I${X11BASE}/include"

post-patch:
	@${REINPLACE_CMD} -e 's|applications|applnk/Applications|g' \
		${WRKSRC}/Makefile.in

post-install:
	${CHMOD} 0755 ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
