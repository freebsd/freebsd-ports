# New ports collection makefile for:	Gdtclft
# Date Created:				10 February 2000
# Whom:					Mikhail Teterin <mi@aldan.algebra.com>
#
# $FreeBSD$
#

PORTNAME=	Gdtclft
PORTVERSION=	2.2.5
PORTREVISION=	1
CATEGORIES=	graphics tcl${TCL_DVER}
MASTER_SITES=	ftp://ftp.graphviz.org/pub/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com

LIB_DEPENDS=	tcl${TCL_DVER}.1:${PORTSDIR}/lang/tcl${TCL_DVER} \
		gd.2:${PORTSDIR}/graphics/gd

TCL_VER=	8.3
TCL_DVER=	${TCL_VER:S/.//}

USE_FREETYPE=	yes
MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
			INSTALL_DATA="${INSTALL_DATA}"
ALL_TARGET=	all

MANN=		gdtclft.n
MANCOMPRESSED=	maybe

.include <bsd.port.mk>

PLIST_SUB!=	${ENV} TCL_VER=${TCL_VER} ${MAKE} -f ${MAKEFILE} env
