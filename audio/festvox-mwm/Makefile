# New ports collection makefile for:	festvox-mwm
# Date created:        			2000-06-20
# Whom:					Trevor Johnson <trevor@jpj.net>
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.10 2000/02/15 09:26:16 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox-mwm
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_FESTIVAL_OGI}
DISTNAME=	voice_mwm_di-2.0
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org

RESTRICTED=	no-commercial-use

RUN_DEPENDS=	festival:${.CURDIR}/../festival \
		${LOCALBASE}/share/festival/lib/dicts/wsj.wp39.poslexR:${.CURDIR}/../festlex-poslex \
		${LOCALBASE}/share/festival/lib/dicts/ogi_lex.out:${.CURDIR}/../festlex-ogi

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755
	@ find ${WRKSRC} -type d -name CVS | xargs ${RM} -fr

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

post-install:
	${RM} -rf ${PREFIX}/share/festival/lib/voices/english/mwm_diphone/work

.include <bsd.port.mk>
