PORTNAME=	google-apis-compute_v1
PORTVERSION=	0.57.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	_057

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple REST client for Compute Engine API V1
WWW=		https://github.com/googleapis/google-api-ruby-client/tree/main/generated/google-apis-compute_v1

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-apis-core>=0.9.1<2.0:devel/rubygem-google-apis-core

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.57\.

.include <bsd.port.mk>
