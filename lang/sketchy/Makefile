# Created by: Nils M Holm <nmh@t3x.org>
# $FreeBSD$

PORTNAME=	sketchy
PORTVERSION=	20070218
CATEGORIES=	lang devel lisp scheme
MASTER_SITES=	http://www.t3x.org/files/

MAINTAINER=	nmh@t3x.org
COMMENT=	An interpreter for purely applicative Scheme

USE_LDCONFIG=	yes
MAKE_ENV+=	BINOWN=${BINOWN} \
		BINGRP=${BINGRP}

MAN1=		sketchy.1 skpp.1
MLINKS=		sketchy.1 sk.1

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/sketchy.h
	@${REINPLACE_CMD} -e 's|/usr/local|${PREFIX}|g' ${WRKSRC}/src/pp.scm

.include <bsd.port.mk>
