# Ports collection makefile for:  pear-Console_Table
# Date created:			  31 August 2003
# Whom:				  Thierry Thomas (<thierry@pompo.net>)
#
# $FreeBSD$
#

PORTNAME=	Console_Table
PORTVERSION=	1.1.2
CATEGORIES=	devel pear

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	PHP class that makes it easy to build console style tables

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	Console
FILES=		Table.php
TESTS=		assoziative_arrays.phpt filters.phpt multibyte.phpt multiline.phpt \
		no_header.phpt no_rows.phpt rules.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
