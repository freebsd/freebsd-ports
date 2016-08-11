# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	celluloid
PORTVERSION=	0.17.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Build concurrent programs out of concurrent objects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-celluloid-essentials>=0:devel/rubygem-celluloid-essentials \
		rubygem-celluloid-extras>=0:devel/rubygem-celluloid-extras \
		rubygem-celluloid-fsm>=0:devel/rubygem-celluloid-fsm \
		rubygem-celluloid-pool>=0:devel/rubygem-celluloid-pool \
		rubygem-celluloid-supervision>=0:devel/rubygem-celluloid-supervision \
		rubygem-timers>=4.1.1:devel/rubygem-timers

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
