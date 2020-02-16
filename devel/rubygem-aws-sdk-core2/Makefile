# $FreeBSD$

PORTNAME=	aws-sdk-core
PORTVERSION=	2.11.440
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AWS SDK for Ruby - Core

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-aws-sigv4>=1.0<2:devel/rubygem-aws-sigv4 \
		rubygem-jmespath>=1.0<2:devel/rubygem-jmespath

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/aws.rb

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
