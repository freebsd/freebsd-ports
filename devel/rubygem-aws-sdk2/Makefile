# $FreeBSD$

PORTNAME=	aws-sdk
DISTVERSION=	2.11.385
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	2

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	AWS SDK for Ruby

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-aws-sdk-resources2>=${PORTVERSION}:devel/rubygem-aws-sdk-resources2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PORTSCOUT=	limit:^2\.

.include <bsd.port.mk>
