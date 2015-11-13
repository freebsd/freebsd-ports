# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	1.3.11
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 3

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

CONFIGURE_ARGS=	--with-sqlite3-dir=${LOCALBASE}
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
