PORTNAME=	google-apis-core
PORTVERSION=	1.2.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common utility and base classes for legacy Google REST clients
WWW=		https://github.com/googleapis/google-api-ruby-client/tree/main/google-apis-core \
		https://github.com/googleapis/google-api-ruby-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-addressable>=2.9<3:www/rubygem-addressable \
		rubygem-faraday>=2.13<3:www/rubygem-faraday \
		rubygem-faraday-follow_redirects>=0.3<1:www/rubygem-faraday-follow_redirects \
		rubygem-googleauth>=1.14<2:security/rubygem-googleauth \
		rubygem-mini_mime>=1.1<2:mail/rubygem-mini_mime \
		rubygem-multi_json>=1.11<2:devel/rubygem-multi_json \
		rubygem-representable>=3.0<4:textproc/rubygem-representable \
		rubygem-retriable4>=3.1<5.0:devel/rubygem-retriable4

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
