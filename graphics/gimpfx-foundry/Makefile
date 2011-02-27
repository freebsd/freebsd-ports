# New ports collection makefile for:   gimpfx-foundry
# Date created:        7 February 2008
# Whom:                Christoph Moench-Tegeder <cmt@burggraben.net>
#
# $FreeBSD$
#

PORTNAME=	gimpfx-foundry
PORTVERSION=	2.6
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-scriptpack/${PORTNAME}-${PORTVERSION}-1
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	cmt@burggraben.net
COMMENT=	A collection of scripts for The Gimp 2.6

RUN_DEPENDS=	gimp-2.6:${PORTSDIR}/graphics/gimp-app

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PORTDOCS=	release-notes.txt

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.scm ${PREFIX}/share/gimp/scripts/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/release-notes.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
