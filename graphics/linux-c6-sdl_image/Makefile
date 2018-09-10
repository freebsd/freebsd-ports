# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	sdl_image
PORTVERSION=	1.2.12
PORTREVISION=	5
CATEGORIES=	graphics linux
MASTER_SITES=	EPEL/s
DISTNAME=	${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library to load images as SDL interfaces (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUXNAME}-${PORTVERSION}
LINUXNAME=	SDL_image
RPMVERSION=	9.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	jpeg png sdl12 tiff
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
