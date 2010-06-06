# Ports collection makefile for:	rubygem-file-tail
# Date created:				06 October 2009
# Whom:					Eric Freeman <freebsdports@chillibear.com>
#
# $FreeBSD$
#

PORTNAME=	file-tail
PORTVERSION=	1.0.5
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	freebsdports@chillibear.com
COMMENT=	This is a small Ruby library that allows Ruby to 'tail' files

RUN_DEPENDS=	rubygem-spruz>=0.1.0:${PORTSDIR}/devel/rubygem-spruz

USE_RUBY=		yes
USE_RUBYGEMS=		yes
RUBYGEM_AUTOPLIST=	yes
PLIST_FILES=	bin/rtail

.include <bsd.port.mk>
