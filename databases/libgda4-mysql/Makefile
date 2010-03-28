# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/libgda4-mysql/Makefile,v 1.1 2008/08/18 23:53:35 kwm Exp $
#

PORTREVISION?=	1
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	-mysql

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides mysql backend for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/mysql/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	mysql

.include "${MASTERDIR}/Makefile"
