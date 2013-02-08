# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	tcl-mmap
PORTVERSION=	1.1
CATEGORIES=	devel tcl
MASTER_SITES=	SF

MAINTAINER=	tcltk@FreeBSD.org
COMMENT=	New TCL channel type using mmap-ed files

MAKEFILE=	${FILESDIR}/Makefile.bsd

USE_TCL=	84+

MAKE_ENV+=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
		PORTVERSION="${PORTVERSION}" \
		FILESDIR="${FILESDIR}" \
		TCLSH="${TCLSH}" \
		INSTALL_DATA="${INSTALL_DATA}"
PLIST_DIRS=	lib/tcl${TCL_VER}/mmap
PLIST_FILES=	${PLIST_DIRS}/pkgIndex.tcl ${PLIST_DIRS}/libmmap${PORTVERSION}.so

MANN=	tcl-mmap.n
MANCOMPRESSED=	maybe

.include <bsd.port.mk>
