# Ports collection makefile for:  pear-FSM
# Date created:			  10 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	FSM
PORTVERSION=	1.3.1
CATEGORIES=	devel www pear

MAINTAINER=	miwi@FreeBSD.org
COMMENT=	PEAR Finite State Machine

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear
RUN_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear

FILES=		FSM.php FSM/GraphViz.php
DOCS=		guide.txt graphviz.png
TESTS=		addTransitionsArray.phpt transitions.phpt graphviz.phpt
EXAMPLES=	rpn.php graphviz.php

LATEST_LINK=	pear-${PORTNAME}
OPTIONS=	PEAR_GraphViz "PEAR::GraphViz support" off

.include <bsd.port.pre.mk>

.if defined(WITH_PEAR_GraphViz)
RUN_DEPENDS+=	${PEARDIR}/GraphViz.php:${PORTSDIR}/graphics/pear-Image_GraphViz
.endif

.include "${PORTSDIR}/devel/pear/bsd.pear.mk"
.include <bsd.port.post.mk>
