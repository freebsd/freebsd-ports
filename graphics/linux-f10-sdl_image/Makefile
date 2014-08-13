# Created by: bsam
# $FreeBSD: head/graphics/linux-f10-sdl_image/Makefile 340722 2014-01-22 17:00:46Z mat $

PORTNAME=	sdl_image
PORTVERSION=	1.2.6
PORTREVISION=	3
CATEGORIES=	graphics linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library to load images as SDL interfaces (Linux Fedora 10)

CONFLICTS=	linux-sdl_image-[0-9]* linux-f8-sdl_image-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	jpeg png sdl12 tiff
LINUX_NAME=	SDL_image
LINUX_DIST_VER=	10
RPMVERSION=	6.fc9
BRANDELF_FILES=	usr/bin/showimage
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/showimage usr/lib/libSDL_image-1.2.so.0 \
		usr/lib/libSDL_image-1.2.so.0.1.5
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	CHANGES COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
