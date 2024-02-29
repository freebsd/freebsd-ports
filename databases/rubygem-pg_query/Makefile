PORTNAME=	pg_query
PORTVERSION=	5.1.0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Parses SQL queries using a copy of the PostgreSQL server query parser
WWW=		https://github.com/lfittl/pg_query

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_15=	fails to link: ld: error: version script assignment of 'global' to symbol '_Init_pg_query' failed: symbol not defined

BUILD_DEPENDS=	rubygem-pathname>0:devel/rubygem-pathname
RUN_DEPENDS=	rubygem-google-protobuf>=3.22.3:devel/rubygem-google-protobuf

USES=		gem

.include <bsd.port.mk>
