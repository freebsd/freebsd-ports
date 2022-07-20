PORTNAME=	view_component
PORTVERSION=	2.50.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails61

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	View components for Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport61>=5<8:devel/rubygem-activesupport61 \
		rubygem-method_source>=1.0<2:devel/rubygem-method_source

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
