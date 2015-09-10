# Created by: Evan Sarmiento <bsdports@wayfair.com>
# $FreeBSD$

PORTNAME=	mongo
PORTVERSION=	1.12.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby driver for MongoDB

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-bson1>=${PORTVERSION}:${PORTSDIR}/devel/rubygem-bson1

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/mongo_console

.include <bsd.port.mk>
