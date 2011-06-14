# Ports collection makefile for:	gem-logging
# Date created:				06 Nov 2009
# Whom:					Ryan Steinmetz (<rpsfa@rit.edu>)
#
# $FreeBSD$

PORTNAME=	logging
PORTVERSION=	1.5.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	rpsfa@rit.edu
COMMENT=	Logging library based on Java's log4j

RUN_DEPENDS=	rubygem-little_plugger>=1.1.2:${PORTSDIR}/devel/rubygem-little_plugger \
		rubygem-flexmock>=0.8.11:${PORTSDIR}/devel/ruby-flexmock \
		rlock:${PORTSDIR}/devel/rubygem-lockfile

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
