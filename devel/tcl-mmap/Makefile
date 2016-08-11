# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	tcl-mmap
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	New TCL channel type using mmap-ed files

LICENSE=	GPLv3

USES+=		tcl:tea

PLIST_FILES=	lib/${TCL_PKG}/pkgIndex.tcl \
		lib/${TCL_PKG}/lib${TCL_PKG}.so \
		man/mann/${PORTNAME}.n.gz
TEST_TARGET=	do-test

do-test:
	cd ${WRKSRC}/tests; \
	for t in *.tcl; \
	do \
	    echo "load ../libmmap${PORTVERSION}.so; source $$t" | ${TCLSH}; \
	done;

.include <bsd.port.mk>
