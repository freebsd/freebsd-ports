# Ports collection makefile for:	rubygem-analogger
# Date created:				01 April 2007
# Whom:					Alexander Logvinov <ports@logvinov.com>
#
# $FreeBSD$

PORTNAME=	analogger
PORTVERSION=	0.5.0
CATEGORIES=	devel rubygems
MASTER_SITES=	${MASTER_SITE_RUBYFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@logvinov.com
COMMENT=	A fast, flexible, easy to use logging service for Ruby

BUILD_DEPENDS=	rubygem-eventmachine>=0.7.0:${PORTSDIR}/devel/rubygem-eventmachine
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_RUBY=	yes
USE_RUBYGEMS=	yes

.include <bsd.port.mk>
