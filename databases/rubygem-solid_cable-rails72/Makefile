PORTNAME=	solid_cable
PORTVERSION=	3.0.12
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails72

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database-backed Action Cable backend
WWW=		https://github.com/rails/solid_cable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actioncable72>=7.2:www/rubygem-actioncable72 \
		rubygem-activejob72>=7.2:devel/rubygem-activejob72 \
		rubygem-activerecord72>=7.2:databases/rubygem-activerecord72 \
		rubygem-railties72>=7.2:www/rubygem-railties72

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
