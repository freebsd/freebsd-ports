# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	celluloid
PORTVERSION=	0.17.4
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Build concurrent programs out of concurrent objects

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-celluloid-essentials>=0:devel/rubygem-celluloid-essentials \
		rubygem-celluloid-extras>=0:devel/rubygem-celluloid-extras \
		rubygem-celluloid-fsm>=0:devel/rubygem-celluloid-fsm \
		rubygem-celluloid-pool>=0:devel/rubygem-celluloid-pool \
		rubygem-celluloid-supervision>=0:devel/rubygem-celluloid-supervision \
		rubygem-timers>=4.1.1:devel/rubygem-timers

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
