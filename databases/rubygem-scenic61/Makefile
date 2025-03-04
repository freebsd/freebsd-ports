PORTNAME=	scenic
PORTVERSION=	1.8.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Adds methods to ActiveRecord::Migration to create and manage database views in Rails
WWW=		https://github.com/scenic-views/scenic

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Uses EOL version 6.1.X of Rails
EXPIRATION_DATE=2025-04-03

RUN_DEPENDS=	rubygem-activerecord61>=4.0.0:databases/rubygem-activerecord61 \
		rubygem-railties61>=4.0.0:www/rubygem-railties61

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
