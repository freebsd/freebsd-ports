PORTNAME=	pghero
DISTVERSION=	3.6.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Performance dashboard for Postgres
WWW=		https://github.com/ankane/pghero

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Ruby on Rails 6.1.x reaches EOL on 2024-10-01
EXPIRATION_DATE=	2024-10-24

RUN_DEPENDS=	rubygem-activerecord61>=5:databases/rubygem-activerecord61

USES=		cpe gem

NO_ARCH=	yes

CPE_VENDOR=	pghero_project

.include <bsd.port.mk>
