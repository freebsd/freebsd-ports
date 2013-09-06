# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/trunk/databases/libgda5-mdb/Makefile 18610 2013-06-30 16:33:05Z marcus $

PORTREVISION=	0
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	5-mdb

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides mdb backend for the libgda5 library

MASTERDIR=	${.CURDIR}/../libgda5
BUILD_WRKSRC=	${WRKSRC}/providers/mdb/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA5_SLAVE=	mdb

.include "${MASTERDIR}/Makefile"
