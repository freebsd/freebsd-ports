# Ports collection makefile for:  pear-XML_SVG
# Date created:			  4 April 2004
# Whom:				  Thierry Thomas (<thierry@FreeBSD.org>)
#
# $FreeBSD$
#

PORTNAME=	XML_SVG
PORTVERSION=	0.0.3
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR object-oriented API for building SVG documents

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	XML
FILES=		SVG.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
