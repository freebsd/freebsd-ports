# Created by: Christoph Moench-Tegeder <cmt@burggraben.net>
# $FreeBSD$

PORTNAME=	gimpfx-foundry
PORTVERSION=	2.6
PORTREVISION=	3
PORTEPOCH=	1
CATEGORIES=	graphics
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-scriptpack/${PORTNAME}-${PORTVERSION}-1
DISTNAME=	${PORTNAME}-${PORTVERSION}-1

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Collection of scripts for The Gimp 2.6

LICENSE_COMB=	multi
LICENSE=	GPLv2 GPLv3 PD
# from release-notes.txt
LICENSE_TEXT=	Scripts contained in this pack are licensed under GPL license, \
		either version 2 or version 3 or in some cases public domain \
		according to the authors preference.

DEPRECATED=	No release for 10 years, only partially working with recent GIMP
EXPIRATION_DATE=	2018-11-30

# Maintainer has requested this use a specific version
# as the plugins may not always be backwards-compatible
RUN_DEPENDS=	gimp-2.10:graphics/gimp-app

NO_ARCH=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PORTDOCS=	release-notes.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/share/gimp/scripts/
	${INSTALL_DATA} ${WRKSRC}/*.scm ${STAGEDIR}${PREFIX}/share/gimp/scripts/

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/release-notes.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
