PORTNAME=	sentry-ruby
PORTVERSION=	5.1.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client interface for the Sentry error logger

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0.2<2:devel/rubygem-concurrent-ruby \
		rubygem-sentry-ruby-core>=5.1.1<5.1.2:devel/rubygem-sentry-ruby-core

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
