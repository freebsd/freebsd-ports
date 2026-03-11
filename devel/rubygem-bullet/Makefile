PORTNAME=	bullet
PORTVERSION=	8.1.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX?=	# empty for base port

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Help to kill N+1 queries and unused eager loading
WWW=		https://github.com/flyerhzm/bullet

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

# Default to ActiveSupport 7.1 for the base port, can be overridden by slave ports
ACTIVESUPPORT_VERSION?=	71
RUN_DEPENDS=	rubygem-activesupport${ACTIVESUPPORT_VERSION}>=3.0.0:devel/rubygem-activesupport${ACTIVESUPPORT_VERSION} \
		rubygem-uniform_notifier>=1.11:devel/rubygem-uniform_notifier

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
