# ports collection makefile for:	Berkeley DB
# Version required:			v2.2.6
# Date created:				12 Jun 1997
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $Id: Makefile,v 1.1.1.1 1997/06/13 17:54:36 jfitz Exp $
#

DISTNAME=	db-2.2.6
CATEGORIES=	databases
MASTER_SITES=	http://www.bostic.com/db/packages/

MAINTAINER=	josh@ican.net

WRKSRC=		${WRKDIR}/${DISTNAME}/build.unix

GNU_CONFIGURE=	YES
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS=		--enable-compat185 \
			--enable-dump185

MAN1=	db_archive.1 db_checkpoint.1 db_deadlock.1 db_dump.1 db_load.1 \
	db_recover.1 db_stat.1
MAN3=	db.3 db_appinit.3 db_cursor.3 db_dbm.3 db_hsearch.3 db_lock.3 \
	db_log.3 db_mpool.3 db_open.3 db_txn.3

.include <bsd.port.mk>
