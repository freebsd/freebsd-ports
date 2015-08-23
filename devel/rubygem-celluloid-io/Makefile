# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	celluloid-io
PORTVERSION=	0.17.0
PORTREVISION=	1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Evented IO for Celluloid actors

LICENSE=	MIT

RUN_DEPENDS=	rubygem-celluloid>=0.17:${PORTSDIR}/devel/rubygem-celluloid \
		rubygem-bundler>=0:${PORTSDIR}/sysutils/rubygem-bundler \
		rubygem-dotenv>=0:${PORTSDIR}/misc/rubygem-dotenv \
		rubygem-nenv>=0:${PORTSDIR}/devel/rubygem-nenv \
		rubygem-nio4r>=1.1:${PORTSDIR}/devel/rubygem-nio4r \
		rubygem-rspec-logsplit>=0.1.2:${PORTSDIR}/devel/rubygem-rspec-logsplit \
		rubygem-timers>=4.0.0:${PORTSDIR}/devel/rubygem-timers

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
