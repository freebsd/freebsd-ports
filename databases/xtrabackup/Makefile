# New ports collection makefile for:	xtrabackup
# Date created:				29 Marc 2010
# Whom:					Alex Samorukov <samm@os2.kiev.ua>
#
# $FreeBSD$
#

PORTNAME=	xtrabackup
PORTVERSION=	2.0.1
CATEGORIES=	databases
MASTER_SITES=	${MASTER_SITE_MYSQL_GRP} \
		http://downloads.skysql.com/archives/mysql-5.5/:mysql55 \
		http://downloads.mysql.com/archives/mysql-5.5/:mysql55 \
		http://www.percona.com/downloads/%SUBDIR%/:xtrabackup,percsrc51,percsrc55 \
		http://samm.kiev.ua/percona/:percsrc51,percsrc55
DISTNAME=	percona-${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DISTFILES=	mysql-${MYSQL51_SRCVER}.tar.gz:mysql51 mysql-${MYSQL55_SRCVER}.tar.gz:mysql55 \
		mysql-${MYSQL55PERCONA_SRCVER}.tar.gz:mysql55 \
		percona-xtrabackup-${PORTVERSION}.tar.gz:xtrabackup \
		Percona-Server-5.1.59-13.0-patches.tar.gz:percsrc51 \
		Percona-Server-5.5.16-22.0-patches.tar.gz:percsrc55
EXTRACT_ONLY=	percona-xtrabackup-${PORTVERSION}.tar.gz

MAINTAINER=	aleksandr.kuzminsky@percona.com
COMMENT=	OpenSource version of InnoDB backup with support of Percona extensions

LICENSE=	GPLv2

# MySQL 5.5 using CMAKE, quilt is requiered by build.sh
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash quilt:${PORTSDIR}/devel/quilt \
		cmake:${PORTSDIR}/devel/cmake bison:${PORTSDIR}/devel/bison

# autotool is in use for 5.1 builds
MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_AUTOTOOLS=	automake autoheader autoconf libtool aclocal

# use MASTER_SITE_MYSQL for the MySQL 5.1
MASTER_SITE_MYSQL_GRP=	${MASTER_SITE_MYSQL:S@%SUBDIR%/@%SUBDIR%/:mysql51@g}
MASTER_SITE_SUBDIR=	MySQL-5.1/:mysql51 \
	XtraBackup/XtraBackup-${PORTVERSION}/source/:xtrabackup \
	Percona-Server-5.1/Percona-Server-5.1.59-13.0/source/:percsrc51 \
	Percona-Server-5.5/Percona-Server-5.5.16-22.0/source/:percsrc55

# port needs MySQL sources to build
MYSQL51_SRCVER=		5.1.59
MYSQL55_SRCVER=		5.5.17
MYSQL55PERCONA_SRCVER=	5.5.16

PLIST_FILES=	bin/xtrabackup bin/xtrabackup_51 bin/xtrabackup_55 bin/xbstream bin/innobackupex

pre-build:
	${CP} ${DISTDIR}/percona-xtrabackup-${PORTVERSION}.tar.gz \
	${DISTDIR}/mysql-${MYSQL51_SRCVER}.tar.gz ${DISTDIR}/mysql-${MYSQL55_SRCVER}.tar.gz \
	${DISTDIR}/mysql-${MYSQL55PERCONA_SRCVER}.tar.gz \
	${DISTDIR}/Percona-Server-5.1.59-13.0-patches.tar.gz \
	${DISTDIR}/Percona-Server-5.5.16-22.0-patches.tar.gz ${WRKSRC}

do-build:
	cd ${WRKSRC} && ./utils/build.sh 5.1
	${CP} ${WRKSRC}/src/xtrabackup_51 ${WRKSRC}/src/xbstream ${WRKSRC}
	cd ${WRKSRC} && ./utils/build.sh xtradb
	${CP} ${WRKSRC}/src/xtrabackup ${WRKSRC}
	cd ${WRKSRC} && ./utils/build.sh xtradb55
	${CP} ${WRKSRC}/src/xtrabackup_55 ${WRKSRC}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/xtrabackup ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/xtrabackup_55 ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/xtrabackup_51 ${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/xbstream ${PREFIX}/bin
	@${INSTALL_SCRIPT} ${WRKSRC}/innobackupex ${PREFIX}/bin

# autoconf is running by build.sh
do-configure:
run-autotools-aclocal:
run-autotools-automake:
run-autotools-autoconf:
run-autotools-autoheader:
run-autotools-libtoolize:
patch-autotools-libtool:
	@${TRUE}

.include <bsd.port.mk>
