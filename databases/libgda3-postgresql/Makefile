# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgda3-postgresql/Makefile,v 1.2 2008/02/26 21:23:35 kwm Exp $

PORTREVISION?=	1
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	-postgresql

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides postgresql access for the libgda3 library

MASTERDIR=	${.CURDIR}/../libgda3
BUILD_WRKSRC=	${WRKSRC}/providers/postgres/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA3_SLAVE=	postgresql

NO_STAGE=	yes
.include "${MASTERDIR}/Makefile"
