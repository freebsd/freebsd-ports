# Ports collection makefile for:	pear-Structures_DataGrid
# Date created:				12 January 2005
# Whom:					Nick Hilliard <nick@foobar.org>
#
# $FreeBSD$
#

PORTNAME=	Structures_DataGrid
PORTVERSION=	0.8.3
CATEGORIES=	devel www pear

MAINTAINER=	nick@foobar.org
COMMENT=	A full-featured tabular structured data management package

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/Console/Table.php:${PORTSDIR}/devel/pear-Console_Table

CATEGORY=	Structures

FILES=		DataGrid/Column.php DataGrid/DataSource.php \
		DataGrid/Renderer.php DataGrid.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
