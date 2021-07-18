# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	cucumber-messages
PORTVERSION=	15.0.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	15

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Protocol Buffer messages for Cucumber

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-protobuf-cucumber>=3.10.8<4:devel/rubygem-protobuf-cucumber

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^15\.

.include <bsd.port.mk>
