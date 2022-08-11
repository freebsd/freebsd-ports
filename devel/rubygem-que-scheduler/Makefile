PORTNAME=	que-scheduler
PORTVERSION=	4.3.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Lightweight cron scheduler for the Que async job worker

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activesupport70>=5.0:devel/rubygem-activesupport70 \
		rubygem-fugit>=1.1.8<2:devel/rubygem-fugit \
		rubygem-hashie>=3<6:devel/rubygem-hashie \
		rubygem-que>=0.14<2.0.0:devel/rubygem-que

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
