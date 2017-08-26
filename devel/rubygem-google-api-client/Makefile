# $FreeBSD$

PORTNAME=	google-api-client
PORTVERSION=	0.13.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Client for accessing Google APIs

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.5.1:www/rubygem-addressable \
		rubygem-googleauth>=0.5:security/rubygem-googleauth \
		rubygem-httpclient>=2.8.1:www/rubygem-httpclient \
		rubygem-mime-types>=3.0:misc/rubygem-mime-types \
		rubygem-representable>=3.0:textproc/rubygem-representable \
		rubygem-retriable>=2.0:devel/rubygem-retriable

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/generate-api

.include <bsd.port.mk>
