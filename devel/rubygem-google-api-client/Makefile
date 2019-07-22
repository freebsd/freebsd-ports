# $FreeBSD$

PORTNAME=	google-api-client
PORTVERSION=	0.30.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client for accessing Google APIs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.5.1:www/rubygem-addressable \
		rubygem-googleauth>=0.5<0.10.0:security/rubygem-googleauth \
		rubygem-httpclient>=2.8.1:www/rubygem-httpclient \
		rubygem-mini_mime>=1.0:mail/rubygem-mini_mime \
		rubygem-representable>=3.0:textproc/rubygem-representable \
		rubygem-retriable>=2.0<4.0:devel/rubygem-retriable \
		rubygem-signet>=0.10:security/rubygem-signet

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/generate-api

SHEBANG_FILES=	.kokoro/build.sh

.include <bsd.port.mk>
