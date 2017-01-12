# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	sdl_ttf
PORTVERSION=	2.0.11
PORTREVISION=	3
CATEGORIES=	graphics linux
MASTER_SITES=	EPEL
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Simple library to load True Type Fonts as SDL interfaces (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-sdl_ttf-[0-9]*

LINUX_NAME=	SDL_ttf
RPMVERSION=	6.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	jpeg png sdl12 tiff
USE_LINUX_RPM=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	CHANGES COPYING README

.include <bsd.port.mk>
