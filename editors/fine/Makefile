# New ports collection makefile for:	FINE
# Version required:		2.1
# Date created:			17 August 1999
# Whom:				Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	fine
PKGNAME=	fine-2.1
CATEGORIES=	editors
MASTER_SITES=	ftp://razor.fer.uni-lj.si/pub/software/bojank/fine/

MAINTAINER=	cpiazza@FreeBSD.org

USE_NEWGCC=	yes
USE_GMAKE=	yes
USE_QT=		yes
WRKSRC=		${WRKDIR}/fine

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 400004
BROKEN=		'This program needs NEWGCC but links with QT, which is built with an old version.'
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/fine
	${INSTALL_DATA} ${WRKSRC}/.editor ${PREFIX}/share/fine/editor
.for template in C++.template LaTeX.template h.template  html.template
	${INSTALL_DATA} ${WRKSRC}/${template} ${PREFIX}/share/fine/
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/fine ${PREFIX}/bin

.include <bsd.port.post.mk>
