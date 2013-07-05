# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	xtrabackup
PORTVERSION=	2.1.3
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://downloads.skysql.com/archives/%SUBDIR%/:mysql51,mysql55,mysql56 \
		http://downloads.mysql.com/archives/%SUBDIR%/:mysql51,mysql55,mysql56 \
		http://www.percona.com/downloads/%SUBDIR%/:xtrabackup,percsrc51,percsrc55 \
		http://samm.kiev.ua/percona/:percsrc51,percsrc55
DISTNAME=	percona-${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DISTFILES=	mysql-${MYSQL51_SRCVER}.tar.gz:mysql51 mysql-${MYSQL55_SRCVER}.tar.gz:mysql55 \
		mysql-${MYSQL56_SRCVER}.tar.gz:mysql56 \
		percona-xtrabackup-${PORTVERSION}.tar.gz:xtrabackup \
		Percona-Server-5.1.59-13.0-patches.tar.gz:percsrc51 \
		Percona-Server-5.5.16-22.0-patches.tar.gz:percsrc55
EXTRACT_ONLY=	percona-xtrabackup-${PORTVERSION}.tar.gz

MAINTAINER=	aleksandr.kuzminsky@percona.com
COMMENT=	OpenSource version of InnoDB backup with support of Percona extensions

LICENSE=	GPLv2

# quilt is requiered by build.sh
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		quilt:${PORTSDIR}/devel/quilt \
		bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	gcrypt:${PORTSDIR}/security/libgcrypt \
		gpg-error:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql

# autotool is in use for 5.1 builds
MAKE_JOBS_SAFE=	yes
USE_GMAKE=	yes
USE_PERL5=	yes
USE_AUTOTOOLS=	automake autoheader autoconf libtool aclocal
# MySQL 5.5 using CMAKE
USES=		cmake iconv gettext

MASTER_SITE_SUBDIR=	mysql-5.1/:mysql51 mysql-5.5/:mysql55 mysql-5.6/:mysql56 \
	XtraBackup/XtraBackup-${PORTVERSION}/source/:xtrabackup \
	Percona-Server-5.1/Percona-Server-5.1.59-13.0/source/:percsrc51 \
	Percona-Server-5.5/Percona-Server-5.5.16-22.0/source/:percsrc55

# port needs MySQL sources to build
MYSQL51_SRCVER=		5.1.59
MYSQL55_SRCVER=		5.5.16
MYSQL56_SRCVER=		5.6.10

PLIST_FILES=	bin/xtrabackup bin/xtrabackup_55 bin/xtrabackup_56 bin/xbstream \
	bin/innobackupex bin/xbcrypt

pre-build:
	${CP} ${DISTDIR}/percona-xtrabackup-${PORTVERSION}.tar.gz \
	${DISTDIR}/mysql-${MYSQL51_SRCVER}.tar.gz ${DISTDIR}/mysql-${MYSQL55_SRCVER}.tar.gz \
	${DISTDIR}/mysql-${MYSQL56_SRCVER}.tar.gz \
	${DISTDIR}/Percona-Server-5.1.59-13.0-patches.tar.gz \
	${DISTDIR}/Percona-Server-5.5.16-22.0-patches.tar.gz ${WRKSRC}

do-build:
	cd ${WRKSRC} && ./utils/build.sh xtradb55
	${CP} ${WRKSRC}/src/xtrabackup_55 ${WRKSRC}
	cd ${WRKSRC} && ./utils/build.sh innodb56
	${CP} ${WRKSRC}/src/xtrabackup_56 ${WRKSRC}
	cd ${WRKSRC} && ./utils/build.sh xtradb
	${CP} ${WRKSRC}/src/xtrabackup ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtrabackup ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xtrabackup_55 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/xtrabackup_56 ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/xbstream ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/src/xbcrypt ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/innobackupex ${PREFIX}/bin

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
