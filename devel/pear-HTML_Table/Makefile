# Ports collection makefile for:  pear-HTML_Table
# Date created:			  01 June 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Table
PORTVERSION=	1.5
CATEGORIES=	devel www pear

MAINTAINER=	tux@pinguru.net
COMMENT=	Makes the design of HTML tables easy, flexible, reusable and efficient

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		Table.php
EXAMPLES=	Table_example1.php Table_example2.php
_EXAMPLESDIR=	docs

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
