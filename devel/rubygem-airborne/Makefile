# $FreeBSD$

PORTNAME=	airborne
PORTVERSION=	0.3.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	RSpec driven API testing framework

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=0:devel/rubygem-activesupport4 \
		rubygem-rack>=0:www/rubygem-rack \
		rubygem-rack-test>=1.1.0<2.0:www/rubygem-rack-test \
		rubygem-rest-client>=2.0.2<3.0:www/rubygem-rest-client \
		rubygem-rspec>=3.8<4:devel/rubygem-rspec

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
