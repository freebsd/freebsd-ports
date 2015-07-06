# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	celluloid-pool
PORTVERSION=	0.20.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Actor pools for Celluloid

LICENSE=	MIT

RUN_DEPENDS=	rubygem-bundler>=0:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-dotenv>=0:${PORTSDIR}/misc/rubygem-dotenv \
		rubygem-nenv>=0:${PORTSDIR}/devel/rubygem-nenv \
		rubygem-rspec-logsplit>=0.1.2:${PORTSDIR}/devel/rubygem-rspec-logsplit \
		rubygem-timers>=4.0.0:${PORTSDIR}/devel/rubygem-timers

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
