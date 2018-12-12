# Created by: stas
# $FreeBSD$

PORTNAME=	dm-postgres-adapter
PORTVERSION=	1.2.0
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	PostgreSQL Adapter for DataMapper

LICENSE=	MIT

RUN_DEPENDS=	rubygem-dm-do-adapter>=${PORTVERSION}:databases/rubygem-dm-do-adapter \
		rubygem-do_postgres>=0.10.6:databases/rubygem-do_postgres

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
