# New ports collection makefile for:	xbarcode
# Date created:				1 October 2000
# Whom:					brett@nodetree.net
#
# $FreeBSD$
#

PORTNAME=	xbarcode
PORTVERSION=	2.11
CATEGORIES=	graphics
MASTER_SITES=	http://www.nodetree.net/distfiles/

MAINTAINER=	brett@nodetree.net
COMMENT=	Generates bar codes in a variety of formats

LIB_DEPENDS=	xview.3:${PORTSDIR}/x11-toolkits/xview
RUN_DEPENDS=	pnmfile:${PORTSDIR}/graphics/netpbm

NO_CDROM=	Must not be sold
MAN1=		XBarcode.1
MLINKS=		XBarcode.1 bar.1
ALL_TARGET=	XBarcode
USE_XLIB=	yes

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502000
BROKEN=		"Does not compile"
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/XBarcode ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bar ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/XBarcode.1 ${MAN1PREFIX}/man/man1

.include <bsd.port.post.mk>
