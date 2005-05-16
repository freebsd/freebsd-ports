# New ports collection makefile for:	SketchyLISP
# Date created:				12 May 2005
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	sketchy
PORTVERSION=	20050512
CATEGORIES=	lang devel lisp
MASTER_SITES=	http://www.t3x.org/sketchy/

MAINTAINER=	nmh@t3x.org
COMMENT=	An interpreter for purely symbolic LISP that smells like Scheme

BUILD_DEPENDS=	tx:${PORTSDIR}/lang/t3x

MAN7=		sketchy.7

MAKE_ENV+=	T3XDIR=${LOCALBASE}/t3x/r8 \
		BINOWN=${BINOWN} \
		BINGRP=${BINGRP} \
		PREFIX=${PREFIX}

.include <bsd.port.mk>
