# Created by: ijliao
# $FreeBSD$

PORTNAME=	tinycdb
PORTVERSION=	0.78
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.corpit.ru/mjt/tinycdb/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analogous to cdb, but faster

USES=		gmake
USE_LDCONFIG=	yes
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}"
ALL_TARGET=	static sharedlib
INSTALL_TARGET=	install install-sharedlib

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/cdb include/cdb.h lib/libcdb.a lib/libcdb.so lib/libcdb.so.1 \
		man/man1/cdb.1.gz man/man3/cdb.3.gz man/man5/cdb.5.gz

.include <bsd.port.mk>
