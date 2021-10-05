PORTNAME=	web-console
PORTVERSION=	4.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails613

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel613>=6.0.0:databases/rubygem-activemodel613 \
		rubygem-actionview613>=6.0.0:devel/rubygem-actionview613 \
		rubygem-bindex>=0.4.0:devel/rubygem-bindex \
		rubygem-railties613>=6.0.0:www/rubygem-railties613

USES=		cpe gem
USE_RUBY=	yes

NO_ARCH=	yes

CPE_VENDOR=	rubyonrails
CPE_PRODUCT=	web_console

.include <bsd.port.mk>
