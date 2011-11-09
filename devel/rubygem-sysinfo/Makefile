# New ports collection makefile for:	rubygem-sysinfo
# Date created:		2011-11-07
# Whom:			Sunpoet Po-Chuan Hsieh <sunpoet@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	sysinfo
PORTVERSION=	0.7.3
CATEGORIES=	devel ruby
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	All your system-independent infoz in one handy class

RUN_DEPENDS=	rubygem-drydock>=0:${PORTSDIR}/devel/rubygem-drydock \
		rubygem-storable>=0:${PORTSDIR}/devel/rubygem-storable

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES=	bin/sysinfo

.include <bsd.port.mk>
