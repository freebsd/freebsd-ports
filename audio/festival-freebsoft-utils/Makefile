# $FreeBSD$

PORTNAME=	festival-freebsoft-utils
PORTVERSION=	0.10
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	http://www.freebsoft.org/pub/projects/${PORTNAME}/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Festival utilities focused on interaction with Speech Dispatcher

RUN_DEPENDS=	festival:${PORTSDIR}/audio/festival \
		sox:${PORTSDIR}/audio/sox

NO_BUILD=	yes
USES=		iconv
NO_STAGE=	yes

PORTDOCS=	ANNOUNCE NEWS README

INFO=		${PORTNAME}

.include <bsd.port.options.mk>

do-install:
	${MKDIR} ${LOCALBASE}/share/festival/lib
	cd ${WRKSRC} && ${INSTALL_DATA} *.scm ${LOCALBASE}/share/festival/lib
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${PORTNAME}.info ${PREFIX}/${INFO_PATH}

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
