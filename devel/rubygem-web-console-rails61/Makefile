PORTNAME=	web-console
PORTVERSION=	4.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel61>=6.0.0:databases/rubygem-activemodel61 \
		rubygem-actionview61>=6.0.0:devel/rubygem-actionview61 \
		rubygem-bindex>=0.4.0:devel/rubygem-bindex \
		rubygem-railties61>=6.0.0:www/rubygem-railties61

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	web_console

.include <bsd.port.mk>
