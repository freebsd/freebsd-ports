# $FreeBSD$

PORTNAME=	web-console
PORTVERSION=	2.3.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel4>=4.0:databases/rubygem-activemodel4 \
		rubygem-binding_of_caller>=0.7.2:devel/rubygem-binding_of_caller \
		rubygem-railties4>=4.0:www/rubygem-railties4 \
		rubygem-sprockets-rails-rails4>=2.0:devel/rubygem-sprockets-rails-rails4

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
