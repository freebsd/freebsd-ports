# $FreeBSD$

PORTNAME=	postgres_ext
PORTVERSION=	3.0.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	PostgreSQL data types extension for ActiveRecord

LICENSE=	MIT

RUN_DEPENDS=	rubygem-activerecord4>=4.0.0:databases/rubygem-activerecord4 \
		rubygem-arel6>=4.0.1:databases/rubygem-arel6 \
		rubygem-pg_array_parser>=0.0.9:databases/rubygem-pg_array_parser

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
