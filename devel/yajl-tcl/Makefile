PORTNAME=	yajl-tcl
PORTVERSION=	1.8.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl bindings for Yet Another JSON Library
WWW=		https://github.com/flightaware/yajl-tcl

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libyajl.so:devel/yajl
TEST_DEPENDS=	dtplite:devel/tcllib

USES=		autoreconf pkgconfig tcl:86+,tea

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

TEST_TARGET=	test

PLIST_FILES=	lib/yajltcl${PORTVERSION}/lib${TCL_PKG_LIB_PREFIX}yajltcl${PORTVERSION}.so \
		lib/yajltcl${PORTVERSION}/pkgIndex.tcl \
		lib/yajltcl${PORTVERSION}/yajl.tcl

.include <bsd.port.mk>
