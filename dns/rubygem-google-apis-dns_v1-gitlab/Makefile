PORTNAME=	google-apis-dns_v1
PORTVERSION=	0.49.0
CATEGORIES=	dns rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple REST client for Cloud DNS API V1
WWW=		https://github.com/googleapis/google-api-ruby-client/tree/main/generated/google-apis-dns_v1 \
		https://github.com/googleapis/google-api-ruby-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-apis-core-gitlab>=0.15.0<2.0:devel/rubygem-google-apis-core-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
