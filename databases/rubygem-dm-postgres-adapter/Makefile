# Created by: stas
# $FreeBSD$

PORTNAME=	dm-postgres-adapter
PORTVERSION=	1.2.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	PostgreSQL Adapter for DataMapper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-dm-do-adapter>=${PORTVERSION}:${PORTSDIR}/databases/rubygem-dm-do-adapter \
		rubygem-do_postgres>=0.10.6:${PORTSDIR}/databases/rubygem-do_postgres

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
