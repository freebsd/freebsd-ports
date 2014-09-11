# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	secretmaryochronicles-music
PORTVERSION=	5.0
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/smclone/Addon%20-%20Music/${PORTVERSION}
DISTNAME=	SMC_Music_${PORTVERSION}_high

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Background music for Secret Maryo Chronicles

RUN_DEPENDS=	smc:${PORTSDIR}/games/secretmaryochronicles

USES=		zip

WRKSRC=		${WRKDIR}
DATADIR=	${PREFIX}/share/smc
NO_BUILD=	yes

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

do-install:
	cd ${WRKSRC}/data && ${COPYTREE_SHARE} music ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/Addon\ -\ Music\ Readme.txt \
		${STAGEDIR}${DOCSDIR}/Addon_-_Music_Readme.txt

.include <bsd.port.mk>
