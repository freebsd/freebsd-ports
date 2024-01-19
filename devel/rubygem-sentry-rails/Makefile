PORTNAME=	sentry-rails
PORTVERSION=	5.10.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client interface for the Sentry error logger
WWW=		https://github.com/getsentry/sentry-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-railties70>=5.0.0:www/rubygem-railties70 \
		rubygem-sentry-ruby>=5.10.0<5.11:devel/rubygem-sentry-ruby

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
