# Ports collection makefile for:  pear-XML_RSS
# Date created:			  04 September 2003
# Whom:				  Alex Miller (<asm@asm.kiev.ua>)
#
# $FreeBSD$
#

PORTNAME=	XML_RSS
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR RSS parser

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS} \
		${PEARDIR}/XML/Tree.php:${PORTSDIR}/devel/pear-XML_Tree

CATEGORY=	XML
FILES=		RSS.php
TESTS=		test.rss 01-parse.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
