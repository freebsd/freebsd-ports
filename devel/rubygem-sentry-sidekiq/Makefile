PORTNAME=	sentry-sidekiq
PORTVERSION=	5.17.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client interface for the Sentry error logger
WWW=		https://github.com/getsentry/sentry-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-sentry-ruby>=5.17.3<5.18:devel/rubygem-sentry-ruby \
		rubygem-sidekiq71>=3.0:devel/rubygem-sidekiq71

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
