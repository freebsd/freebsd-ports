# Ports collection makefile for:	rubygem-systemu
# Date created:				18 Mar 2010
# Whom:					renchap@cocoa-x.com
#
# $FreeBSD$
#

PORTNAME=	systemu
PORTVERSION=	1.2.0
CATEGORIES=	devel
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	A portable replacement for popen4

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

# we care about not passing -A to allow HTTP redirects
FETCH_ARGS=	-pRr

.include <bsd.port.mk>
