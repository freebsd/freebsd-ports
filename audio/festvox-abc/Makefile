# New ports collection makefile for:	festvox-abc
# Date created:        			2000-06-12
# Whom:					Trevor Johnson <trevor@jpj.net>
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.10 2000/02/15 09:26:13 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox-abc
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_FESTIVAL_OGI}
DISTNAME=	voice_abc_di-2.0
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	festival:${.CURDIR}/../festival \
		${LOCALBASE}/share/festival/lib/ogi_spanish/ogi_span_mx_lts.scm:${.CURDIR}/../festogi-spanish \
		${LOCALBASE}/share/festival/lib/dicts/ogi_lex.out:${.CURDIR}/../festlex-ogi

RESTRICTED=	no-commercial-use

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	${CHMOD} -R a+r ${WRKSRC}
	find ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755
	${RM} -f ${WRKSRC}/lib/voices/spanish/abc_diphone/group/hvslpcOGI16k.group
	find ${WRKSRC} -type d -name CVS | xargs ${RM} -fr

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
