PORTNAME=	tinycdb
PORTVERSION=	0.81
CATEGORIES=	databases
MASTER_SITES=	http://www.corpit.ru/mjt/tinycdb/

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Analogous to cdb, but faster
WWW=		https://www.corpit.ru/mjt/tinycdb.html

LICENSE=	PD

USES=		gmake

ALL_TARGET=	static sharedlib
INSTALL_TARGET=	install install-sharedlib
MAKE_ARGS=	CC="${CC}" \
		CFLAGS="${CFLAGS}" \
		mandir=${PREFIX}/share/man \
		pkgconfdir=${PREFIX}/libdata/pkgconfig \
		prefix=${PREFIX}
USE_LDCONFIG=	yes

CONFLICTS_INSTALL=	libcdb # lib/libcdb.a

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/cdb ${STAGEDIR}${PREFIX}/lib/libcdb.so

.include <bsd.port.mk>
