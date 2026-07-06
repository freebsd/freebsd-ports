PORTNAME=	gitlab-grape-openapi
PORTVERSION=	0.2.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Generates OpenAPI 3.0 spec files
WWW=		https://gitlab.com/gitlab-org/ruby/gems/gitlab-grape-openapi

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-grape20>=0:devel/rubygem-grape20 \
		rubygem-grape-entity>=1.0.1<1.1,1:devel/rubygem-grape-entity \
		rubygem-js_regex>=3.8.0<4.0:textproc/rubygem-js_regex

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
