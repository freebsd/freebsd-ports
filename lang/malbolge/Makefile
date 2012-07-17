# New ports collection makefile for:	malbolge
# Date created:		13 July 2012
# Whom:		Dereckson <dereckson@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	malbolge
PORTVERSION=	0.1.1
CATEGORIES=	lang
MASTER_SITES=	http://cdn.bitbucket.org/dereckson/${PORTNAME}/downloads/

MAINTAINER=	dereckson@gmail.com
COMMENT=	An esoteric language

PLIST_FILES=	bin/malbolge

PORTDOCS=	*

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/malbolge ${PREFIX}/bin

.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/malbolge.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
