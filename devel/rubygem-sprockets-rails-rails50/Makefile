# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	sprockets-rails
PORTVERSION=	3.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Sprockets Rails integration

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack50>0:www/rubygem-actionpack50 \
		rubygem-activesupport50>0:devel/rubygem-activesupport50 \
		rubygem-sprockets3>=3.0.0:devel/rubygem-sprockets3

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
