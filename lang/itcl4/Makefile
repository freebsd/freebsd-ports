# Created by: gahr
# $FreeBSD$

PORTNAME=	itcl4
PORTVERSION=	4.0.4
CATEGORIES=	lang
MASTER_SITES=	TCLTK/itcl \
		SF/incrtcl/%5Bincr%20Tcl_Tk%5D-4-source/itcl%20${PORTVERSION}/
DISTNAME=	itcl${PORTVERSION}

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	Object-oriented extension to Tcl [incr Tcl]

USES+=		tcl:86,tea
CONFIGURE_ARGS+=--includedir=${PREFIX}/include/itcl${PORTVERSION:R}
PLIST_SUB+=	PKGVER=${PORTVERSION}
TEST_TARGET=	test

.include <bsd.port.mk>
