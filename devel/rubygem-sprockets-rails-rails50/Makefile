# Created by: Steve Wills <swills@FreeBSD.org>

PORTNAME=	sprockets-rails
PORTVERSION=	3.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sprockets Rails integration

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack50>=4.0:www/rubygem-actionpack50 \
		rubygem-activesupport50>=4.0:devel/rubygem-activesupport50 \
		rubygem-sprockets3>=3.0.0:devel/rubygem-sprockets3

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.2\.

.include <bsd.port.mk>
