# New ports collection makefile for:	FINE
# Date created:			17 August 1999
# Whom:				Chris Piazza <cpiazza@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fine
PORTVERSION=	2.3
CATEGORIES=	editors
# DEAD MASTER_SITES=	ftp://razor.fer.uni-lj.si/pub/software/bojank/fine/
MASTER_SITES=	http://dccnet.linux.tucows.com/files/x11/office/
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org

USE_GMAKE=	yes
USE_QT_VER=	2
WRKSRC=		${WRKDIR}/fine

.include <bsd.port.pre.mk>

.if ${MACHINE_ARCH} == "alpha"
CFLAGS+=	-O0
.endif

do-install:
	@${MKDIR} ${PREFIX}/share/fine
	${INSTALL_DATA} ${WRKSRC}/.editor ${PREFIX}/share/fine/editor
.for template in C++.template LaTeX.template h.template  html.template
	${INSTALL_DATA} ${WRKSRC}/${template} ${PREFIX}/share/fine/
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/fine ${PREFIX}/bin

.include <bsd.port.post.mk>
