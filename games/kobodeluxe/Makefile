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

BROKEN=		"Does not compile"

BUILD_DEPENDS=	autoconf:${PORTSDIR}/devel/autoconf \
		automake:${PORTSDIR}/devel/automake
LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12 \
		SDL_image.10:${PORTSDIR}/graphics/sdl_image

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG=${LOCALBASE}/bin/sdl11-config
CONFIGURE_ARGS+=	--program-transform-name="s/$$//"

AUTOCONF=	autoconf
AUTOMAKE=	automake
ACLOCAL=	aclocal

pre-configure:
	cd ${WRKDIR}/${DISTNAME} && ${ACLOCAL} && ${AUTOCONF} && ${AUTOHEADER}

.include <bsd.port.mk>
