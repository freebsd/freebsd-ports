# New ports collection makefile for:	zh-ttfm
# Date created:		12 Nov 2000
# Whom:			Jing-Tang Keith Jang <keith@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ttfm
PORTVERSION=	0.9.5
CATEGORIES=	chinese print
MASTER_SITES=	ftp://freebsd.sinica.edu.tw/pub/statue/ttfm/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Big5/GB enhanced TrueType Font Manager

RUN_DEPENDS=	mkfontdir:${X_CLIENTS_PORT}
LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2

PORTDOCS=	README USAGE
MAN1=		ttfm.sh.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ttfinfo ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/ttfm.sh ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for doc in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${doc} ${DOCSDIR}
.endfor
.endif
	${INSTALL_MAN} ${WRKSRC}/ttfm.sh.1 ${PREFIX}/man/man1
	@${MKDIR} ${DATADIR}
.for module in gscjk.ttfm xttfm.ttfm
	${INSTALL_SCRIPT} ${WRKSRC}/modules/${module} ${DATADIR}
.endfor

.include <bsd.port.mk>
