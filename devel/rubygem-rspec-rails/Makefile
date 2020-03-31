# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	rspec-rails
PORTVERSION=	4.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Testing framework for Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-actionpack4>=4.2:www/rubygem-actionpack4 \
		rubygem-activesupport4>=4.2:devel/rubygem-activesupport4 \
		rubygem-railties4>=4.2:www/rubygem-railties4 \
		rubygem-rspec-core>=3.9<4:devel/rubygem-rspec-core \
		rubygem-rspec-expectations>=3.9<4:devel/rubygem-rspec-expectations \
		rubygem-rspec-mocks>=3.9<4:devel/rubygem-rspec-mocks \
		rubygem-rspec-support>=3.9<4:devel/rubygem-rspec-support

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
