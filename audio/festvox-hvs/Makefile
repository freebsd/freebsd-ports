# New ports collection makefile for:	festvox-hvs
# Date created:        			2000-06-20
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.10 2000/02/15 09:26:14 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox-hvs
PORTVERSION=	2.0
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL_OGI}
DISTNAME=	voice_hvs_di-2.0
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Mexican Spanish female voice for Festival

RESTRICTED=	no-commercial-use

RUN_DEPENDS=	\
${PREFIX}/share/festival/lib/ogi_token.scm:${PORTSDIR}/audio/festival+OGI \
		${LOCALBASE}/share/festival/lib/dicts/wsj.wp39.poslexR:${PORTSDIR}/audio/festlex-poslex \
		${LOCALBASE}/share/festival/lib/dicts/ogi_lex.out:${PORTSDIR}/audio/festlex-ogi \
		${LOCALBASE}/share/festival/lib/ogi_spanish/ogi_span_mx_lts.scm:${PORTSDIR}/audio/festogi-spanish

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@ ${FIND} ${WRKSRC} -type d -name CVS | ${XARGS} ${RM} -fr

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
