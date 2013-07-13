# Created by: Espen Volden aka voldern <voldern@hoeggen.net>
# $FreeBSD$

PORTNAME=	do_sqlite3
PORTVERSION=	0.10.13
CATEGORIES=	databases rubygems
MASTER_SITES=	RG

MAINTAINER=	voldern@hoeggen.net
COMMENT=	Ruby DataObjects driver to the SQLite DB engine version 3

LIB_DEPENDS=	sqlite3.8:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	rubygem-data_objects>=0.10.13:${PORTSDIR}/databases/rubygem-data_objects

USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

CONFIGURE_ARGS=	--with-sqlite3-dir=${LOCALBASE}

.include <bsd.port.mk>
