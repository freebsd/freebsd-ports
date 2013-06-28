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

USES=		imake
USE_XORG=	xi
USE_GCC=	any
WRKSRC=		${WRKDIR}/xli-${XLI_SNAPVER}

MAN1=		xli.1 xlito.1
MLINKS=		xli.1 xview.1 xli.1 xsetbg.1
PLIST_FILES=	bin/xli bin/xlito bin/xview bin/xsetbg lib/X11/app-defaults/Xli

XLI_SNAPVER=	2006-11-10

.include <bsd.port.mk>
