# $FreeBSD$

PORTNAME=	active_model_serializers
PORTVERSION=	0.10.6
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Conventions-based JSON generation for Rails

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activemodel5>0:databases/rubygem-activemodel5 \
		rubygem-actionpack5>0:www/rubygem-actionpack5 \
		rubygem-railties5>0:www/rubygem-railties5 \
		rubygem-jsonapi-renderer>0.1:devel/rubygem-jsonapi-renderer \
		rubygem-case_transform>=0.2:textproc/rubygem-case_transform

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
