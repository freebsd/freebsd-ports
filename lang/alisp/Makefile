# New ports collection makefile for:	ArrowLISP
# Date created:				12 Aug 2003
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	alisp
PORTVERSION=	8
CATEGORIES=	lang devel
MASTER_SITES=	http://t3x.dyndns.org/files/ \
		http://www.t3x.org/files/
DISTNAME=	alisp${PORTVERSION}

MAINTAINER=	nmh@t3x.org
COMMENT=	A tail-recursive interpreter for purely symbolic LISP

BUILD_DEPENDS=	tx:${PORTSDIR}/lang/t3x \
		${LOCALBASE}/t3x/r8/tide:${PORTSDIR}/devel/tide

MAN7=		alisp.7
MANCOMPRESSED=	no

MAKE_ENV+=	T3XDIR=${LOCALBASE}/t3x/r8 \
		BINOWN=${BINOWN} \
		BINGRP=${BINGRP}

USE_REINPLACE=	yes

post-patch:
	${REINPLACE_CMD} \
		-e 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/Makefile
	${REINPLACE_CMD} \
		-e 's,/usr/local,${PREFIX},g' \
		${WRKSRC}/cnf/dfl_unix.rc

.include <bsd.port.mk>
