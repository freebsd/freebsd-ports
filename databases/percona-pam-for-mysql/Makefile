# Created by: Mark Felder <feld@FreeBSD.org>
# $FreeBSD$

PORTNAME=	percona
PORTREVISION=	1
PKGNAMESUFFIX=	-pam-for-mysql

COMMENT=	PAM plugin for MySQL

BROKEN_armv6=		fails to compile: cannot combine with previous 'type-name' declaration specifier
BROKEN_armv7=		fails to compile: cannot combine with previous 'type-name' declaration specifier
BROKEN_mips=		fails to configure: CMake Error: Generator: execution of make failed
BROKEN_mips64=		fails to configure: CMake Error: Generator: execution of make failed
NOT_FOR_ARCHS=		powerpc64
NOT_FOR_ARCHS_REASON=	unsupported platform

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
