# $FreeBSD$

PORTNAME=	grape
PORTVERSION=	1.2.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Framework for rapid API development with great conventions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport52>=0:devel/rubygem-activesupport52 \
		rubygem-builder>=0:devel/rubygem-builder \
		rubygem-mustermann-grape>=1.0.0<1.1:devel/rubygem-mustermann-grape \
		rubygem-rack>=1.3.0:www/rubygem-rack \
		rubygem-rack-accept>=0:www/rubygem-rack-accept \
		rubygem-virtus>=1.0.0:devel/rubygem-virtus

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
