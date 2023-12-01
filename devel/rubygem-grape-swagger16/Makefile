PORTNAME=	grape-swagger
PORTVERSION=	1.6.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	16

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Documentation tool for grape APIs
WWW=		https://github.com/ruby-grape/grape-swagger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-grape1>=1.3<2:devel/rubygem-grape1

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^1\.6\.

.include <bsd.port.mk>
