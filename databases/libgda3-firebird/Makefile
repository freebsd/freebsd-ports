# New ports collection makefile for:	libgda2
# Date created:				02 June 2002
# Whom:					Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/databases/libgda3-firebird/Makefile,v 1.2 2008/02/26 21:23:34 kwm Exp $
#

PORTREVISION?=	1
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	-firebird

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides firebird backend for the libgda3 library

MASTERDIR=	${.CURDIR}/../libgda3
BUILD_WRKSRC=	${WRKSRC}/providers/firebird/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA3_SLAVE=	firebird

.include "${MASTERDIR}/Makefile"
