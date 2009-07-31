# Ports collection makefile for:	rubygem-turing
# Date created:				07 June 2007
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	turing
PORTVERSION=	0.0.11
PORTREVISION=	1
CATEGORIES=	graphics rubygems
MASTER_SITES=	RF

MAINTAINER=	avl@FreeBSD.org
COMMENT=	Easy to use and customize/extend implementation of captcha

BUILD_DEPENDS=	rubygem-gd2>=1.0.0:${PORTSDIR}/graphics/rubygem-gd2
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=  yes

.include <bsd.port.mk>
