# Ports collection makefile for:  pear-DBA_Relational
# Date created:			  28 Arp 2007
# Whom:				  Martin Wilke <miwi@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DBA_Relational
PORTVERSION=	0.2.0
CATEGORIES=	databases www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	Berkely-style database abstraction class

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

PORTSCOUT=	skipv:0.19

FILES=		Functions.php Relational.php Table.php TempTable.php Toolbox.php
TESTS=		empSchema.php hatSchema.php test_relational.php test_table.php
DOCS=		Examples.txt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
