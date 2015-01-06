# Created by: bsam
# $FreeBSD$

PORTNAME=	sqlite3
PORTVERSION=	3.5.9
PORTREVISION=	2
CATEGORIES=	databases linux
MASTER_SITES=	LOCAL/ehaupt/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	sqlite-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Library that implements an embeddable SQL database engine (Linux Fedora 10)

CONFLICTS=	linux-f8-sqlite3-[0-9]*

USE_LINUX=	f10
USE_LINUX_RPM=	yes

RPMVERSION=	4.fc10
BRANDELF_FILES=	usr/bin/sqlite3
USE_LDCONFIG=	yes

PLIST_FILES=	usr/bin/sqlite3 usr/lib/libsqlite3.so.0 \
		usr/lib/libsqlite3.so.0.8.6 usr/share/man/man1/sqlite3.1.gz
DOCSDIR=	${PREFIX}/usr/share/doc/sqlite-${PORTVERSION}
PORTDOCS=	README
DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
