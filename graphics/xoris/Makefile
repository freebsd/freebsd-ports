# New ports collection makefile for:	xoris
# Date created:				02 April 2006
# Whom:					Alexander Gromnizki
#
# $FreeBSD$
#

PORTNAME=	xoris
PORTVERSION=	0.1b
CATEGORIES=	graphics x11
MASTER_SITES=	http://gromnizki.unixdev.net/soft/

MAINTAINER=	grommizki@unixdev.net
COMMENT=	An X11 pixel color grabber

USE_IMAKE=	yes

.if !defined(NOPORTDOCS)
SUB_FILES=	pkg-message

post-install:
	@ ${ECHO_MSG} "===>   Installing documentation for ${PORTNAME}"
	@ ${MKDIR} ${DOCSDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}/
	@ ${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
