# Created by: Johannes Meixner <johannes@perceivon.net
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	1.2.14
DISTVERSIONSUFFIX=	-7.el6_7.1
PORTREVISION=	4
CATEGORIES=	devel linux
DISTNAME=	SDL-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform multi-media development API (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes

DESCR=		${.CURDIR}/../${PORTNAME}12/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
