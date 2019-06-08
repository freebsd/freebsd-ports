# Created by: Johannes Meixner <johannes@perceivon.net
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	1.2.14
DISTVERSIONSUFFIX=	-7.el6_7.1
PORTREVISION=	4
CATEGORIES=	devel linux
DISTNAME=	${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform multi-media development API (Linux CentOS ${LINUX_DIST_VER})

DESCR=		${.CURDIR}/../${PORTNAME}12/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUXNAME}-${PORTVERSION}
LINUXNAME=	SDL
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
