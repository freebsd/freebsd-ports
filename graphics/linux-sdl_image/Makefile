# New ports collection makefile for:	linux-sdl_image
# Date created:				09 July 2004
# Whom:                         	Nicola Vitale <nivit@email.it>
# Based on:				devel/linux-sdl12 by martin@tradex.sk
#
# $FreeBSD$
#

PORTNAME=	sdl_image
PORTVERSION=	1.2.5
PORTREVISION=	2
CATEGORIES=	graphics linux
MASTER_SITES=	http://www.libsdl.org/projects/SDL_image/release/
DISTNAME=	SDL_image-${PORTVERSION}-1

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	A simple library to load images as SDL interfaces (linux version)

CONFLICTS=	linux-f8-sdl_image-[0-9]* linux-f10-sdl_image-[0-9]*

USE_LINUX_RPM=	yes
USE_LINUX_APPS=	sdl12
INSTALL_SHLIB=	yes
ONLY_FOR_ARCHS=	i386 amd64
DIST_SUBDIR=	rpm
PLIST_SUB+=	SDLIMVER=${PORTVERSION}
MD5_FILE=	${PKGDIR}/distinfo

.include <bsd.port.mk>
