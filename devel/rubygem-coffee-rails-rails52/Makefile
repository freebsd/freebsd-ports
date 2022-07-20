PORTNAME=	coffee-rails
PORTVERSION=	5.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Coffee Script adapter for the Rails asset pipeline

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-coffee-script>=2.2.0:devel/rubygem-coffee-script \
		rubygem-railties52>=5.2.0:www/rubygem-railties52

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
