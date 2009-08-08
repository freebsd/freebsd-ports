# New ports collection makefile for:	databases/linux-f10-sqlite3
# Date created:				2009-05-04
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	sqlite3
PORTVERSION=	3.5.9
PORTREVISION=	1
CATEGORIES=	databases linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	sqlite-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	The library that implements an embeddable SQL database engine (Linux Fedora 10)

CONFLICTS=	linux-f8-sqlite3-[0-9]*

USE_LINUX_RPM=	yes
LINUX_DIST_VER=	10
RPMVERSION=	4.fc10
BRANDELF_FILES=	usr/bin/sqlite3
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/sqlite3 usr/lib/libsqlite3.so.0 \
		usr/lib/libsqlite3.so.0.8.6
DOCSDIR=	${PREFIX}/usr/share/doc/sqlite-${PORTVERSION}
PORTDOCS=	README
MANPREFIX=	${PREFIX}/usr/share
MAN1=		sqlite3.1
MANCOMPRESSED=	yes
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
