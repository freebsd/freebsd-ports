# New ports collection makefile for:	dte
# Date created:				4 October 2000
# Whom:					Steve Horan <sjhports@tracking.amos.net>
#
# $FreeBSD$
#

PORTNAME=	dte
PORTVERSION=	6.12
CATEGORIES=	editors
MASTER_SITES=	ftp://mugca.cc.monash.edu.au/pub/dougt/
EXTRACT_SUFX=	.tgz

DEPRECATED=	"master site disappeared, last version in port is from 2000"
EXPIRATION_DATE=2005-07-31

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A simple text editor which uses many of the shortcuts used in MSDOS EDIT

MAN1=		dte.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dte ${PREFIX}/bin/dte
.if !defined(NOPORTDOCS)
	${MKDIR} ${PREFIX}/share/doc/dte
	${INSTALL_DATA} ${WRKSRC}/dte.doc ${PREFIX}/share/doc/dte/
	${INSTALL_DATA} ${WRKSRC}/dte.hlp ${PREFIX}/share/doc/dte/
	${INSTALL_DATA} ${WRKSRC}/dte.rc ${PREFIX}/share/doc/dte/
	${INSTALL_MAN} ${WRKSRC}/dte.1 ${MANPREFIX}/man/man1
.endif

.include <bsd.port.mk>
