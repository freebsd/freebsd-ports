# Ports collection makefile for:  pear-HTML_Select
# Date created:			  11 August 2004
# Whom:				  Michael Schout <mschout@gkg.net>
#
# $FreeBSD$
#

PORTNAME=	HTML_Select
PORTVERSION=	1.3.0
CATEGORIES=	devel www pear

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PEAR::HTML_Select is a class for generating HTML form select elements

BUILD_DEPENDS=	${PEARDIR}/HTML/Common.php:${PORTSDIR}/devel/pear-HTML_Common
RUN_DEPENDS=	${BUILD_DEPENDS}

CATEGORY=	HTML
FILES=		Select.php

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}/HTML

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
