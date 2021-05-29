# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	pg_query
PORTVERSION=	2.0.3
PORTREVISION=	0
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Parses SQL queries using a copy of the PostgreSQL server query parser

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

MY_DEPENDS=	${LOCALBASE}/lib/libpg_query.a:databases/libpg_query
BUILD_DEPENDS=	${MY_DEPENDS} \
		rubygem-pathname>0:devel/rubygem-pathname
RUN_DEPENDS=	${MY_DEPENDS} \
		rubygem-google-protobuf315>=3.15.5<3.16:devel/rubygem-google-protobuf315

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
