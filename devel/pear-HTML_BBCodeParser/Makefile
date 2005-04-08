# Ports collection makefile for:  pear-HTML_BBCodeParser
# Date created:			  29 May 2004
# Whom:				  Lewis Thompson <purple@lewiz.net>
#
# $FreeBSD$
#

PORTNAME=	HTML_BBCodeParser
PORTVERSION=	1.1
CATEGORIES=	devel www pear

MAINTAINER=	lewiz@compsoc.man.ac.uk
COMMENT=	Parser to replace UBB style tags with their HTML equivalents

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		BBCodeParser.php \
		BBCodeParser/Filter/Basic.php \
		BBCodeParser/Filter/Email.php \
		BBCodeParser/Filter/Extended.php \
		BBCodeParser/Filter/Images.php \
		BBCodeParser/Filter/Links.php \
		BBCodeParser/Filter/Lists.php
EXAMPLES=	BBCodeParser.ini parser.php
_EXAMPLESDIR=	BBCodeParser/example

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
