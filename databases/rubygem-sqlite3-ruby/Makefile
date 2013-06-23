# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sqlite3-ruby
PORTVERSION=	1.3.3
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 3

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3
BUILD_DEPENDS=	swig:${PORTSDIR}/devel/swig13
RUN_DEPENDS=	rubygem-sqlite3>=1.3.3:${PORTSDIR}/databases/rubygem-sqlite3

CONFIGURE_ARGS+=--with-sqlite3-dir=${LOCALBASE}

GEM_NAME=	${DISTNAME}

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

PLIST_FILES+=	bin/sqlite3_ruby

.include <bsd.port.mk>
