PORTNAME=	pghero
PORTVERSION=	2.8.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails5

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Performance dashboard for Postgres

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activerecord5>=5:databases/rubygem-activerecord5

USES=		cpe gem
CPE_VENDOR=	${PORTNAME}_project
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
