PORTNAME=	view_component
PORTVERSION=	4.12.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	View components for Rails
WWW=		https://github.com/github/view_component

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-actionview-gitlab>=7.1.0:devel/rubygem-actionview-gitlab \
		rubygem-activesupport-gitlab>=7.1.0:devel/rubygem-activesupport-gitlab \
		rubygem-concurrent-ruby>=1<2:devel/rubygem-concurrent-ruby

USES=		cpe gem

CPE_VENDOR=	viewcomponent

NO_ARCH=	yes

.include <bsd.port.mk>
