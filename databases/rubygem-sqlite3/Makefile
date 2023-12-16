PORTNAME=	sqlite3
PORTVERSION=	1.6.9
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 3
WWW=		https://github.com/sparklemotion/sqlite3-ruby

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem sqlite

CONFIGURE_ARGS=	--enable-system-libraries --with-sqlite3-dir=${LOCALBASE}

.include <bsd.port.mk>
