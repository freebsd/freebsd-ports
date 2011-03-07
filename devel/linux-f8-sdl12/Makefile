# New ports collection makefile for:	devel/linux-f8-sdl12
# Date created:				2008-04-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	1.2.13
PORTREVISION=	1
CATEGORIES=	devel linux
PKGNAMEPREFIX=	linux-f8-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform multi-media development API (Linux Fedora 8)

CONFLICTS=	linux-sdl12-[0-9]* linux-f10-sdl12-[0-9]*

DEPRECATED=	End of Life since Jan 7, 2009
EXPIRATION_DATE=2011-04-01

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
INSTALL_SHLIB=	yes
LINUX_NAME=	SDL
LINUX_DIST_VER=	8
RPMVERSION=	2.fc8
USE_LDCONFIG=	yes

PLIST_FILES=	etc/profile.d/SDL_pulseaudio_hack.csh etc/profile.d/SDL_pulseaudio_hack.sh \
		usr/lib/libSDL-1.2.so.0 usr/lib/libSDL-1.2.so.0.11.2
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	BUGS COPYING CREDITS README-SDL.txt
DESCR=		${.CURDIR}/../${PORTNAME}12/pkg-descr

.include <bsd.port.mk>
