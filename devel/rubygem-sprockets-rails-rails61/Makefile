PORTNAME=	sprockets-rails
PORTVERSION=	3.5.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Sprockets Rails integration
WWW=		https://github.com/rails/sprockets-rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actionpack61>=6.1:www/rubygem-actionpack61 \
		rubygem-activesupport61>=6.1:devel/rubygem-activesupport61 \
		rubygem-sprockets3>=3.0.0:devel/rubygem-sprockets3

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
