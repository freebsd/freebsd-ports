PORTNAME=	sentry-ruby
PORTVERSION=	5.18.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client interface for the Sentry error logger
WWW=		https://github.com/getsentry/sentry-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-bigdecimal>0:math/rubygem-bigdecimal \
		rubygem-concurrent-ruby>=1.0.2<2:devel/rubygem-concurrent-ruby

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
