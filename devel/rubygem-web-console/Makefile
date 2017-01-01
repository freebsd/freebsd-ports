# $FreeBSD$

PORTNAME=	web-console
PORTVERSION=	3.3.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Debugging tool for your Ruby on Rails applications

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel4>=4.2:databases/rubygem-activemodel4 \
		rubygem-debug_inspector>=0:devel/rubygem-debug_inspector \
		rubygem-railties4>=4.2:www/rubygem-railties4

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
