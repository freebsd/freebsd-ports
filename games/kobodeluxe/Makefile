# New ports collection makefile for:	kobodeluxe
# Date created:		12 June 2002
# Whom:			Amar Takhar <verm@drunkmonk.net>
#
# $FreeBSD$
#

PORTNAME=	kobodeluxe
PORTVERSION=	0.4.p8
CATEGORIES=	games
MASTER_SITES=	http://olofson.net/skobo/download/ \
		http://olofson.net/download/
DISTNAME=	KoboDeluxe-${PORTVERSION:S/.p/pre/}

MAINTAINER=	verm@drunkmonk.net

LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG=${LOCALBASE}/bin/sdl11-config
CONFIGURE_ARGS+=	--program-transform-name="s/$$//"

USE_AUTOMAKE=	yes
USE_AUTOCONF=	yes
USE_AUTOCONF_VER=	253
USE_AUTOMAKE_VER=	15
AUTOCONF=	autoconf
ACLOCAL=	aclocal

pre-configure:
	cd ${WRKDIR}/${DISTNAME} && ${ACLOCAL} && ${AUTOCONF} && ${AUTOHEADER}

.include <bsd.port.mk>
