# Ports collection makefile for:  pear-FSM
# Date created:			  10 January 2005
# Whom:				  Antonio Carlos Venancio Junior (<antonio@inf.ufsc.br>)
#
# $FreeBSD$
#

PORTNAME=	FSM
PORTVERSION=	1.2.2
CATEGORIES=	devel www pear

MAINTAINER=	antonio@php.net
COMMENT=	PEAR Finite State Machine

BUILD_DEPENDS=	${PEARDIR}/PEAR.php:${PORTSDIR}/devel/pear-PEAR
RUN_DEPENDS=	${BUILD_DEPENDS}

FILES=		FSM.php
DOCS=		guide.txt
TESTS=		001.phpt
EXAMPLES=	rpn.php
_EXAMPLESDIR=	docs/examples

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/devel/pear-PEAR/Makefile.common"
.include <bsd.port.post.mk>
