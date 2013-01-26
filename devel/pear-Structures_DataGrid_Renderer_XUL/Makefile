# Ports collection makefile for:	pear-Structures_DataGrid_Renderer_XUL
# Date created:				26 Jun 2008
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	Structures_DataGrid_Renderer_XUL
PORTVERSION=	0.1.3
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	XUL Renderer for pear-Structures_DataGrid

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:${PORTSDIR}/devel/pear-Structures_DataGrid \
		${PEARDIR}/XML/Util.php:${PORTSDIR}/devel/pear-XML_Util

CATEGORY=	Structures
FILES=		DataGrid/Renderer/XUL.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
