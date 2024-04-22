PORTNAME=	tcl-lmdb
DISTVERSION=	0.4.3
PORTREVISION=	1
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tcl interface to the Lightning Memory-Mapped Database
WWW=		https://github.com/ray2501/tcl-lmdb

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	liblmdb.so:databases/lmdb

USES=		gmake localbase:ldflags tcl:tea

USE_GITHUB=	yes
GH_ACCOUNT=	ray2501

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-system-lmdb

TEST_TARGET=	test

PLIST_FILES=	lib/${TCL_PKG}/lib${TCL_PKG}.so \
		lib/${TCL_PKG}/pkgIndex.tcl \
		share/man/mann/lmdb.n.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${TCL_PKG}/lib${TCL_PKG}.so

.include <bsd.port.mk>
