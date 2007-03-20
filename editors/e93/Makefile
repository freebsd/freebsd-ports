# New ports collection makefile for:	e93
# Date created:		21 June 1995
# Whom:			Satoshi Asami (asami)
#
# $FreeBSD$
#

PORTNAME=	e93
PORTVERSION=	1.3.4
PORTREVISION=	1
CATEGORIES=	editors tcl84 tk84
MASTER_SITES=	ftp://ftp.e93.org/pub/ \
  		http://www.crpetsmoker.net/distfiles/ \
		http://www.xs4all.nl/~tournoij/distfiles/
DISTNAME=	${PORTNAME}-1.3r4X
EXTRACT_SUFX=	.tgz

MAINTAINER=	carpetsmoker@xs4all.nl
COMMENT=	A nifty editor based on Tcl/Tk

USE_TCL=	yes
USE_TCL_BUILD=	yes
USE_TK=		yes
USE_TK_BUILD=	yes
USE_XLIB=	yes
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
