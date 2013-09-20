# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgda3-mysql/Makefile,v 1.2 2008/02/26 21:23:35 kwm Exp $

PORTREVISION?=	2
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	-mysql

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides MySQL backend for the libgda3 library

MASTERDIR=	${.CURDIR}/../libgda3
BUILD_WRKSRC=	${WRKSRC}/providers/mysql/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA3_SLAVE=	mysql

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
