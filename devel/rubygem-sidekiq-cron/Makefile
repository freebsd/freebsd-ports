PORTNAME=	sidekiq-cron
PORTVERSION=	1.7.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Enables to set jobs to be run in specified time (using CRON notation)

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-fugit>=1<2:devel/rubygem-fugit \
		rubygem-sidekiq>=4.2.1:devel/rubygem-sidekiq

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
