PORTNAME=	cf-uaa-lib
PORTVERSION=	4.0.9
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Client library for CloudFoundry UAA
WWW=		https://github.com/cloudfoundry/cf-uaa-lib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.8.0<3:www/rubygem-addressable \
		rubygem-base64>=0:converters/rubygem-base64 \
		rubygem-httpclient>=2.8.2.4<3:www/rubygem-httpclient \
		rubygem-json>=2.7<3:devel/rubygem-json \
		rubygem-mutex_m>=0:devel/rubygem-mutex_m

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
