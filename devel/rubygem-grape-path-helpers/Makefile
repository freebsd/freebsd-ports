PORTNAME=	grape-path-helpers
PORTVERSION=	2.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Route path helpers for Grape
WWW=		https://gitlab.com/gitlab-org/grape-path-helpers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport-gitlab>=0:devel/rubygem-activesupport-gitlab \
		rubygem-grape-gitlab>=2.0<4:devel/rubygem-grape-gitlab \
		rubygem-rake>=12:devel/rubygem-rake \
		rubygem-ruby2_keywords>=0.0.2<0.1:devel/rubygem-ruby2_keywords

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
