PORTNAME=	solid_cable
PORTVERSION=	3.0.12
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database-backed Action Cable backend
WWW=		https://github.com/rails/solid_cable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actioncable81>=7.2:www/rubygem-actioncable81 \
		rubygem-activejob81>=7.2:devel/rubygem-activejob81 \
		rubygem-activerecord81>=7.2:databases/rubygem-activerecord81 \
		rubygem-railties81>=7.2:www/rubygem-railties81

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
