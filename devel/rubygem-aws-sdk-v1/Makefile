# $FreeBSD$

PORTNAME=	aws-sdk-v1
PORTVERSION=	1.67.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	AWS SDK for Ruby V1

LICENSE=	APACHE20

RUN_DEPENDS=	rubygem-json1>=1.4:devel/rubygem-json1 \
		rubygem-nokogiri>=1:textproc/rubygem-nokogiri

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

PLIST_FILES=	bin/aws-rb

.include <bsd.port.mk>
