# New ports collection makefile for:	e93
# Date created:		21 June 1995
# Whom:			Satoshi Asami (asami)
#
# $FreeBSD$
#

PORTNAME=	e93
PORTVERSION=	1.3.4
PORTREVISION=	2
CATEGORIES=	editors tcl tk
MASTER_SITES=	ftp://ftp.e93.org/pub/
DISTNAME=	${PORTNAME}-1.3r4X
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A nifty editor based on Tcl/Tk

USE_TCL=	84
USE_TCL_BUILD=	84
USE_TK=		84
USE_TK_BUILD=	84
USE_XORG=	x11 xt
WRKSRC=		${WRKDIR}/${PORTNAME}

post-patch:
	@${REINPLACE_CMD} 's|wish|wish${TK_VER}|' ${WRKSRC}/e93r
	@${REINPLACE_CMD} 's|CFLAGS=|CFLAGS+=$$(TK_INCLUDE) -I${LOCALBASE}/include |' \
		${WRKSRC}/Makefile ${WRKSRC}/xgui/Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/e93 ${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/e93r ${PREFIX}/bin
	${MKDIR} ${PREFIX}/lib/e93lib
	${CP} -R ${WRKSRC}/e93lib/* ${PREFIX}/lib/e93lib
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README* ${DOCSDIR}
.endif

.include <bsd.port.mk>
