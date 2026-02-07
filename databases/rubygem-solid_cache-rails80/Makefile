PORTNAME=	solid_cache
PORTVERSION=	1.0.10
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails80

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database-backed ActiveSupport::Cache::Store
WWW=		https://github.com/rails/solid_cache

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activejob80>=7.2:devel/rubygem-activejob80 \
		rubygem-activerecord80>=7.2:databases/rubygem-activerecord80 \
		rubygem-railties80>=7.2:www/rubygem-railties80

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
