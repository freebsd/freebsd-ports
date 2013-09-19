# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	tcl-mmap
PORTVERSION=	1.1
CATEGORIES=	devel
MASTER_SITES=	SF

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	New TCL channel type using mmap-ed files

LICENSE=	GPLv3

USES+=		tcl
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-tcl=${TCL_LIBDIR} \
		--prefix=${PREFIX} \
		--exec-prefix=${PREFIX}

PLIST_DIRS=	lib/mmap${PORTVERSION}
PLIST_FILES=	lib/mmap${PORTVERSION}/pkgIndex.tcl \
		lib/mmap${PORTVERSION}/libmmap${PORTVERSION}.so

MANN=	tcl-mmap.n

regression-test: build
	cd ${WRKSRC}/tests; \
	for t in *.tcl; \
	do \
	    echo "load ../libmmap${PORTVERSION}.so; source $$t" | ${TCLSH}; \
	done;

.include <bsd.port.mk>
