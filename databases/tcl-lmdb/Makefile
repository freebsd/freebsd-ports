PORTNAME=	tcl-lmdb
DISTVERSION=	0.5.0
PORTREVISION=	2
CATEGORIES=	databases
CPPFLAGS+=	-I${LOCALBASE}/lmdb0/include
LDFLAGS+=	-L${LOCALBASE}/lmdb0/lib
CONFIGURE_ENV+=	PKG_CONFIG_PATH=${LOCALBASE}/lmdb0/libdata/pkgconfig

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tcl interface to the Lightning Memory-Mapped Database
WWW=		https://github.com/ray2501/tcl-lmdb

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	liblmdb0.so:databases/lmdb0

USES=		gmake localbase:ldflags tcl:tea

USE_GITHUB=	yes
GH_ACCOUNT=	ray2501

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	--with-system-lmdb

TEST_TARGET=	test

PLIST_FILES=	lib/${TCL_PKG}/lib${TCL_PKG_LIB_PREFIX}${TCL_PKG}.so \
		lib/${TCL_PKG}/pkgIndex.tcl \
		share/man/mann/lmdb.n.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${TCL_PKG}/lib${TCL_PKG_LIB_PREFIX}${TCL_PKG}.so

.include <bsd.port.mk>
