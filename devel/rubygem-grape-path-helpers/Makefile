PORTNAME=	grape-path-helpers
PORTVERSION=	2.0.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Route path helpers for Grape
WWW=		https://gitlab.com/gitlab-org/grape-path-helpers

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-activesupport70>=0:devel/rubygem-activesupport70 \
		rubygem-grape>=2.0<3:devel/rubygem-grape \
		rubygem-rake>=12:devel/rubygem-rake \
		rubygem-ruby2_keywords>=0.0.2<0.1:devel/rubygem-ruby2_keywords

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
