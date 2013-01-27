# Created by: trevor
# $FreeBSD$

PORTNAME=	festvox-don
PORTVERSION=	1.4.0
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	1.4.1
DISTNAME=	festvox_don
DIST_SUBDIR=	festival

MAINTAINER=	ports@FreeBSD.org
COMMENT=	British English male voice for Festival speech synthesis system

RUN_DEPENDS=	\
${LOCALBASE}/share/festival/lib/dicts/wsj.wp39.poslexR:${PORTSDIR}/audio/festlex-poslex \
${LOCALBASE}/share/festival/lib/dicts/oald/oaldlex.scm:${PORTSDIR}/audio/festlex-oald

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
