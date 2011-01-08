# New ports collection makefile for:   mariadb
# Date created:        14 November 2010
# Whom:                siasia
#
# $FreeBSD$
#

PORTNAME=	mariadb
PORTVERSION=	5.2.4
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/downloads/MariaDB/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://ftp.osuosl.org/pub/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirrors.supportex.net/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://technocation.org/mirror/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirror.aarnet.edu.au/pub/MariaDB/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://ftp-stud.hs-esslingen.de/pub/Mirrors/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://gd.tuwien.ac.at/db/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/ \
		http://mirrors.fe.up.pt/pub/mariadb/${PORTNAME}-${PORTVERSION}/kvm-tarbake-jaunty-x86/

MAINTAINER=	siasiamail@gmail.com
COMMENT=	A database server that offers drop-in replacement functionality for MySQL

LICENSE=	GPLv2

CONFLICTS=	mysql-server-[0-9]* mysql-client-[0-9]*

CONFIGURE_ARGS=	--with-embedded-server
DATADIR=	${PREFIX}/share/mysql
GNU_CONFIGURE=	yes
USE_LDCONFIG=	${PREFIX}/lib/mysql
USE_RC_SUBR=	mysql-server

USERS=		mysql
GROUPS=		mysql

INFO=		mysql
MAN1=		comp_err.1 \
		innochecksum.1 \
		msql2mysql.1 \
		my_print_defaults.1 \
		myisam_ftdump.1 \
		myisamchk.1 \
		myisamlog.1 \
		myisampack.1 \
		mysql-stress-test.pl.1 \
		mysql-test-run.pl.1 \
		mysql.1 \
		mysql.server.1 \
		mysql_client_test.1 \
		mysql_client_test_embedded.1 \
		mysql_config.1 \
		mysql_convert_table_format.1 \
		mysql_find_rows.1 \
		mysql_fix_extensions.1 \
		mysql_fix_privilege_tables.1 \
		mysql_install_db.1 \
		mysql_secure_installation.1 \
		mysql_setpermission.1 \
		mysql_tzinfo_to_sql.1 \
		mysql_upgrade.1 \
		mysql_waitpid.1 \
		mysql_zap.1 \
		mysqlaccess.1 \
		mysqladmin.1 \
		mysqlbinlog.1 \
		mysqlbug.1 \
		mysqlcheck.1 \
		mysqld_multi.1 \
		mysqld_safe.1 \
		mysqldump.1 \
		mysqldumpslow.1 \
		mysqlhotcopy.1 \
		mysqlimport.1 \
		mysqlman.1 \
		mysqlshow.1 \
		mysqlslap.1 \
		mysqltest.1 \
		mysqltest_embedded.1 \
		perror.1 \
		replace.1 \
		resolve_stack_dump.1 \
		resolveip.1
MAN8=		mysqld.8 \
		mysqlmanager.8

post-patch:
	@${REINPLACE_CMD} -e '/^install:/ s|^\(install:\).*$$|\1|' \
		${WRKSRC}/mysql-test/Makefile.in ${WRKSRC}/sql-bench/Makefile.in

.include <bsd.port.mk>
