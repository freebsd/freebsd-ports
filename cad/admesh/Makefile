# New ports collection makefile for:	admesh
# Date created:			25 June 2003
# Whom:				Pedro F. Giffuni <giffunip@asme.org>
#
# $FreeBSD$
#

PORTNAME=	admesh
PORTVERSION=	0.95
CATEGORIES=	cad
MASTER_SITES=	http://www.varlog.com//products/admesh/files/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Program for processing STL triangulated solid meshes

GNU_CONFIGURE=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/admesh ${PREFIX}/bin/
.ifndef NOPORTDOCS
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ADMESH.DOC ${DOCSDIR}/admesh.doc
.endif

.include <bsd.port.mk>
