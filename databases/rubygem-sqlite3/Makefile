# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	1.3.9
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Ruby interface to the SQLite DB engine version 3

LICENSE=	BSD

BUILD_DEPENDS=	${LOCALBASE}/bin/swig:${PORTSDIR}/devel/swig13
LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3

CONFIGURE_ARGS=	--with-sqlite3-dir=${LOCALBASE}
GEM_NAME=	${DISTNAME}
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
