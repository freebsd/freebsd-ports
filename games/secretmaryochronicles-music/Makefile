# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	secretmaryochronicles-music
PORTVERSION=	5.0
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

PORTDOCS=	Addon_-_Music_Readme.txt

NO_STAGE=	yes

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
# The pointyhat build system doesn't like spaces in $PORTDOCS,
# so this makes it happier
	${MV} ${WRKSRC}/docs/Addon\ -\ Music\ Readme.txt \
		${WRKSRC}/docs/Addon_-_Music_Readme.txt

do-install:
	cd ${WRKSRC}/data && \
		${FIND} music | ${CPIO} -pdmvu ${DATADIR}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/docs/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
