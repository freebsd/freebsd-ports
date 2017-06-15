# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgda4-mysql/Makefile,v 1.7 2011/10/15 15:18:36 kwm Exp $

PORTREVISION=	2
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	4-mysql

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides MySQL backend for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/mysql/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	mysql

.include "${MASTERDIR}/Makefile"
