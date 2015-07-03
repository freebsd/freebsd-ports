# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fog-core
PORTVERSION=	1.32.0
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Shared classes and tests for fog providers and services

LICENSE=	MIT

RUN_DEPENDS=	rubygem-builder32>=0:${PORTSDIR}/devel/rubygem-builder32 \
		rubygem-excon>=0.45:${PORTSDIR}/devel/rubygem-excon \
		rubygem-formatador>=0.2:${PORTSDIR}/devel/rubygem-formatador \
		rubygem-mime-types>=0:${PORTSDIR}/misc/rubygem-mime-types \
		rubygem-net-scp>=1.1:${PORTSDIR}/security/rubygem-net-scp \
		rubygem-net-ssh>=2.1.3:${PORTSDIR}/security/rubygem-net-ssh

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
