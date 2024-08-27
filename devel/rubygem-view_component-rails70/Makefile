PORTNAME=	view_component
PORTVERSION=	3.13.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails70

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	View components for Rails
WWW=		https://github.com/github/view_component

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport70>=5.2.0<8:devel/rubygem-activesupport70 \
		rubygem-concurrent-ruby>=1.0<2:devel/rubygem-concurrent-ruby \
		rubygem-method_source>=1.0<2:devel/rubygem-method_source

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
