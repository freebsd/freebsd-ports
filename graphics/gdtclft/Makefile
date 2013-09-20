# Created by: Mikhail Teterin <mi@aldan.algebra.com>
# $FreeBSD$

PORTNAME=	Gdtclft
PORTVERSION=	2.2.5
PORTREVISION=	11
CATEGORIES=	graphics tcl
MASTER_SITES=	http://www.graphviz.org/pub/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	mi@aldan.algebra.com
COMMENT=	A TCL interface to the Thomas Boutell's Gd library

LIB_DEPENDS=	tcl${TCL_DVER}.1:${PORTSDIR}/lang/tcl${TCL_DVER} \
		gd:${PORTSDIR}/graphics/gd

TCL_VER?=	8.4
TCL_DVER=	${TCL_VER:S/.//}

MAKEFILE=	${FILESDIR}/Makefile.bsd
MAKE_ENV=	TCL_VER=${TCL_VER} MKDIR="${MKDIR}" \
			INSTALL_DATA="${INSTALL_DATA}"
ALL_TARGET=	all

MANN=		gdtclft.n

NO_STAGE=	yes
post-patch:
	${REINPLACE_CMD} -Ee 's,[[:space:]]+$$,,' ${WRKSRC}/${MANN}

post-install:
	${INSTALL_MAN} ${WRKSRC}/${MANN} ${PREFIX}/man/mann/

.include <bsd.port.mk>

PLIST_SUB!=	${SETENV} TCL_VER=${TCL_VER} ${MAKE} -f ${MAKEFILE} env
