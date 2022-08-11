PORTNAME=	sentry-sidekiq
PORTVERSION=	5.1.1
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client interface for the Sentry error logger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-sentry-ruby-core>=5.1.1<5.2:devel/rubygem-sentry-ruby-core \
		rubygem-sidekiq64>=3.0:devel/rubygem-sidekiq64

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
