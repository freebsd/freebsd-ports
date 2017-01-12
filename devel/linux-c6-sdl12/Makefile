# Created by: Johannes Meixner <johannes@perceivon.net
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	1.2.14
PORTREVISION=	4
CATEGORIES=	devel linux
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform multi-media development API (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-sdl12-[0-9]* linux-f8-sdl12-[0-9]*

LINUX_NAME=	SDL
RPMVERSION=	7.el6_7.1
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	BUGS COPYING CREDITS README-SDL.txt
DESCR=		${.CURDIR}/../${PORTNAME}12/pkg-descr

.include <bsd.port.mk>
