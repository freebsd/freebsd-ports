# New ports collection makefile for:	devel/linux-f10-sdl12
# Date created:				2009-05-03
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	sdl
PORTVERSION=	1.2.13
CATEGORIES=	devel linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform multi-media development API (Linux Fedora 10)

CONFLICTS=	linux-sdl12-[0-9]* linux-f8-sdl12-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	xorglibs
INSTALL_SHLIB=	yes
LINUX_NAME=	SDL
LINUX_DIST_VER=	10
RPMVERSION=	7.fc10
USE_LDCONFIG=	yes

PLIST_FILES=	usr/lib/libSDL-1.2.so.0 usr/lib/libSDL-1.2.so.0.11.2
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	BUGS COPYING CREDITS README-SDL.txt
DESCR=		${.CURDIR}/../${PORTNAME}12/pkg-descr

.include <bsd.port.mk>
