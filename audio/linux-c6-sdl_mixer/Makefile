# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.12
PORTREVISION=	4
CATEGORIES=	audio linux
MASTER_SITES=	EPEL
DISTNAME=	${LINUX_NAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Sample multi-channel audio mixer library (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-sdl_mixer-[0-9]* linux-f8-sdl_mixer-[0-9]*

LINUX_NAME=	SDL_mixer
RPMVERSION=	1.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	sdl12 mikmod
USE_LINUX_RPM=	yes

DOCSDIR=	${PREFIX}/usr/share/doc/${LINUX_NAME}-${PORTVERSION}
PORTDOCS=	CHANGES COPYING README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
