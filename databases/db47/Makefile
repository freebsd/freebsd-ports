# ports collection makefile for:	Berkeley DB
# Version required:			v2.3.16
# Date created:				26 Jan 1998
# Whom:					Josh Tiefenbach <josh@ican.net>
#
# $Id: Makefile,v 1.7 1998/01/26 18:43:20 jfitz Exp $
#

DISTNAME=	db-2.3.16
CATEGORIES=	databases
MASTER_SITES=	http://www.sleepycat.com/db/packages/

MAINTAINER=	josh@ican.net

Y2K=		http://www.sleepycat.com/faq.html#A8

MANUAL_PACKAGE_BUILD=	incompatible with libc version
WRKSRC=		${WRKDIR}/${DISTNAME}/build.unix

GNU_CONFIGURE=	YES
CONFIGURE_SCRIPT=	../dist/configure
CONFIGURE_ARGS=		--enable-compat185 \
			--enable-dump185 --enable-cxx

MAN1=	db_archive.1 db_checkpoint.1 db_deadlock.1 db_dump.1 db_load.1 \
	db_recover.1 db_stat.1
MAN3=	db_appinit.3 db_cursor.3 db_dbm.3 db_hsearch.3 db_intro.3 db_lock.3 \
	db_log.3 db_mpool.3 db_open.3 db_txn.3 \
	Db.3 DbEnv.3 DbException.3 DbInfo.3 DbLock.3 DbLockTab.3 DbLog.3 \
	DbLsn.3 DbMpool.3 DbMpoolFile.3 DbTxn.3 DbTxnMgr.3 Dbc.3 Dbt.3

post-install:
	${MKDIR} ${PREFIX}/share/doc/db
.for doc in hash.usenix.ps libtp.usenix.ps
	${INSTALL_DATA} ${WRKSRC}/../documents/${doc} ${PREFIX}/share/doc/db
	gzip -9 ${PREFIX}/share/doc/db/${doc}
.endfor
	${MKDIR} ${PREFIX}/share/examples/db
.for example in README ex_access.c ex_appinit.c ex_btrec.c ex_lock.c ex_mpool.c ex_tpcb.c ex_tpcb.h
	${INSTALL_DATA} ${WRKSRC}/../examples/${example} ${PREFIX}/share/examples/db
.endfor
.for example in AccessExample.cpp AppinitExample.cpp LockExample.cpp MpoolExample.cpp TpcbExample.cpp
	${INSTALL_DATA} ${WRKSRC}/../examples_cxx/${example} ${PREFIX}/share/examples/db
.endfor
	@echo ""
	@echo "Java support for ${PKGNAME} is *not* built by default, and requires that you"
	@echo "have a working copy of the JDK (v1.1) installed."
	@echo ""
	@echo "To build java support, please read:"
	@echo ""
	@echo "${WRKDIR}/${DISTNAME}/java/README"
	@echo ""
	@echo "and follow the directions therein."

.include <bsd.port.mk>
