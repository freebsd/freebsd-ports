# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	percona
PORTREVISION=	1
PKGNAMESUFFIX=	-pam-for-mysql

COMMENT=	PAM plugin for MySQL

MASTERDIR=	${.CURDIR}/../percona56-server

PKGMESSAGE=	${.CURDIR}/pkg-message
PATCHDIR=	${MASTERDIR}/files
FILESDIR=	${.CURDIR}/files
PLIST=		${.CURDIR}/pkg-plist
DESCR=		${.CURDIR}/pkg-descr

CMAKE_ARGS+=	-DWITH_PAM=1

PLUGIN_ONLY=	yes

do-install:
	(cd ${WRKSRC}/plugin/percona-pam-for-mysql && ${MAKE} ${MAKE_ARGS} install)
	${INSTALL_DATA} ${FILESDIR}/pam.conf ${STAGEDIR}${PREFIX}/etc/pam.d/mysqld.sample

.include "${MASTERDIR}/Makefile"

RUN_DEPENDS= # This plugin has no run dependencies. It should work with any desired mysql client/server.
