# Created by: Alex Dupre <ale@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mysql
PKGNAMESUFFIX=	51-client
PORTREVISION=	3

COMMENT=	Multithreaded SQL database (client)

MASTERDIR=	${.CURDIR}/../mysql51-server

PKGINSTALL=	mustnotexist
PKGMESSAGE=	${.CURDIR}/pkg-message
PLIST=		${PKGDIR}/pkg-plist.client

CLIENT_ONLY=	yes

.include "${MASTERDIR}/Makefile"
