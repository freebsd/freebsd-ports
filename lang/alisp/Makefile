# New ports collection makefile for:	ArrowLISP
# Date created:				12 Aug 2003
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	alisp
PORTVERSION=	20050425
CATEGORIES=	lang devel lisp
MASTER_SITES=	http://www.holm-und-jeschag.de/files/

MAINTAINER=	nils@holm-und-jeschag.de
COMMENT=	A tail-recursive interpreter for purely symbolic LISP

BUILD_DEPENDS=	tx:${PORTSDIR}/lang/t3x

MAN7=		alisp.7
MANCOMPRESSED=	no

MAKE_ENV+=	T3XDIR=${LOCALBASE}/t3x/r8 \
		BINOWN=${BINOWN} \
		BINGRP=${BINGRP} \
		PREFIX=${PREFIX}

.include <bsd.port.mk>
