# New ports collection makefile for:	FINE
# Version required:		2.1
# Date created:			17 August 1999
# Whom:				Chris Piazza <cpiazza@FreeBSD.org>
#
# $Id$
#

DISTNAME=	fine
PKGNAME=	fine-2.1
CATEGORIES=	editors
MASTER_SITES=	ftp://razor.fer.uni-lj.si/pub/software/bojank/fine/

MAINTAINER=	cpiazza@FreeBSD.org

USE_GMAKE=	yes
USE_QT=		yes
WRKSRC=		${WRKDIR}/fine

do-install:
	@${MKDIR} ${PREIFX}/share/fine
	${INSTALL_DATA} ${WRKSRC}/.editor ${PREFIX}/share/fine/editor
.for template in C++.template LaTeX.template h.template  html.template
	${INSTALL_DATA} ${WRKSRC}/${template} ${PREFIX}/share/fine/
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/fine ${PREFIX}/bin

.include <bsd.port.mk>
