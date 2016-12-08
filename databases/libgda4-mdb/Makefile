# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/databases/libgda4-mdb/Makefile,v 1.5 2012/03/13 01:34:31 mezz Exp $

PORTREVISION=	3
CATEGORIES=	databases gnome
PKGNAMESUFFIX=	4-mdb

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Provides mdb backend for the libgda4 library

MASTERDIR=	${.CURDIR}/../libgda4
BUILD_WRKSRC=	${WRKSRC}/providers/mdb/
INSTALL_WRKSRC=	${BUILD_WRKSRC}
PLIST=		${.CURDIR}/pkg-plist

LIBGDA4_SLAVE=	mdb

post-extract:
	@${REINPLACE_CMD} -e 's|MDB_SDATETIME|MDB_DATETIME|g' \
		${WRKSRC}/providers/mdb/gda-mdb-provider.c \
		${WRKSRC}/providers/mdb/libmdb-src/include/mdbtools.h \
		${WRKSRC}/providers/mdb/libmdb-src/data.c

.include "${MASTERDIR}/Makefile"
