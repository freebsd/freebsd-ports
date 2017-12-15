# $FreeBSD$

PORTNAME=	peek-pg
PORTVERSION=	1.3.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	idefix@fechner.net
COMMENT=	Take a peek into the MySQL queries made

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-concurrent-ruby>=0:devel/rubygem-concurrent-ruby \
		rubygem-concurrent-ruby-ext>=0:devel/rubygem-concurrent-ruby-ext \
		rubygem-pg>=0:databases/rubygem-pg \
		rubygem-peek>=0.1.0:devel/rubygem-peek

NO_ARCH=	yes
USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
