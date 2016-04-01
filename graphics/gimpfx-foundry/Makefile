# Created by: Christoph Moench-Tegeder <cmt@burggraben.net>
# $FreeBSD$

PORTNAME=	gimpfx-foundry
PORTVERSION=	2.6
PORTREVISION=	2
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-scriptpack/${PORTNAME}-${PORTVERSION}-1
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	cmt@burggraben.net
COMMENT=	Collection of scripts for The Gimp 2.6

# Maintainer has requested this use a specific version
# as the plugins may not always be backwards-compatible
RUN_DEPENDS=	gimp-2.8:graphics/gimp-app

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PORTDOCS=	release-notes.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/gimp/scripts/
	${INSTALL_DATA} ${WRKSRC}/*.scm ${STAGEDIR}${PREFIX}/share/gimp/scripts/

post-install:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/release-notes.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
