PORTNAME=	web-console
PORTVERSION=	4.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails81

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications
WWW=		https://github.com/rails/web-console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel81>=6.0.0:databases/rubygem-activemodel81 \
		rubygem-actionview81>=6.0.0:devel/rubygem-actionview81 \
		rubygem-bindex>=0.4.0:devel/rubygem-bindex \
		rubygem-railties81>=6.0.0:www/rubygem-railties81

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	web_console

.include <bsd.port.mk>
