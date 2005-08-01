# New ports collection makefile for:	dte
# Date created:				4 October 2000
# Whom:					Steve Horan <sjhports@tracking.amos.net>
#
# $FreeBSD$
#

PORTNAME=	dte
PORTVERSION=	6.12
CATEGORIES=	editors
MASTER_SITES=	http://freebsd.t-hosting.hu/dte/
EXTRACT_SUFX=	.tgz

MAINTAINER=	gkovesdan@t-hosting.hu
COMMENT=	A text editor which uses many of the shortcuts used in MSDOS EDIT

MAN1=		dte.1
PORTDOCS=	dte.doc dte.hlp dte.rc
PLIST_FILES=	bin/dte

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/dte ${PREFIX}/bin/dte
	${INSTALL_MAN} ${WRKSRC}/dte.1 ${MANPREFIX}/man/man1
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
