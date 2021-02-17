# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cucumber-messages
PORTVERSION=	13.2.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	13

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Protocol Buffer messages for Cucumber

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-protobuf-cucumber>=3.10.8<4:devel/rubygem-protobuf-cucumber

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^13\.

.include <bsd.port.mk>
