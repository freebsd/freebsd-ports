# New ports collection makefile for:	ArrowLISP
# Date created:				12 Aug 2003
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	alisp
PORTVERSION=	20060602
CATEGORIES=	lang devel lisp
MASTER_SITES=	http://www.t3x.org/files/

MAINTAINER=	nmh@t3x.org
COMMENT=	An interpreter for purely symbolic LISP

MAN7=		alisp.7
MANCOMPRESSED=	no

INSTALLS_SHLIB=	yes
MAKE_ENV+=	BINOWN=${BINOWN} \
		BINGRP=${BINGRP} \
		PREFIX=${PREFIX}

.include <bsd.port.mk>
