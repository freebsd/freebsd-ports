# New ports collection makefile for:	Gdtclft
# Date Created:				10 February 2000
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	Gdtclft
PORTVERSION=	2.2.3
CATEGORIES=	graphics tcl82
MASTER_SITES=	ftp://ftp.graphviz.org/pub/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82 \
		gd.1:${PORTSDIR}/graphics/gd \
		ttf.4:${PORTSDIR}/print/freetype

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV=	TCL_VER=8.2 MKDIR="${MKDIR}" INSTALL_DATA="${INSTALL_DATA}"
ALL_TARGET=	all

MANN=		gdtclft.n
MANCOMPRESSED=	maybe

.include <bsd.port.mk>

PLIST_SUB!=	${MAKE} -f ${MAKEFILE} env
