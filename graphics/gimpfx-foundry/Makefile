# Created by: Christoph Moench-Tegeder <cmt@burggraben.net>
# $FreeBSD$

PORTNAME=	gimpfx-foundry
PORTVERSION=	2.6
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-scriptpack/${PORTNAME}-${PORTVERSION}-1
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	cmt@burggraben.net
COMMENT=	Collection of scripts for The Gimp 2.6

# Maintainer has requested this use a specific version
# as the plugins may not always be backwards-compatible
RUN_DEPENDS=	gimp-2.8:${PORTSDIR}/graphics/gimp-app

NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PORTDOCS=	release-notes.txt

NO_STAGE=	yes
do-install:
	${INSTALL_DATA} ${WRKSRC}/*.scm ${PREFIX}/share/gimp/scripts/

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/release-notes.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
