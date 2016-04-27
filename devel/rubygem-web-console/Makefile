# $FreeBSD$

PORTNAME=	web-console
PORTVERSION=	2.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel4>=4.0:databases/rubygem-activemodel4 \
		rubygem-binding_of_caller>=0.7.2:devel/rubygem-binding_of_caller \
		rubygem-railties4>=4.0:www/rubygem-railties4 \
		rubygem-sprockets-rails>=2.0:devel/rubygem-sprockets-rails

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
