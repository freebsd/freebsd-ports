# New ports collection makefile for:	MySQL-client
# Date created:				28 Jan 2006
# Whom:					Alex Dupre <ale@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	mysql
PORTREVISION=	1
PKGNAMESUFFIX=	-client

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../mysql51-server

PKGINSTALL=	mustnotexist
PLIST=		${PKGDIR}/pkg-plist.client

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"
