# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/libgda4-mysql/Makefile,v 1.3 2010/10/18 12:47:12 kwm Exp $
#

PORTREVISION?=	2
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	-mysql

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides MySQL backend for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/mysql/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	mysql

.include "${MASTERDIR}/Makefile"
