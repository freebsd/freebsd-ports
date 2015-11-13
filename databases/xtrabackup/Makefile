# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	xtrabackup
PORTVERSION=	2.2.12
CATEGORIES=	databases
MASTER_SITES=	https://www.percona.com/downloads/XtraBackup/Percona-XtraBackup-${PORTVERSION}/source/tarball/
DISTNAME=	percona-${PORTNAME}-${PORTVERSION}

MAINTAINER=	aleksandr.kuzminsky@percona.com
COMMENT=	OpenSource version of InnoDB backup with support of Percona extensions

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

# quilt is required by build.sh
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		cmake:${PORTSDIR}/devel/cmake \
		bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		qpress:${PORTSDIR}/archivers/qpress

# autotool is in use for 5.1 builds
USES=		alias autoreconf:build cpe gettext cmake libtool perl5
CPE_VENDOR=	percona

PLIST_FILES=	bin/xtrabackup bin/xbstream bin/innobackupex bin/xbcrypt

.include <bsd.port.mk>
