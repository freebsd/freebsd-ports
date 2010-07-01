# Ports collection makefile for:  pear-HTML_Table
# Date created:			  01 June 2004
# Whom:				  Gerrit Beine (<tux@pinguru.net>)
#
# $FreeBSD$
#

PORTNAME=	HTML_Table
PORTVERSION=	1.8.3
CATEGORIES=	devel www pear

MAINTAINER=	gerrit.beine@gmx.de
COMMENT=	Makes the design of HTML tables easy, flexible, reusable and efficient

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		Table.php Table/Storage.php
EXAMPLES=	Table_example1.php Table_example2.php
_EXAMPLESDIR=	docs

TESTS=		1.phpt 2.phpt 3.phpt 4.phpt 5.phpt \
		6.phpt 7.phpt 8.phpt 9.phpt 10.phpt \
		11.phpt 12.phpt 13.phpt 14.phpt 15.phpt \
		16.phpt 17.phpt 18.phpt 19.phpt 20.phpt \
		21.phpt 22.phpt 23.phpt 24.phpt 25.phpt \
		26.phpt 27.phpt 28.phpt 29.phpt 30.phpt \
		31.phpt

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
