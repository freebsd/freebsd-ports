# $FreeBSD$

PORTNAME=	web-console
PORTVERSION=	4.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails60

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

BROKEN_RUBY24=	yes

RUN_DEPENDS=	rubygem-activemodel60>=6.0.0:databases/rubygem-activemodel60 \
		rubygem-actionview60>=6.0.0:devel/rubygem-actionview60 \
		rubygem-bindex>=0.4.0:devel/rubygem-bindex \
		rubygem-railties60>=6.0.0:www/rubygem-railties60

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
