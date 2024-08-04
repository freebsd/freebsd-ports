PORTNAME=	google-apis-generator
PORTVERSION=	0.15.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Code generator for legacy Google REST clients
WWW=		https://github.com/googleapis/google-api-ruby-client/tree/main/google-apis-generator \
		https://github.com/googleapis/google-api-ruby-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-activesupport60>=5.0:devel/rubygem-activesupport60 \
		rubygem-gems>=1.2<2:devel/rubygem-gems \
		rubygem-google-apis-core>=0.15.0<2.0:devel/rubygem-google-apis-core \
		rubygem-google-apis-discovery_v1>=0.18<1:devel/rubygem-google-apis-discovery_v1 \
		rubygem-thor>=0.20<2:devel/rubygem-thor

USES=		gem

NO_ARCH=	yes

PLIST_FILES=	bin/generate-api

.include <bsd.port.mk>
