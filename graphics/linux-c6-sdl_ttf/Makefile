# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	sdl_ttf
PORTVERSION=	2.0.11
PORTREVISION=	1
CATEGORIES=	graphics linux
MASTER_SITES=	EPEL
DISTNAME=	SDL_ttf-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library to load True Type Fonts as SDL interfaces (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-sdl_ttf-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX=	c6
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	jpeg png sdl12 tiff
LINUX_NAME=	SDL_ttf

RPMVERSION=	6.el6
USE_LDCONFIG=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	CHANGES COPYING README

DESCR=		${.CURDIR}/../linux-f10-sdl_ttf/pkg-descr

.include <bsd.port.mk>
