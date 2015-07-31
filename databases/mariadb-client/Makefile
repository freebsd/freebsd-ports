# $FreeBSD$

PORTNAME=	mariadb
PORTREVISION=	7
PKGNAMESUFFIX=	53-client

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}

COMMENT=	Database client - drop-in replacement for MySQL

MASTERDIR=	${.CURDIR}/../mariadb-server
MARIADB_CLIENT_SLAVE=	yes

USES+=		readline
CONFIGURE_ARGS=	--without-server --with-libevent=no

OPTIONS_DEFINE=		THREADSAFE
OPTIONS_DEFAULT=	THREADSAFE
THREADSAFE_DESC=	Build thread-safe client

CONFLICTS=	mariadb5[4-9]-client-* \
		mariadb1[0-9][0-9]-client-* \
		mysql*-client-* \
		percona*-client-* 

PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist
PKGMESSAGE=	${.CURDIR}/pkg-message

MANS=	mysql_config.1 mysql_upgrade.1 mysql.1 mysqladmin.1 \
	mysqlbinlog.1 mysqlbug.1 mysqlcheck.1 \
	mysqldump.1 mysqlimport.1 mysqlshow.1 mysqlslap.1 mysqltest.1

EXTRA_PATCHES=	${MASTERDIR}/files/patch-*
MDB_CLIENT_SUBDIRS=	include sql-common cmd-line-utils scripts strings regex mysys dbug extra libmysql libmysql_r client @man_dirs@

post-patch:
	@${REINPLACE_CMD} -e "s|%%SUBDIRS%%|${MDB_CLIENT_SUBDIRS}|" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|install-exec-am: install-pkglibLIBRARIES|install-exec-am:|g" ${WRKSRC}/strings/Makefile.in ${WRKSRC}/mysys/Makefile.in ${WRKSRC}/dbug/Makefile.in
	@${REINPLACE_CMD} -e "s|install-exec-am: install-binPROGRAMS|install-exec-am:|g" ${WRKSRC}/extra/Makefile.in
	@${REINPLACE_CMD} -e "s|%%MANS%%|${MANS}|" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(install-man: install-man1\).*|\1|" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|-fno-implicit-templates||g" ${WRKSRC}/configure

post-install:
	${INSTALL_DATA} ${WRKSRC}/support-files/mysql.m4 ${STAGEDIR}${PREFIX}/share/aclocal/

post-stage:
	@${RM} -rf ${STAGEDIR}/${PREFIX}/include/mysql/private

.include "${MASTERDIR}/Makefile"
