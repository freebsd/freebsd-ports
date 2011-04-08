# New ports collection makefile for:	xli
# Date created:				24 November 1994
# Whom:					Satoshi Asami <asami@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	xli
PORTVERSION=	1.17.0
PORTREVISION=	10
CATEGORIES=	graphics
#MASTER_SITES=	${MASTER_SITE_XCONTRIB}
#MASTER_SITE_SUBDIR=	applications
DISTNAME=	xli-2005-09-04

MAINTAINER=	lichray@gmail.com
COMMENT=	Utilities to display images in X11

LIB_DEPENDS=	png.6:${PORTSDIR}/graphics/png \
		jpeg.11:${PORTSDIR}/graphics/jpeg

USE_XORG=	xi
USE_IMAKE=	yes

MAN1=		xli.1 xlito.1
MLINKS=		xli.1 xview.1 xli.1 xsetbg.1
PLIST_FILES=	bin/xli bin/xlito bin/xview bin/xsetbg lib/X11/app-defaults/Xli

.include <bsd.port.mk>
