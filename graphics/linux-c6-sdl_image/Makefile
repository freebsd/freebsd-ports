# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	sdl_image
PORTVERSION=	1.2.12
DISTVERSIONSUFFIX=	-9.el6
PORTREVISION=	5
CATEGORIES=	graphics linux
MASTER_SITES=	EPEL/s
DISTNAME=	SDL_image-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library to load images as SDL interfaces (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	jpeg png sdl12 tiff
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL_image-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
