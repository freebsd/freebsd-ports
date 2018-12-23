# $FreeBSD$

PORTNAME=	peek-mysql2
PORTVERSION=	1.2.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails50

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Take a peek into the MySQL queries made

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-concurrent-ruby>=0:devel/rubygem-concurrent-ruby \
		rubygem-concurrent-ruby-ext>=0:devel/rubygem-concurrent-ruby-ext \
		rubygem-mysql2>=0:databases/rubygem-mysql2 \
		rubygem-peek-rails50>=0.1.0:devel/rubygem-peek-rails50

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
