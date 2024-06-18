PORTNAME=	sprockets-rails
PORTVERSION=	3.4.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails52

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sprockets Rails integration
WWW=		https://github.com/rails/sprockets-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack52>=5.2:www/rubygem-actionpack52 \
		rubygem-activesupport52>=5.2:devel/rubygem-activesupport52 \
		rubygem-sprockets3>=3.0.0:devel/rubygem-sprockets3

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.4\.

.include <bsd.port.mk>
