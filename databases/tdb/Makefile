# ex:ts=8
# Ports collection makefile for:	tdb
# Date created:			Oct 12, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	tdb
PORTVERSION=	1.0.6
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Trivial Database

USE_AUTOMAKE_VER=	14
USE_AUTOCONF_VER=	213
USE_INC_LIBTOOL_VER=	13
INSTALLS_SHLIB=		yes

MAN3=	tdb.3 tdb_chainlock.3 tdb_close.3 tdb_delete.3 tdb_error.3 \
	tdb_exists.3 tdb_fetch.3 tdb_firstkey.3 tdb_open.3 tdb_store.3 \
	tdb_traverse.3

.include <bsd.port.mk>
