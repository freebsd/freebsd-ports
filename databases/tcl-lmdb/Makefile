# Created by: gahr
# $FreeBSD$

PORTNAME=	tcl-lmdb
PORTVERSION=	0.3.3
CATEGORIES=	databases

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Tcl interface to the Lightning Memory-Mapped Database

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	liblmdb.so:databases/lmdb

USE_GITHUB=	yes
GH_ACCOUNT=	ray2501

USES=		gmake tcl
GNU_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} --with-system-lmdb
CONFIGURE_ENV+=	CPPFLAGS="${CFLAGS}"

TEST_TARGET=	test

TCLPKG=		lmdb${PORTVERSION}
PLIST_FILES=	lib/${TCLPKG}/lib${TCLPKG}.so \
		lib/${TCLPKG}/pkgIndex.tcl \
		man/mann/lmdb.n.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${TCLPKG}/lib${TCLPKG}.so

.include <bsd.port.mk>

