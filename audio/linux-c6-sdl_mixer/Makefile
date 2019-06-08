# Created by: Johannes Meixner <johannes@perceivon.net>
# $FreeBSD$

PORTNAME=	sdl_mixer
PORTVERSION=	1.2.12
DISTVERSIONSUFFIX=	-1.el6
PORTREVISION=	5
CATEGORIES=	audio linux
MASTER_SITES=	EPEL/s
DISTNAME=	SDL_mixer-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Sample multi-channel audio mixer library (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	sdl12
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL_mixer-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
