# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgda3-mdb/Makefile,v 1.2 2008/02/26 21:23:34 kwm Exp $

PORTREVISION?=	2
CATEGORIES=	databases gnome
PKGNAMESUFFIX?=	-mdb

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides mdb backend for the libgda3 library

MASTERDIR=	${.CURDIR}/../libgda3
BUILD_WRKSRC=	${WRKSRC}/providers/mdb/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA3_SLAVE=	mdb

NO_STAGE=	yes

post-extract:
	@${REINPLACE_CMD} -e 's|MDB_SDATETIME|MDB_DATETIME|g' \
		${WRKSRC}/providers/mdb/util.c

.include "${MASTERDIR}/Makefile"
