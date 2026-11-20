PORTNAME=	redis-cloud-auth
PORTVERSION=	0.1.1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Pluggable credentials providers
WWW=		https://gitlab.com/gitlab-org/ruby/gems/redis-cloud-auth

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-logger-gitlab>=0:devel/rubygem-logger-gitlab \
		rubygem-redis-client>=0.14:databases/rubygem-redis-client

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
