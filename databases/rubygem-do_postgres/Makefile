# New ports collection makefile for: rubygem-do_postgres
# Date created:		28 April 2009
# Whom:		Espen Volden aka voldern <voldern@hoeggen.net>
#
# $FreeBSD$
#

PORTNAME=	do_postgres
PORTVERSION=	0.9.11
CATEGORIES=	databases rubygems
MASTER_SITES=	RUBYFORGE/dorb
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	voldern@hoeggen.net
COMMENT=	Ruby DataObjects driver for PostgreSQL

RUN_DEPENDS=	rubygem-data_objects>=0.9.11:${PORTSDIR}/databases/rubygem-data_objects

USE_PGSQL=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
