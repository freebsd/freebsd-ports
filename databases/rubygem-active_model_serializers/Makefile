# $FreeBSD$

PORTNAME=	active_model_serializers
PORTVERSION=	0.10.10
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Conventions-based JSON generation for Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel5>=4.1<6.1:databases/rubygem-activemodel5 \
		rubygem-actionpack5>=4.1<6.1:www/rubygem-actionpack5 \
		rubygem-case_transform>=0.2:textproc/rubygem-case_transform \
		rubygem-jsonapi-renderer>=0.1.1<0.3:devel/rubygem-jsonapi-renderer

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
