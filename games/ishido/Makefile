# ex:ts=8
# New ports collection makefile for:    ishido
# Version required:     1.1
# Date created:         Wed June 24, 1998
# Whom:                 Steven H. Samorodin (samorodi@NUXI.com)
#
# $FreeBSD$
#

DISTNAME=	ishido-1.1
CATEGORIES=	games
MASTER_SITES=	ftp://nuxi.ucdavis.edu/pub/misc/ \
		ftp://ftp.nuxi.com/pub/misc/

MAINTAINER=     samorodi@NUXI.com

USE_XLIB=	yes
MAN6=		ishido.6

do-install:
	${INSTALL_MAN} ${WRKSRC}/ishido.6 ${PREFIX}/man/man6
	${INSTALL} ${COPY} ${STRIP} -o ${BINOWN} -g games -m 2511 ${WRKSRC}/ishido ${PREFIX}/bin
	${INSTALL} ${COPY} -o ${BINOWN} -g games -m 664 ${WRKSRC}/ishido_scores  ${PREFIX}/share/misc/ishido_scores

.include <bsd.port.mk>
