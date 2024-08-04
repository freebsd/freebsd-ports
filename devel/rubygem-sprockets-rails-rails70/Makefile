PORTNAME=	sprockets-rails
PORTVERSION=	3.5.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails70

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sprockets Rails integration
WWW=		https://github.com/rails/sprockets-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack70>=5.2:www/rubygem-actionpack70 \
		rubygem-activesupport70>=5.2:devel/rubygem-activesupport70 \
		rubygem-sprockets3>=3.0.0:devel/rubygem-sprockets3

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
