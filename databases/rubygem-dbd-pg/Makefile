# $FreeBSD$

PORTNAME=	dbd-pg
PORTVERSION=	0.3.9
PORTREVISION=	3
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	PostgreSQL driver for DBI-for-Ruby

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-dbi>=0.4.0:databases/rubygem-dbi \
		rubygem-pg>=0:databases/rubygem-pg

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
