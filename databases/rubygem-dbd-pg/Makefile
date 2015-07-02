# $FreeBSD$

PORTNAME=	dbd-pg
PORTVERSION=	0.3.9
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	PostgreSQL driver for DBI-for-Ruby

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-dbi>=0.4.0:${PORTSDIR}/databases/rubygem-dbi \
		rubygem-pg>=0:${PORTSDIR}/databases/rubygem-pg

NO_ARCH=	yes

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
