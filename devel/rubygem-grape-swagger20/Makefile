PORTNAME=	grape-swagger
PORTVERSION=	2.0.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	20

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Documentation tool for grape APIs
WWW=		https://github.com/ruby-grape/grape-swagger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-grape>=1.7<3.0:devel/rubygem-grape \
		rubygem-rack-test>=2<3:www/rubygem-rack-test

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.0\.

.include <bsd.port.mk>
