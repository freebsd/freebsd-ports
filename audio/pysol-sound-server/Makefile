# New ports collection makefile for:	pysol-sound-server
# Date created:				7 January 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pysol-sound-server
PORTVERSION=	3.00
CATEGORIES=	audio games
MASTER_SITES=	http://www.oberhumer.com/opensource/pysol/download/ \
		ftp://ftp.is.co.za/linux/distributions/gentoo/distfiles/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python extension module to play sounds and background music

LIB_DEPENDS=	SDL-1.1.5:${PORTSDIR}/devel/sdl12 \
		smpeg.1:${PORTSDIR}/multimedia/smpeg \
		SDL_mixer.2:${PORTSDIR}/audio/sdl_mixer

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

WRKSRC=		${WRKDIR}/${DISTNAME}/src

USE_BZIP2=	yes
USE_PYTHON=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

.include <bsd.port.mk>
