# New ports collection makefile for:	MySQL-client
# Date created:				Fri Apr 11 10:06:26 CET 2003
# Whom:					Alex Dupre <sysadmin@alexdupre.com>
#
# $FreeBSD$
#

PORTNAME=	mysql
PORTREVISION=	0
PKGNAMESUFFIX=	-client

MASTERDIR=	${.CURDIR}/../mysql41-server
COMMENT=	Multithreaded SQL database (client)
PKGINSTALL=	mustnotexist
PLIST=		${PKGDIR}/pkg-plist.client

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"
