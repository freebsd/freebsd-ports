# $FreeBSD$

PORTNAME=	generator_spec
PORTVERSION=	0.9.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Test Rails generators with RSpec

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activerecord4>=4.1.4:databases/rubygem-activerecord4 \
		rubygem-railties4>=4.1.4:www/rubygem-railties4

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
