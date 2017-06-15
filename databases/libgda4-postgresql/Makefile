# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgda4-postgresql/Makefile,v 1.7 2012/03/13 01:34:31 mezz Exp $

PORTREVISION=	2
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	4-postgresql

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides PostgreSQL access for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/postgres/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	postgresql

.include "${MASTERDIR}/Makefile"
