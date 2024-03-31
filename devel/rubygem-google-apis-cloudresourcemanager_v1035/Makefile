PORTNAME=	google-apis-cloudresourcemanager_v1
PORTVERSION=	0.35.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	035

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Simple REST client for Cloud Resource Manager API V1
WWW=		https://github.com/googleapis/google-api-ruby-client/tree/main/generated/google-apis-cloudresourcemanager_v1 \
		https://github.com/googleapis/google-api-ruby-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-apis-core>=0.11.0<2.0:devel/rubygem-google-apis-core

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.35\.

.include <bsd.port.mk>
