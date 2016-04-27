# $FreeBSD$

PORTNAME=	grape
PORTVERSION=	0.15.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Framework for rapid API development with great conventions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport4>=0:devel/rubygem-activesupport4 \
		rubygem-builder32>=0:devel/rubygem-builder32 \
		rubygem-hashie>=2.1.0:devel/rubygem-hashie \
		rubygem-multi_json>=1.3.2:devel/rubygem-multi_json \
		rubygem-multi_xml>=0.5.2:textproc/rubygem-multi_xml \
		rubygem-rack16>=1.3.0:www/rubygem-rack16 \
		rubygem-rack-accept>=0:www/rubygem-rack-accept \
		rubygem-rack-mount>=0:www/rubygem-rack-mount\
		rubygem-virtus>=1.0.0:devel/rubygem-virtus

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
