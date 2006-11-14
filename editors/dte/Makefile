# New ports collection makefile for:	dte
# Date created:				4 October 2000
# Whom:					Steve Horan <sjhports@tracking.amos.net>
#
# $FreeBSD$
#

PORTNAME=	dte
PORTVERSION=	6.12
PORTREVISION=	1
CATEGORIES=	editors
MASTER_SITES=	http://personal.gscit.monash.edu.au/~dougt/
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A text editor which uses many of the shortcuts used in MSDOS EDIT

BROKEN=		Does not fetch

MAN1=		dte.1
PORTDOCS=	dte.doc dte.hlp dte.rc
PLIST_FILES=	bin/dte

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dte ${TARGETDIR}/bin/dte
	${INSTALL_MAN} ${WRKSRC}/dte.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
