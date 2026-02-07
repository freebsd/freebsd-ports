PORTNAME=	sprockets-rails
PORTVERSION=	3.5.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails81

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sprockets Rails integration
WWW=		https://github.com/rails/sprockets-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack81>=5.2:www/rubygem-actionpack81 \
		rubygem-activesupport81>=5.2:devel/rubygem-activesupport81 \
		rubygem-sprockets>=3.0.0:devel/rubygem-sprockets

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
