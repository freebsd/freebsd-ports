# $FreeBSD$

PORTNAME=	web-console
PORTVERSION=	3.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	3-rails50

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel50>=5.0:databases/rubygem-activemodel50 \
		rubygem-actionview50>=5.0:devel/rubygem-actionview50 \
		rubygem-bindex>=0.4.0:devel/rubygem-bindex \
		rubygem-railties50>=5.0:www/rubygem-railties50

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

# web-console 4.0.0+ requires Rails 6.0.0+
PORTSCOUT=	limit:^3\.

.include <bsd.port.mk>
