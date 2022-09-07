PORTNAME=	google-apis-core
PORTVERSION=	0.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Common utility and base classes for legacy Google REST clients
WWW=		https://github.com/googleapis/google-api-ruby-client/tree/master/google-apis-core

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-addressable>=2.5.1<3:www/rubygem-addressable \
		rubygem-googleauth>=0.16.2<2.0:security/rubygem-googleauth \
		rubygem-httpclient>=2.8.1<3.0:www/rubygem-httpclient \
		rubygem-mini_mime>=1.0<2:mail/rubygem-mini_mime \
		rubygem-representable>=3.0<4:textproc/rubygem-representable \
		rubygem-retriable>=2.0<4.0:devel/rubygem-retriable \
		rubygem-rexml>=0:textproc/rubygem-rexml \
		rubygem-webrick>=0:www/rubygem-webrick

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
