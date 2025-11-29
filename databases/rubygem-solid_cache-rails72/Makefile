PORTNAME=	solid_cache
PORTVERSION=	1.0.10
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database-backed ActiveSupport::Cache::Store
WWW=		https://github.com/rails/solid_cache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activejob72>=7.2:devel/rubygem-activejob72 \
		rubygem-activerecord72>=7.2:databases/rubygem-activerecord72 \
		rubygem-railties72>=7.2:www/rubygem-railties72

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
