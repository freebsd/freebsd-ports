# ex:ts=8
# New ports collection makefile for:   ucpp
# Date created:                Feb 16, 2001
# Whom:                        Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ucpp
PORTVERSION=	1.2
CATEGORIES=	devel
MASTER_SITES=	http://pornin.nerim.net/ucpp/

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	A C preprocessor and lexer

MAKE_ENV=	FLAGS="${CFLAGS}"

MAN1=	ucpp.1

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/${MAN1} ${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
