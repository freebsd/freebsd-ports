PORTNAME=	solid_cache
PORTVERSION=	1.0.10
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database-backed ActiveSupport::Cache::Store
WWW=		https://github.com/rails/solid_cache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activejob81>=7.2:devel/rubygem-activejob81 \
		rubygem-activerecord81>=7.2:databases/rubygem-activerecord81 \
		rubygem-railties81>=7.2:www/rubygem-railties81

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
