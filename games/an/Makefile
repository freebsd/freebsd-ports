# New ports collection makefile for:	an
# Date created:		28 Feb 1997
# Whom:			proff
#
# $FreeBSD$
#

PORTNAME=	an
PORTVERSION=	0.93
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.gtoal.com/wordgames/anagrams/${DISTNAME}/

MAINTAINER=	ports@FreeBSD.org

USE_REINPLACE=	yes
MAKE_ENV+=	DEFS=-DDEFDICT=\\\"/usr/share/dict/words\\\"
ALL_TARGET=	with-getopt
MAN6=		an.6

post-patch:
	@${FIND} ${WRKSRC} -name "Makefile" | ${XARGS} ${REINPLACE_CMD} -e \
		's|^CC=|CC?=|g ; \
		 s|^CFLAGS=-O|CFLAGS+=|g ; \
		 s| make| \$$\(MAKE\)|g'

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/an ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/an.6 ${MANPREFIX}/man/man6

.include <bsd.port.mk>
