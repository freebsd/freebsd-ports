# Created by: Cheng-Lung Sung <clsung@FreeBSD.org>
# $FreeBSD$

PORTNAME=	dbd_sqlite3
PORTVERSION=	1.2.5
CATEGORIES=	databases ruby
MASTER_SITES=	RF
MASTER_SITE_SUBDIR=	ruby-dbi
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DISTNAME=	dbd-sqlite3-${PORTVERSION}
DIST_SUBDIR=	ruby

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	SQLite3 driver for DBI-for-Ruby

LIB_DEPENDS=	libsqlite3.so:${PORTSDIR}/databases/sqlite3
RUN_DEPENDS=	${RUBY_SITELIBDIR}/dbi.rb:${PORTSDIR}/databases/ruby-dbi

USE_RUBY=	yes
USE_RUBY_SETUP=	yes

NO_STAGE=	yes
.include <bsd.port.mk>
