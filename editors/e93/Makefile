# New ports collection makefile for:	e93
# Date created:		21 June 1995
# Whom:			Satoshi Asami (asami)
#
# $FreeBSD$
#

PORTNAME=	e93
PORTVERSION=	1.3.4
CATEGORIES=	editors tcl82 tk82
MASTER_SITES=	ftp://ftp.e93.org/pub/
DISTNAME=	${PORTNAME}-1.3r4X
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A nifty editor based on Tcl/Tk

LIB_DEPENDS=	tcl82.1:${PORTSDIR}/lang/tcl82 \
		tk82.1:${PORTSDIR}/x11-toolkits/tk82

WRKSRC=		${WRKDIR}/${PORTNAME}

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
