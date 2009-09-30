# Ports collection makefile for:  pear-Services_JSON
# Date created:			  22 May, 2009
# Whom:				  Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Services_JSON
PORTVERSION=	1.0.1
CATEGORIES=	converters www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PHP implementaion of json_encode/decode

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		JSON.php

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
