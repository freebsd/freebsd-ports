PORTNAME=	web-console
PORTVERSION=	4.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails71

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications
WWW=		https://github.com/rails/web-console

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel71>=6.0.0:databases/rubygem-activemodel71 \
		rubygem-actionview71>=6.0.0:devel/rubygem-actionview71 \
		rubygem-bindex>=0.4.0:devel/rubygem-bindex \
		rubygem-railties71>=6.0.0:www/rubygem-railties71

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	web_console

.include <bsd.port.mk>
