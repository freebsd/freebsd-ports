# Created by: Sven Moeller <smoeller@nichthelfer.de>
# $FreeBSD$

PORTNAME=	megaglest
PORTVERSION=	3.11.1
CATEGORIES=	games
PKGNAMESUFFIX=	-data
DISTNAME=	${PORTNAME}${PKGNAMESUFFIX}-${PORTVERSION}

MAINTAINER=	monwarez@mailoo.org
COMMENT=	MegaGlest data files

USE_GITHUB=	yes
GH_ACCOUNT=	MegaGlest
GH_PROJECT=	megaglest-data

USES=		dos2unix tar:xz
DOS2UNIX_GLOB=	*.log *.ini *.html *.txt *.lng
NO_BUILD=	yes
NO_ARCH=	yes

BASEDOCS=	AUTHORS.data.txt README.data-license.txt \
		cc-by-sa-3.0-unported.txt COPYRIGHT.data.txt
PORTDOCS=	*
PORTDATA=	*

OPTIONS_DEFINE=	DOCS

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} "data maps scenarios techs tilesets tutorials" ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC}/docs && ${COPYTREE_SHARE} "${BASEDOCS} glest_factions" ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
