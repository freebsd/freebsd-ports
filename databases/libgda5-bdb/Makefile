# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/libgda5-bdb/Makefile 18393 2013-04-26 21:23:07Z kwm $

PORTREVISION=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	5-bdb

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides Berkeley DB backend for the libgda5 library

MASTERDIR=	${.CURDIR}/../libgda5
BUILD_WRKSRC=	${WRKSRC}/providers/bdb/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA5_SLAVE=	bdb

.include "${MASTERDIR}/Makefile"
