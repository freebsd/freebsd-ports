# New ports collection makefile for:	rubygem-dm-postgres-adapter
# Date created:		02/10/2011
# Whom:			stas
#
# $FreeBSD$
#

PORTNAME=	dm-postgres-adapter
PORTVERSION=	1.2.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	PostgreSQL Adapter for DataMapper

RUN_DEPENDS=	rubygem-do_postgres>=0.10.2:${PORTSDIR}/databases/rubygem-do_postgres \
		rubygem-dm-do-adapter>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-do-adapter

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
