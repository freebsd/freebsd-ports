# New ports collection makefile for:	q-graph
# Date created:		14 August 2003
# Whom:			ag@muwiinfa.geschichte.uni-mainz.de Albert Graef
#
# $FreeBSD$
#

PORTNAME=	graph
PORTVERSION=	1.2
PORTREVISION=	3
CATEGORIES=	graphics
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	q-lang
PKGNAMEPREFIX=	q-

MAINTAINER=	ag@muwiinfa.geschichte.uni-mainz.de
COMMENT=	Q-Graph -- graph library and editor for the Q language

RUN_DEPENDS=	${LOCALBASE}/bin/q:${PORTSDIR}/lang/q

USE_GNOME=	gnometarget
GNU_CONFIGURE=	yes

DATADIR=	${PREFIX}/share/q
EXAMPLESDIR=	${PREFIX}/share/examples/q/graph

post-patch:
	@${FIND} ${WRKSRC} -name Makefile.in | ${XARGS} \
		${GREP} -l "^examplesdir" | ${XARGS} ${REINPLACE_CMD} -e \
		"s;[(]pkgdatadir[)]/examples;(datadir)/examples/q;"

.include <bsd.port.mk>
