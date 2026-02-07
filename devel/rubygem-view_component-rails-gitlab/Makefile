PORTNAME=	view_component
PORTVERSION=	3.23.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	View components for Rails
WWW=		https://github.com/github/view_component

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport-gitlab>=5.2.0<8.1:devel/rubygem-activesupport-gitlab \
		rubygem-concurrent-ruby>=1<2:devel/rubygem-concurrent-ruby \
		rubygem-method_source>=1.0<2:devel/rubygem-method_source

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
