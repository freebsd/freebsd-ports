# ports collection makefile for:	fkiss
# Version required:	0.28
# Date created:		31 Oct 1998
# Whom:			Seiichirou Hiraoka
#
# $Id: Makefile,v 1.1.1.1 1998/11/16 15:37:32 vanilla Exp $
#

DISTNAME=	fkiss028
PKGNAME=	fkiss-0.28
CATEGORIES=	games
MASTER_SITES=	http://www2s.biglobe.ne.jp/~yav/soft/fkiss/

MAINTAINER=	flathill@flathill.gr.jp

RUN_DEPENDS=	lha:${PORTSDIR}/archivers/lha

WRKSRC=		${WRKDIR}/fkiss
USE_IMAKE=	yes
MAN1=		fkiss.1

INSTALL_TARGET=	install install.man

post-install:
	${MKDIR} ${PREFIX}/share/examples/fkiss
	${INSTALL_DATA} ${WRKSRC}/frkismi4.lzh ${PREFIX}/share/examples/fkiss

.include <bsd.port.mk>
