PORTNAME=	google-apis-core
PORTVERSION=	0.18.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Common utility and base classes for legacy Google REST clients
WWW=		https://github.com/googleapis/google-api-ruby-client/tree/main/google-apis-core \
		https://github.com/googleapis/google-api-ruby-client

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-addressable>=2.5.1<3:www/rubygem-addressable \
		rubygem-googleauth-gitlab>=1.9<2:security/rubygem-googleauth-gitlab \
		rubygem-httpclient>=2.8.3<3.0:www/rubygem-httpclient \
		rubygem-mini_mime>=1.0<2:mail/rubygem-mini_mime \
		rubygem-mutex_m>=0:devel/rubygem-mutex_m \
		rubygem-representable>=3.0<4:textproc/rubygem-representable \
		rubygem-retriable>=2.0<4.0:devel/rubygem-retriable

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
