# $FreeBSD$

PORTNAME=	pg
PORTVERSION=	0.18.4
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	018

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby interface to PostgreSQL library

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE	=${WRKSRC}/BSDL
LICENSE_FILE_RUBY	=${WRKSRC}/LICENSE

PORTSCOUT=	limit:^0\.18\.

CONFIGURE_ARGS=	--with-pgsql-include-dir=`${PG_CONFIG} --includedir` \
		--with-pgsql-lib-dir=`${PG_CONFIG} --libdir`
PG_CONFIG=	${LOCALBASE}/bin/pg_config
USES=		gem pgsql
USE_RUBY=	yes

.include <bsd.port.mk>
