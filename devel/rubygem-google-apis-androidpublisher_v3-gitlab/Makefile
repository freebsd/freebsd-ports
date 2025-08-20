PORTNAME=	google-apis-androidpublisher_v3
PORTVERSION=	0.84.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Simple REST client for Google Play Android API V3
WWW=		https://github.com/google/google-api-ruby-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-apis-core-gitlab>=0.15.0<2.0:devel/rubygem-google-apis-core-gitlab

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^0\.84\.

.include <bsd.port.mk>
