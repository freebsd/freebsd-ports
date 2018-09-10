# Created by: Piotr Kubaj <pkubaj@anongoth.pl>
# $FreeBSD$

PORTNAME=	sdl
PORTVERSION=	1.2.15
PORTREVISION=	1
CATEGORIES=	devel linux
DISTNAME=	${LINUXNAME}-${DISTVERSIONFULL}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Cross-platform multi-media development API (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-c6-${PORTNAME}-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}12/pkg-descr
DOCSDIR=	${PREFIX}/usr/share/doc/${LINUXNAME}-${PORTVERSION}
LINUXNAME=	SDL
RPMVERSION=	14.el7
USES=		linux:c7
USE_LDCONFIG=	yes
USE_LINUX=	xorglibs
USE_LINUX_RPM=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
