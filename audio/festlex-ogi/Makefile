# New ports collection makefile for:	festlex-ogi
# Date created:        			2000-06-19
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.8 2000/02/15 09:26:12 agc Exp $
# $FreeBSD$
#

PORTNAME=	festlex-ogi
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL_OGI}
DISTNAME=	OGIlexicon-2.2
DIST_SUBDIR=	festival

MAINTAINER=	araujo@FreeBSD.org
COMMENT=	Composite pronunciation dictionary from ogi.edu for Festival

RUN_DEPENDS=	festival:${PORTSDIR}/audio/festival \
		${LOCALBASE}/share/festival/lib/dicts/wsj.wp39.poslexR:${PORTSDIR}/audio/festlex-poslex

RESTRICTED=	no-commercial-use

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
