# New ports collection makefile for:    sced
# Version required:     0.94
# Date created:         27  Dec 1996
# Whom:                 proff@iq.org
#
# $Id: Makefile,v 1.3 1997/02/19 04:58:23 asami Exp $
#

DISTNAME=       sced-1.01
CATEGORIES=	graphics
MASTER_SITES=	http://www.cs.berkeley.edu/~schenney/sced/src/ \
		http://www.physik.TU-Berlin.DE/~ibex/ports/distfiles/

MAINTAINER=	ports@FreeBSD.ORG

RUN_DEPENDS=	povray:${PORTSDIR}/graphics/povray

USE_XLIB=	yes
GNU_CONFIGURE=	yes

MAN1=		sced.1

do-install:
	${INSTALL_PROGRAM}  ${WRKSRC}/sced ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/docs/man/man1/sced.1 ${PREFIX}/man/man1
	${MKDIR} ${PREFIX}/lib/sced
	${INSTALL_DATA} ${WRKSRC}/scenerc ${PREFIX}/lib/sced
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/sced
	${INSTALL_DATA} ${WRKSRC}/docs/guide.* ${PREFIX}/share/doc/sced
.endif

.include <bsd.port.mk>
