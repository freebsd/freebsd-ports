# Created by: ijliao
# $FreeBSD$

PORTNAME=	tinycdb
PORTVERSION=	0.78
PORTREVISION=	2
CATEGORIES=	databases
MASTER_SITES=	http://www.corpit.ru/mjt/tinycdb/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Analogous to cdb, but faster

LICENSE=	PD

ALL_TARGET=	static sharedlib
INSTALL_TARGET=	install install-sharedlib
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" prefix="${PREFIX}"
USE_LDCONFIG=	yes
USES=		gmake

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cdb ${STAGEDIR}${PREFIX}/lib/libcdb.so.1

.include <bsd.port.mk>
