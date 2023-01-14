PORTNAME=	request_store
PORTVERSION=	1.4.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	14

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	RequestStore gives you per-request global storage
WWW=		https://github.com/steveklabnik/request_store

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-rack16>=1.4:www/rubygem-rack16

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.4\.

.include <bsd.port.mk>
