PORTNAME=	webpacker
PORTVERSION=	5.4.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails613

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Use Webpack to manage app-like JavaScript modules in Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activesupport613>=5.2:devel/rubygem-activesupport613 \
		rubygem-rack-proxy>=0.6.1:www/rubygem-rack-proxy \
		rubygem-railties613>=5.2:www/rubygem-railties613 \
		rubygem-semantic_range>=2.3.0:devel/rubygem-semantic_range \
		yarn:www/yarn

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
