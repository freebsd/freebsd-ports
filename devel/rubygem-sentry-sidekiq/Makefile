PORTNAME=	sentry-sidekiq
PORTVERSION=	5.10.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client interface for the Sentry error logger
WWW=		https://github.com/getsentry/sentry-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-sentry-ruby>=5.10.0<5.11:devel/rubygem-sentry-ruby \
		rubygem-sidekiq>=3.0:devel/rubygem-sidekiq

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
