# New ports collection makefile for:	linux-sdl_ttf
# Date created:		03 Feb 2008
# Whom:			Dmitry Marakasov <amdmi3@amdmi3.ru>
#
# $FreeBSD$
#

PORTNAME=	sdl_ttf
PORTVERSION=	2.0.8
CATEGORIES=	graphics linux
MASTER_SITES=	http://www.libsdl.org/projects/SDL_ttf/release/
DISTNAME=	SDL_ttf-${PORTVERSION}-1

MAINTAINER=	amdmi3@amdmi3.ru
COMMENT=	A library to use TrueType fonts in SDL applications (linux version)

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libSDL-1.2.so.0:${PORTSDIR}/devel/linux-sdl12

USE_LINUX_RPM=	yes
USE_LDCONFIG=	yes
ONLY_FOR_ARCHS=	i386 amd64
DIST_SUBDIR=	rpm
PLIST_SUB+=	SDLTTFVER=${PORTVERSION}

.include <bsd.port.mk>
