# New ports collection makefile for:	festvox-tll
# Date created:        			2000-06-20
# Whom:					Trevor Johnson <trevor@jpj.net>
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.10 2000/02/15 09:26:17 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox-tll
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_FESTIVAL_OGI}
DISTNAME=	voice_tll_di-2.0
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	festival:${.CURDIR}/../festival \
		${LOCALBASE}/share/festival/lib/dicts/ogi_lex.out:${.CURDIR}/../festlex-ogi

RESTRICTED=	no-commercial-use

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	find ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755
	find ${WRKSRC} -type d -name CVS | xargs ${RM} -fr

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
