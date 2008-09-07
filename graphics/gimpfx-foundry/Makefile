# New ports collection makefile for:   gimpfx-foundry
# Date created:        7 February 2008
# Whom:                Christoph Moench-Tegeder <cmt@burggraben.net>
#
# $FreeBSD$
#

PORTNAME=	gimpfx-foundry
PORTVERSION=	20080323
CATEGORIES=	graphics
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-scriptpack-${PORTVERSION}

MAINTAINER=	cmt@burggraben.net
COMMENT=	A collection of scripts for The Gimp 2.4

RUN_DEPENDS=	gimp-2.4:${PORTSDIR}/graphics/gimp-app

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PORTDOCS=	release-manifest.txt

do-install:
	${INSTALL_DATA} ${WRKSRC}/*.scm ${LOCALBASE}/share/gimp/scripts/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/release-manifest.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
