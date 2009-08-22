# New ports collection makefile for:	q-graph
# Date created:		14 August 2003
# Whom:			ag@muwiinfa.geschichte.uni-mainz.de Albert Graef
#
# $FreeBSD$
#

PORTNAME=	graph
PORTVERSION=	1.8
PORTREVISION=	2
CATEGORIES=	graphics
MASTER_SITES=	SF/q-lang/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	q-

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Q-Graph -- graph library and editor for the Q language

LIB_DEPENDS=	q.8:${PORTSDIR}/lang/q
RUN_DEPENDS=	${LOCALBASE}/lib/bwidget/init.tcl:${PORTSDIR}/x11-toolkits/bwidget

DATADIR=	${PREFIX}/share/q

GNU_CONFIGURE=	yes

.include <bsd.port.mk>
