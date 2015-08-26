# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	celluloid
PORTVERSION=	0.17.1.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Build concurrent programs out of concurrent objects

LICENSE=	MIT

RUN_DEPENDS=	rubygem-bundler>=0:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-celluloid-essentials>=0:${PORTSDIR}/devel/rubygem-celluloid-essentials \
		rubygem-celluloid-extras>=0:${PORTSDIR}/devel/rubygem-celluloid-extras \
		rubygem-celluloid-fsm>=0:${PORTSDIR}/devel/rubygem-celluloid-fsm \
		rubygem-celluloid-pool>=0:${PORTSDIR}/devel/rubygem-celluloid-pool \
		rubygem-celluloid-supervision>=0:${PORTSDIR}/devel/rubygem-celluloid-supervision \
		rubygem-dotenv>=0:${PORTSDIR}/misc/rubygem-dotenv \
		rubygem-nenv>=0:${PORTSDIR}/devel/rubygem-nenv \
		rubygem-rspec-logsplit>=0.1.2:${PORTSDIR}/devel/rubygem-rspec-logsplit \
		rubygem-timers>=4.1.1:${PORTSDIR}/devel/rubygem-timers

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
