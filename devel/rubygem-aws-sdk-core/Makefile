# $FreeBSD$

PORTNAME=	aws-sdk-core
PORTVERSION=	2.1.30
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	AWS SDK for Ruby - Core

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-jmespath>=1.0:${PORTSDIR}/devel/rubygem-jmespath

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/aws.rb

.include <bsd.port.mk>
