PORTNAME=	yajl-tcl
PORTVERSION=	1.7.0
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl bindings for Yet Another JSON Library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libyajl.so:devel/yajl
TEST_DEPENDS=	dtplite:devel/tcllib

USES=		autoreconf pkgconfig tcl:tea

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

TEST_TARGET=	test

PLIST_FILES=	lib/yajltcl${PORTVERSION}/libyajltcl.so.1 \
		lib/yajltcl${PORTVERSION}/pkgIndex.tcl \
		lib/yajltcl${PORTVERSION}/yajl.tcl

.include <bsd.port.mk>
