# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>

PORTREVISION=	1
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
