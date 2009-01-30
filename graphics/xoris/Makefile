# New ports collection makefile for:	xoris
# Date created:				02 April 2006
# Whom:					Alexander Gromnitsky
#
# $FreeBSD$
#

PORTNAME=	xoris
PORTVERSION=	0.1e
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	alexander.gromnitsky@gmail.com
COMMENT=	An X11 pixel color grabber

USE_XLIB=	yes
USE_IMAKE=	yes

.if !defined(NOPORTDOCS)
SUB_FILES=	pkg-message
.endif

post-install:
	@ ${INSTALL_SCRIPT} ${FILESDIR}/xoris-run.sh ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	@ ${ECHO_MSG} "===>   Installing documentation for ${PORTNAME}"
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
