PORTNAME=	graphiql-rails
# do not upgrade to 1.9.0, it will break gitlab-ce asset compilation
# https://gitlab.com/gitlab-org/gitlab/-/issues/410500
PORTVERSION=	1.10.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Use the GraphiQL IDE for GraphQL with Ruby on Rails
WWW=		https://github.com/rmosolgo/graphiql-rails

LICENSE=	MIT

RUN_DEPENDS=	rubygem-railties70>=0:www/rubygem-railties70

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
