# Ports collection makefile for:	gem-logging
# Date created:				06 Nov 2009
# Whom:					Ryan Steinmetz (<rpsfa@rit.edu>)
#
# $FreeBSD$

PORTNAME=	logging
PORTVERSION=	1.2.2
CATEGORIES=	devel rubygems
MASTER_SITES=	RF

MAINTAINER=	rpsfa@rit.edu
COMMENT=	Logging library based on Java's log4j

RUN_DEPENDS=	${LOCALBASE}/${GEMS_BASE_DIR}/cache/little-plugger-1.0.1.gem:${PORTSDIR}/devel/rubygem-little_plugger \
		${LOCALBASE}/${GEMS_BASE_DIR}/cache/flexmock-0.8.6.gem:${PORTSDIR}/devel/ruby-flexmock \
		rlock:${PORTSDIR}/devel/rubygem-lockfile

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
