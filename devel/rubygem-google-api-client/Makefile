# $FreeBSD$

PORTNAME=	google-api-client
PORTVERSION=	0.19.1
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

# bin/generate-api
CONFLICTS_INSTALL=	rubygem-google-api-client010

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

PLIST_FILES=	bin/generate-api

.include <bsd.port.mk>
