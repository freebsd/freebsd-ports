# Created by: gahr
# $FreeBSD$

PORTNAME=	tcl-lmdb
PORTVERSION=	0.4.1
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tcl interface to the Lightning Memory-Mapped Database

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	liblmdb.so:databases/lmdb

USES=		gmake tcl:tea

USE_GITHUB=	yes
GH_ACCOUNT=	ray2501

CONFIGURE_ARGS=	--with-system-lmdb
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

TEST_TARGET=	test

PLIST_FILES=	lib/${TCL_PKG}/lib${TCL_PKG}.so \
		lib/${TCL_PKG}/pkgIndex.tcl \
		man/mann/lmdb.n.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${TCL_PKG}/lib${TCL_PKG}.so

.include <bsd.port.mk>
