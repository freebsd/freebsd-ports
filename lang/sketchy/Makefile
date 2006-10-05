# New ports collection makefile for:	SketchyLISP
# Date created:				12 May 2005
# Whom:					Nils M Holm <nmh@t3x.org>
#
# $FreeBSD$
#

PORTNAME=	sketchy
PORTVERSION=	20061005
CATEGORIES=	lang devel lisp scheme
MASTER_SITES=	http://www.t3x.org/files/

MAINTAINER=	nmh@t3x.org
COMMENT=	An interpreter for purely applicative Scheme

MAN7=		sketchy.7

MAKE_ENV+=	BINOWN=${BINOWN} \
		BINGRP=${BINGRP}

# Please keep this!
USE_REINPLACE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/sketchy.h

.include <bsd.port.mk>
