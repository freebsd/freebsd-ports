# $FreeBSD$

PORTNAME=	mariadb
PKGNAMESUFFIX=	53-scripts

COMMENT=	Scripts for mariadb - drop-in replacement for MySQL

LICENSE=	GPLv2

UNIQUENAME=	${PORTNAME}${PKGNAMESUFFIX}
USES=		perl5

MASTERDIR=	${.CURDIR}/../mariadb-server
MARIADB_SCRIPTS_SLAVE=	yes

CONFLICTS=	mysql[0-9][0-9]-scripts-* \
		mytop-[0-9]*

PATCHDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist

MAN1=		msql2mysql.1 mysql_convert_table_format.1 mysql_find_rows.1 \
		mysql_fix_extensions.1 mysql_secure_installation.1 \
		mysql_setpermission.1 mysql_zap.1 mysqlaccess.1 \
		mysqldumpslow.1 mysqlhotcopy.1 mysqld_multi.1

EXTRA_PATCHES=	${MASTERDIR}/files/patch-Makefile.in ${MASTERDIR}/files/patch-man__Makefile.in
MDB_SCRIPTS_SUBDIRS=	scripts @man_dirs@

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e "s|%%SUBDIRS%%|${MDB_SCRIPTS_SUBDIRS}|" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|%%MANS%%|${MAN1}|" ${WRKSRC}/man/Makefile.in
	@${REINPLACE_CMD} -e "s|^\(install-man: install-man1\).*|\1|" ${WRKSRC}/man/Makefile.in

.include "${MASTERDIR}/Makefile"
