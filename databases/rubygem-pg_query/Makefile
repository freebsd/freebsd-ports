# Created by: Matthias Fechner <mfechner@FreeBSD.org>

PORTNAME=	pg_query
PORTVERSION=	2.1.3
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Parses SQL queries using a copy of the PostgreSQL server query parser

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	rubygem-pathname>0:devel/rubygem-pathname
RUN_DEPENDS=	rubygem-google-protobuf>=3.19.2:devel/rubygem-google-protobuf

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
