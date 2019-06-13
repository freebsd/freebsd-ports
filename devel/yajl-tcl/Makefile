# Created by: gahr
# $FreeBSD$

PORTNAME=	yajl-tcl
PORTVERSION=	1.6.2
DISTVERSIONPREFIX=	v
CATEGORIES=	devel

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Tcl bindings for Yet Another JSON Library

LICENSE=	BSD3CLAUSE

LIB_DEPENDS=	libyajl.so:devel/yajl

USE_GITHUB=	yes
GH_ACCOUNT=	flightaware

USES+=		autoreconf pkgconfig tcl:tea

TEST_TARGET=	test
TEST_DEPENDS=	dtplite:devel/tcllib

PLIST_FILES=	lib/yajltcl${PORTVERSION}/libyajltcl.so.1 \
		lib/yajltcl${PORTVERSION}/pkgIndex.tcl \
		lib/yajltcl${PORTVERSION}/yajl.tcl

.include <bsd.port.mk>
