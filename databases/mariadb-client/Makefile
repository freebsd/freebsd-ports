# New ports collection makefile for:	mariadb-client
# Date created:				30 May 2011
# Whom:					Doug Barton <dougb@FreeBSD.org>
#
# $FreeBSD$

PORTNAME=	mariadb
PKGNAMESUFFIX=	-client

COMMENT=	Database client - drop-in replacement for MySQL

MASTERDIR=	${.CURDIR}/../mariadb-server
MARIADB_CLIENT_SLAVE=	yes

CONFIGURE_ARGS=	--without-server

IGNORE=		Post repo-copy, not ready for use yet

CONFLICTS=	mysql-client-[0-9]*

PKGMESSAGE=	/nonexistent	# To avoid equivalent in master port
PLIST=		${.CURDIR}/pkg-plist

.include "${MASTERDIR}/Makefile"
