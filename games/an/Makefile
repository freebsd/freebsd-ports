# New ports collection makefile for:	an
# Date created:		28 Feb 1997
# Whom:			proff
#
# $FreeBSD$
#

PORTNAME=	an
PORTVERSION=	0.93
CATEGORIES=	games
MASTER_SITES=	ftp://suburbia.net/pub/rmj/ \
		ftp://ftp.suburbia.net/pub/rmj/

MAINTAINER=	proff@iq.org

MAKE_ENV+=	DEFS=-DDEFDICT=\\\"/usr/share/dict/words\\\"
ALL_TARGET=	with-getopt
MAN6=		an.6

do-install:
		${INSTALL_PROGRAM} ${WRKSRC}/an ${PREFIX}/bin
		${INSTALL_MAN} ${WRKSRC}/an.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
