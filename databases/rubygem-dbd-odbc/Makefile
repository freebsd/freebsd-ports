# $FreeBSD$

PORTNAME=	dbd-odbc
PORTVERSION=	0.2.5
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	ODBC driver for DBI-for-Ruby

LICENSE=	BSD3CLAUSE

RUN_DEPENDS=	rubygem-dbi>=0:databases/rubygem-dbi \
		${RUBY_SITEARCHLIBDIR}/odbc.so:databases/ruby-odbc

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
