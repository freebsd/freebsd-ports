# New ports collection makefile for:	mariadb-client
# Date created:				30 May 2011
# Whom:					Doug Barton <dougb@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mariadb
PKGNAMESUFFIX=	-client

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

COMMENT=	Database client - drop-in replacement for MySQL

MASTERDIR=	${.CURDIR}/../mariadb-server
MARIADB_CLIENT_SLAVE=	yes

CONFIGURE_ARGS=	--without-server --with-libevent=no

OPTIONS=	THREADSAFE "Build thread-safe client" On

CONFLICTS=	mysql-client-[0-9]*

PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

MAN1=	mysql_config.1 mysql_upgrade.1 mysql.1 mysqladmin.1 \
	mysqlbinlog.1 mysqlbug.1 mysqlcheck.1 \
	mysqldump.1 mysqlimport.1 mysqlshow.1 mysqlslap.1 mysqltest.1

EXTRA_PATCHES=	${MASTERDIR}/files/patch-*
MDB_CLIENT_SUBDIRS=	include sql-common cmd-line-utils scripts strings regex mysys dbug extra libmysql libmysql_r client @man_dirs@

post-patch:
	@${REINPLACE_CMD} -e "s|%%SUBDIRS%%|${MDB_CLIENT_SUBDIRS}|" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|install-exec-am: install-pkglibLIBRARIES|install-exec-am:|g" ${WRKSRC}/strings/Makefile.in ${WRKSRC}/mysys/Makefile.in ${WRKSRC}/dbug/Makefile.in
	@${REINPLACE_CMD} -e "s|install-exec-am: install-binPROGRAMS|install-exec-am:|g" ${WRKSRC}/extra/Makefile.in
	@${REINPLACE_CMD} -e "s|%%MANS%%|${MAN1}|" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(install-man: install-man1\).*|\1|" ${WRKSRC}/man/Makefile.in

post-install:
	${INSTALL_DATA} ${WRKSRC}/support-files/mysql.m4 ${PREFIX}/share/aclocal/

.include "${MASTERDIR}/Makefile"
