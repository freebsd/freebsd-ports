# New ports collection makefile for:	C4
# Date created:		2 September 2001
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	c4
PORTVERSION=	1.6
CATEGORIES+=	devel
MASTER_SITES=	ftp://ftp.perforce.com/perforce/utils/c4/
DISTNAME=	${PORTNAME}

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A CVS-like Frontend to Perforce

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
ALL_TARGET=	c4

MAN1=		c4.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/c4 ${PREFIX}/bin/
.if !defined(NOPORTDOCS)
	${INSTALL_MAN} ${WRKSRC}/c4.1 ${PREFIX}/man/man1/
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/index.html ${DOCSDIR}/
.endif

.include <bsd.port.mk>
