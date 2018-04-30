# $FreeBSD$

PORTNAME=	web-console
PORTVERSION=	3.6.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel5>=5.0:databases/rubygem-activemodel5 \
		rubygem-actionview5>=5.0:devel/rubygem-actionview5 \
		rubygem-bindex>=0:devel/rubygem-bindex \
		rubygem-railties5>=5.0:www/rubygem-railties5

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
