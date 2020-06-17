# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	1.4.2
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 3

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	swig:devel/swig
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3

USES=		gem
USE_RUBY=	yes

CONFIGURE_ARGS=	--with-sqlite3-dir=${LOCALBASE}

.include <bsd.port.mk>
