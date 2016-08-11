# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	sdl_image
PORTVERSION=	1.2.12
PORTREVISION=	2
CATEGORIES=	graphics linux
MASTER_SITES=	EPEL
DISTNAME=	SDL_image-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library to load images as SDL interfaces (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-sdl_image-[0-9]* linux-f8-sdl_image-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	jpeg png sdl12 tiff
LINUX_NAME=	SDL_image

RPMVERSION=	9.el6
BRANDELF_FILES=	usr/bin/showimage
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	CHANGES COPYING README

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
