# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	1.3.13
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 3

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig3.0:devel/swig30
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

CONFIGURE_ARGS=	--with-sqlite3-dir=${LOCALBASE}
USE_RUBY=	yes
USES=		gem
BINARY_ALIAS=	swig=swig3.0

.include <bsd.port.mk>
