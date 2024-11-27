PORTNAME=	cf-uaa-lib
PORTVERSION=	4.0.7
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Client library for CloudFoundry UAA
WWW=		https://github.com/cloudfoundry/cf-uaa-lib

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.8.0<3:www/rubygem-addressable \
		rubygem-httpclient>=2.8.2.4<3:www/rubygem-httpclient \
		rubygem-json>=2.7<3:devel/rubygem-json

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
