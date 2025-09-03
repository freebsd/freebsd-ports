PORTNAME=	pg
PORTVERSION=	1.6.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby interface to PostgreSQL library
WWW=		https://github.com/ged/ruby-pg

LICENSE=	BSD2CLAUSE RUBY
LICENSE_COMB=	dual
LICENSE_FILE_BSD2CLAUSE=${WRKSRC}/BSDL
LICENSE_FILE_RUBY=	${WRKSRC}/LICENSE

USES=		gem pgsql

CONFIGURE_ARGS=	--with-pgsql-include-dir=`${PG_CONFIG} --includedir` \
		--with-pgsql-lib-dir=`${PG_CONFIG} --libdir`
PG_CONFIG=	${LOCALBASE}/bin/pg_config

PORTSCOUT=	limit:^1\.6\.

.include <bsd.port.mk>
