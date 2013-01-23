# New ports collection makefile for:	rubygem-mongo
# Date created:		18 Feburary 2012
# Whom:			Evan Sarmiento <bsdports@wayfair.com>
#
# $FreeBSD$
#

PORTNAME=	mongo
PORTVERSION=	1.8.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby library for mongo

RUN_DEPENDS=	rubygem-bson>=1.8.2:${PORTSDIR}/devel/rubygem-bson

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/mongo_console

.include <bsd.port.mk>
