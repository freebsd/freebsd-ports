# New ports collection makefile for:	festival-freebsoft-utils
# Date created:				6 January 2010
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	festival-freebsoft-utils
PORTVERSION=	0.10
PORTREVISION=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	http://www.freebsoft.org/pub/projects/${PORTNAME}/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	Festival utilities focused on interaction with Speech Dispatcher

RUN_DEPENDS=	festival:${PORTSDIR}/audio/festival \
		sox:${PORTSDIR}/audio/sox

NO_BUILD=	yes
USE_ICONV=	yes

PORTDOCS=	ANNOUNCE NEWS README

INFO=		${PORTNAME}

do-install:
	${MKDIR} ${LOCALBASE}/share/festival/lib
	cd ${WRKSRC} && ${INSTALL_DATA} *.scm ${LOCALBASE}/share/festival/lib
	cd ${WRKSRC}/doc && ${INSTALL_MAN} ${PORTNAME}.info ${PREFIX}/${INFO_PATH}

post-install:
.ifndef(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_MAN} ${WRKSRC}/${f} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
