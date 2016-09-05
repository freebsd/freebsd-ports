# Created by: bsam
# $FreeBSD$

PORTNAME=	sdl_image
PORTVERSION=	1.2.6
PORTREVISION=	3
CATEGORIES=	graphics linux
DISTNAME=	SDL_image-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library to load images as SDL interfaces (Linux Fedora 10)

CONFLICTS=	linux-sdl_image-[0-9]* linux-f8-sdl_image-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	jpeg png sdl12 tiff
LINUX_NAME=	SDL_image

RPMVERSION=	6.fc9
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/showimage usr/lib/libSDL_image-1.2.so.0 \
		usr/lib/libSDL_image-1.2.so.0.1.5
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	CHANGES COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
