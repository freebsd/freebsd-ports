# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	pg_query
PORTVERSION=	2.0.3
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Parses SQL queries using a copy of the PostgreSQL server query parser

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	${LOCALBASE}/lib/libpg_query.a:databases/libpg_query
BUILD_DEPENDS=	${MY_DEPENDS} \
		rubygem-pathname>0:devel/rubygem-pathname
# rubygem-google-protobuf 3.17.1 is required to fix a segfault
# see PR: https://github.com/pganalyze/pg_query/pull/212
# and https://github.com/pganalyze/pg_query/pull/213
RUN_DEPENDS=	${MY_DEPENDS} \
		rubygem-google-protobuf>=3.17.1:devel/rubygem-google-protobuf

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
