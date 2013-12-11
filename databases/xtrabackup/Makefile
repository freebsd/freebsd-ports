# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	xtrabackup
PORTVERSION=	2.1.4
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/downloads/%SUBDIR%/
DISTNAME=	percona-${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DISTFILES=	percona-xtrabackup-${PORTVERSION}.tar.gz
EXTRACT_ONLY=	percona-xtrabackup-${PORTVERSION}.tar.gz

MAINTAINER=	aleksandr.kuzminsky@percona.com
COMMENT=	OpenSource version of InnoDB backup with support of Percona extensions

LICENSE=	GPLv2

# quilt is requiered by build.sh
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		quilt:${PORTSDIR}/devel/quilt \
		bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		qpress:${PORTSDIR}/archivers/qpress

# autotool is in use for 5.1 builds
USE_AUTOTOOLS=	automake autoheader autoconf libtool aclocal
# MySQL 5.5 using CMAKE
USES=		cmake iconv gettext gmake perl5

MASTER_SITE_SUBDIR=	XtraBackup/XtraBackup-${PORTVERSION}/source/

PLIST_FILES=	bin/xtrabackup bin/xtrabackup_55 bin/xtrabackup_56 bin/xbstream \
	bin/innobackupex bin/xbcrypt

NO_STAGE=	yes
pre-build:
	${CP} ${DISTDIR}/percona-xtrabackup-${PORTVERSION}.tar.gz ${WRKSRC}

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
