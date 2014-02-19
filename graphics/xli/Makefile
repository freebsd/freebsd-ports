# Created by: Satoshi Asami <asami@FreeBSD.org>
# $FreeBSD$

PORTNAME=	xli
PORTVERSION=	1.17.0
PORTREVISION=	13
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_DEBIAN}
MASTER_SITE_SUBDIR=	pool/main/x/${PORTNAME}
DISTNAME=	xli_${PORTVERSION}+${XLI_SNAPVER:C/-//g}.orig

MAINTAINER=	lichray@gmail.com
COMMENT=	Utilities to display images in X11

CONFLICTS_INSTALL=	xloadimage-*
LIB_DEPENDS=	png15:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USES=		imake desthack
USE_XORG=	xi
WRKSRC=		${WRKDIR}/xli-${XLI_SNAPVER}

XLI_SNAPVER=	2006-11-10

.include <bsd.port.mk>
