# Ports collection makefile for:	rubygem-mixlib-authentication
# Date created:				18 Mar 2010
# Whom:					renchap@cocoa-x.com
#
# $FreeBSD$
#

PORTNAME=	mixlib-authentication
PORTVERSION=	1.1.2
CATEGORIES=	devel
MASTER_SITES=	RG

MAINTAINER=	renchap@cocoa-x.com
COMMENT=	Mixes in simple per-request authentication

BUILD_DEPENDS=	rubygem-mixlib-log>=1.1.0:${PORTSDIR}/devel/rubygem-mixlib-log
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
