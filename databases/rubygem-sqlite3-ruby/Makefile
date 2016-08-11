# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sqlite3-ruby
PORTVERSION=	1.3.3
PORTREVISION=	1
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 3

LICENSE=	BSD3CLAUSE

BUILD_DEPENDS=	swig:devel/swig13
LIB_DEPENDS=	libsqlite3.so:databases/sqlite3
RUN_DEPENDS=	rubygem-sqlite3>=1.3.3:databases/rubygem-sqlite3

CONFIGURE_ARGS=	--with-sqlite3-dir=${LOCALBASE}
NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/sqlite3_ruby

.include <bsd.port.mk>
