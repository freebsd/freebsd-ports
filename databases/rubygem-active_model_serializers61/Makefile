PORTNAME=	active_model_serializers
PORTVERSION=	0.10.13
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	61

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Conventions-based JSON generation for Rails
WWW=		https://github.com/rails-api/active_model_serializers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS=	rubygem-activemodel61>=4.1<7.1:databases/rubygem-activemodel61 \
		rubygem-actionpack61>=4.1<7.1:www/rubygem-actionpack61 \
		rubygem-case_transform61>=0.2:textproc/rubygem-case_transform61 \
		rubygem-jsonapi-renderer>=0.1.1<0.3:devel/rubygem-jsonapi-renderer

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
