# New ports collection makefile for:	Structures_DataGrid_DataSource_MDB2
# Date created:				19 Dec 2007
# Whom:					Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Structures_DataGrid_DataSource_MDB2
PORTVERSION=	0.1.11
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	DataSource driver using PEAR::MDB2 and an SQL query

BUILD_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:${PORTSDIR}/devel/pear-Structures_DataGrid \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2
RUN_DEPENDS=	${PEARDIR}/Structures/DataGrid.php:${PORTSDIR}/devel/pear-Structures_DataGrid \
		${PEARDIR}/MDB2.php:${PORTSDIR}/databases/pear-MDB2

USE_PHP=	mysql

CATEGORY=	Structures

FILES=		DataGrid/DataSource/MDB2.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
