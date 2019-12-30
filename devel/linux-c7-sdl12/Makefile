# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	1.2.15
DISTVERSIONSUFFIX=	-15.el7_7
PORTREVISION=	2
CATEGORIES=	devel linux
DISTNAME=	SDL-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform multi-media development API (Linux CentOS ${LINUX_DIST_VER})

USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*
DESCR=		${.CURDIR}/../${PORTNAME}12/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/SDL-${PORTVERSION}

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
