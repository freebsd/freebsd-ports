PORTNAME=	sentry-ruby-core
PORTVERSION=	5.18.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client interface for the Sentry error logger
WWW=		https://github.com/getsentry/sentry-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-concurrent-ruby>=0:devel/rubygem-concurrent-ruby \
		rubygem-sentry-ruby>=5.18.2<5.18.3:devel/rubygem-sentry-ruby

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
