# Created by: Evan Sarmiento <bsdports@wayfair.com>
# $FreeBSD$

PORTNAME=	mongo
PORTVERSION=	2.12.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby driver for MongoDB

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bson>=4.8.2<5.0.0:devel/rubygem-bson

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/mongo_console

.include <bsd.port.mk>
