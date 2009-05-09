# New ports collection makefile for:	festvox-ogirab
# Date created:        			2000-06-19
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.10 2000/02/15 09:26:16 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox-ogirab
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL_OGI}
DISTNAME=	voice_ogirab_di-2.0
DIST_SUBDIR=	festival

MAINTAINER=	ports@FreeBSD.org
COMMENT=British English male voice for Festival (non-commercial use only)

RUN_DEPENDS=	\
${PREFIX}/share/festival/lib/ogi_token.scm:${PORTSDIR}/audio/festival+OGI \
		${LOCALBASE}/share/festival/lib/dicts/ogi_lex.out:${PORTSDIR}/audio/festlex-ogi

RESTRICTED=	no-commercial-use

DEPRECATED=	unfulfilled dependencies for 8+ months, no maintainer, no user interest
EXPIRATION_DATE=2009-06-09

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	${FIND} ${WRKSRC} -type d -name CVS | ${XARGS} ${RM} -fr

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
