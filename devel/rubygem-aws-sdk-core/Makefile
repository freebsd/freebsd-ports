# $FreeBSD$

PORTNAME=	aws-sdk-core
PORTVERSION=	2.0.41
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	AWS SDK for Ruby - Core

RUN_DEPENDS=	rubygem-multi_json>=1.0:${PORTSDIR}/devel/rubygem-multi_json \
		rubygem-builder>=3.0:${PORTSDIR}/devel/rubygem-builder \
		rubygem-jmespath>=1.0:${PORTSDIR}/devel/rubygem-jmespath

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=yes

PLIST_FILES=	bin/aws.rb

.include <bsd.port.mk>
