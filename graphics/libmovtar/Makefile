# New ports collection makefile for:	libmovtar
# Date created:		Mon Oct 15 23:35:04 BRST 2001
# Whom:                 Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libmovtar
PORTVERSION=	0.1.2
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	mjpeg

MAINTAINER=	lioux@FreeBSD.org

LIB_DEPENDS=	SDL-1.1.3:${PORTSDIR}/devel/sdl12 \
		jpeg.9:${PORTSDIR}/graphics/jpeg

USE_GTK=	yes
USE_AUTOCONF=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS= --with-m4data-prefix=${PREFIX}/share
CONFIGURE_ENV=  SDL_CONFIG="${SDL_CONFIG}" \
		LOCALBASE="${LOCALBASE}"
MAKE_ENV=	PTHREAD_CFLAGS="${PTHREAD_CFLAGS}" \
		PTHREAD_LIBS=${PTHREAD_LIBS}

SDL_CONFIG?=    ${LOCALBASE}/bin/sdl11-config

.include <bsd.port.mk>
