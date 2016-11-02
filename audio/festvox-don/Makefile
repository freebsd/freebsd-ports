# Created by: trevor
# $FreeBSD$

PORTNAME=	festvox-don
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	FESTIVAL/1.4.1
DISTNAME=	festvox_don
DIST_SUBDIR=	festival

MAINTAINER=	ports@FreeBSD.org
COMMENT=	British English male voice for Festival speech synthesis system

RUN_DEPENDS=	\
${LOCALBASE}/share/festival/lib/dicts/wsj.wp39.poslexR:audio/festlex-poslex \
${LOCALBASE}/share/festival/lib/dicts/oald/oaldlex.scm:audio/festlex-oald

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

do-install:
	@${MKDIR} ${STAGEDIR}${FHOME}
	cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${FHOME}

.include <bsd.port.mk>
