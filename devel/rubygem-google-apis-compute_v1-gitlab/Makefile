PORTNAME=	google-apis-compute_v1
PORTVERSION=	0.127.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple REST client for Compute Engine API V1
WWW=		https://github.com/googleapis/google-api-ruby-client/tree/main/generated/google-apis-compute_v1 \
		https://github.com/googleapis/google-api-ruby-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-apis-core-gitlab>=0.15.0<2.0:devel/rubygem-google-apis-core-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
