PORTNAME=	webpacker
PORTVERSION=	5.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Use Webpack to manage app-like JavaScript modules in Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport61>=5.2:devel/rubygem-activesupport61 \
		rubygem-rack-proxy>=0.6.1:www/rubygem-rack-proxy \
		rubygem-railties61>=5.2:www/rubygem-railties61 \
		rubygem-semantic_range>=2.3.0:devel/rubygem-semantic_range \
		yarn:www/yarn

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
