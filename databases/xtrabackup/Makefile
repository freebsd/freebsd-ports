# New ports collection makefile for:	xtrabackup
# Date created:				29 Marc 2010
# Whom:					Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	xtrabackup
PORTVERSION=	1.1
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/downloads/XtraBackup/XtraBackup-1.1/source/	\
		http://launchpadlibrarian.net/41612347/

MAINTAINER=	aleksandr.kuzminsky@percona.com
COMMENT=	OpenSource version of InnoDB backup with support of Percona extensions

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS=	--localstatedir=/var/db/mysql \
		--without-debug \
		--without-readline \
		--without-libedit \
		--without-server \
		--with-libwrap \
		--with-low-memory \
		--enable-thread-safe-client \
		--with-named-thread-libs="${PTHREAD_LIBS}"

PLIST_FILES=	bin/xtrabackup bin/tar4ibd bin/innobackupex-1.5.1

post-build:
	cd ${WRKSRC}/storage/innobase/xtrabackup && ${GMAKE}
	cd ${WRKSRC}/libtar-1.2.11 && ./configure && ${GMAKE}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/storage/innobase/xtrabackup/xtrabackup ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/storage/innobase/xtrabackup/innobackupex-1.5.1 ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/libtar-1.2.11/libtar/tar4ibd ${PREFIX}/bin

.include <bsd.port.mk>
