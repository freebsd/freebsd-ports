# New ports collection makefile for:	dgen-sdl
# Date created:				20 September 2000
# Whom:					Maxim Sobolev <sobomax@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	dgen-sdl
PORTVERSION=	1.22
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://pknet.com/~joe/

MAINTAINER=	sobomax@FreeBSD.org

BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
LIB_DEPENDS=	SDL-1.1.4:${PORTSDIR}/devel/sdl12

SDL_CONFIG?=	${LOCALBASE}/bin/sdl11-config

USE_MESA=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	SDL_CONFIG="${SDL_CONFIG}"

MAN1=		dgen.1 tobin.1
MAN5=		dgenrc.5

.include <bsd.port.mk>
