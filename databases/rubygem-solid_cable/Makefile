PORTNAME=	solid_cable
PORTVERSION=	3.0.12
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Database-backed Action Cable backend
WWW=		https://github.com/rails/solid_cable

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-actioncable80>=7.2:www/rubygem-actioncable80 \
		rubygem-activejob80>=7.2:devel/rubygem-activejob80 \
		rubygem-activerecord80>=7.2:databases/rubygem-activerecord80 \
		rubygem-railties80>=7.2:www/rubygem-railties80

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
