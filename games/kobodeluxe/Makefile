# New ports collection makefile for:	kobodeluxe
# Date created:		12 June 2002
# Whom:			Amar Takhar <verm@drunkmonk.net>
#
# $FreeBSD$
#

PORTNAME=	kobodeluxe
PORTVERSION=	0.4.p8
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://olofson.net/skobo/download/ \
		http://olofson.net/download/
DISTNAME=	KoboDeluxe-${PORTVERSION:S/.p/pre/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Kobo Deluxe (formerly SKobo) is an SDL port of Akira Higuchi's XKobo

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG=${LOCALBASE}/bin/sdl11-config
CONFIGURE_ARGS+=	--program-transform-name="s/$$//"

USE_SDL=	image sdl
USE_AUTOCONF_VER=	253
USE_AUTOMAKE_VER=	15

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
BROKEN=		"Does not compile on amd64"
.endif

pre-configure:
	cd ${WRKDIR}/${DISTNAME} && ${ACLOCAL} && ${AUTOCONF} && ${AUTOHEADER}

.include <bsd.port.post.mk>
