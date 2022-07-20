PORTNAME=	celluloid-io
PORTVERSION=	0.17.3
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Evented IO for Celluloid actors

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-celluloid>=0.17.2:devel/rubygem-celluloid \
		rubygem-nio4r>=1.1:devel/rubygem-nio4r \
		rubygem-timers>=4.1.1:devel/rubygem-timers

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
