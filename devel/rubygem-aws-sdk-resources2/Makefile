# $FreeBSD$

PORTNAME=	aws-sdk-resources
PORTVERSION=	2.11.452
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AWS SDK for Ruby Resources

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-aws-sdk-core2>=${PORTVERSION}:devel/rubygem-aws-sdk-core2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
