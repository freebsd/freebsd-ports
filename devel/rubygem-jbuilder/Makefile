PORTNAME=	jbuilder
PORTVERSION=	2.9.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Create JSON structures via a Builder-style DSL

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/MIT-LICENSE

RUN_DEPENDS?=	rubygem-activesupport4>=4.2.0:devel/rubygem-activesupport4

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

# jbuilder 2.10.0+ requires Rails 5.0+
PORTSCOUT=	limit:^2\.9\.

.include <bsd.port.mk>
