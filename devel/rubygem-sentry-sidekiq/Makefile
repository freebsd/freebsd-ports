PORTNAME=	sentry-sidekiq
PORTVERSION=	5.21.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client interface for the Sentry error logger
WWW=		https://github.com/getsentry/sentry-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-sentry-ruby>=5.21.0<5.22:devel/rubygem-sentry-ruby \
		rubygem-sidekiq72>=3.0:devel/rubygem-sidekiq72

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
