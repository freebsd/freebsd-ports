# New ports collection makefile for:	xli
# Date created:		24 November 1994
# Whom:			asami
#
# $FreeBSD$
#

PORTNAME=	xli
PORTVERSION=	1.17.0
PORTREVISION=	7
CATEGORIES=	graphics
MASTER_SITES=	http://pantransit.reptiles.org/prog/xli/ \
		${MASTER_SITE_XCONTRIB}
MASTER_SITE_SUBDIR=	applications
DISTNAME=	xli-${XLI_SNAPVER}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Xli, xsetbg, xview, xlito - utilities to display images on X11

LIB_DEPENDS=	png.5:${PORTSDIR}/graphics/png \
		jpeg.10:${PORTSDIR}/graphics/jpeg

WRKSRC=		${WRKDIR}/xli-${XLI_SNAPVER}

USE_XORG=	xi
USE_IMAKE=	yes
MAN1=		xli.1 xlito.1
MLINKS=		xli.1 xview.1 \
		xli.1 xsetbg.1

XLI_SNAPVER=	2005-09-04

.include <bsd.port.mk>
