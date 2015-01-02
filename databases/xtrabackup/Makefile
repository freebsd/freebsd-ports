# Created by: Alex Samorukov <samm@os2.kiev.ua>
# $FreeBSD$

PORTNAME=	xtrabackup
PORTVERSION=	2.2.6
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.percona.com/redir/downloads/XtraBackup/LATEST/source/tarball/
DISTNAME=	percona-${PORTNAME}-${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}
DISTFILES=	percona-xtrabackup-${PORTVERSION}.tar.gz
EXTRACT_ONLY=	percona-xtrabackup-${PORTVERSION}.tar.gz

MAINTAINER=	aleksandr.kuzminsky@percona.com
COMMENT=	OpenSource version of InnoDB backup with support of Percona extensions

LICENSE=	GPLv2

# quilt is required by build.sh
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash \
		cmake:${PORTSDIR}/devel/cmake \
		bison:${PORTSDIR}/devel/bison
LIB_DEPENDS=	libgcrypt.so:${PORTSDIR}/security/libgcrypt \
		libgpg-error.so:${PORTSDIR}/security/libgpg-error
RUN_DEPENDS=	p5-DBD-mysql>=0:${PORTSDIR}/databases/p5-DBD-mysql \
		qpress:${PORTSDIR}/archivers/qpress

# autotool is in use for 5.1 builds
USES=		autoreconf:build gettext cmake iconv libtool perl5

PLIST_FILES=	bin/xtrabackup bin/xbstream bin/innobackupex bin/xbcrypt

pre-build:
	${CP} ${DISTDIR}/percona-xtrabackup-${PORTVERSION}.tar.gz ${WRKSRC}

.include <bsd.port.mk>
