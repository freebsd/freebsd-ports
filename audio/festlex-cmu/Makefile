# New ports collection makefile for:	festlex-cmu
# Date created:        			2000-06-15
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.7 1999/12/28 04:19:58 wiz Exp $
# $FreeBSD$
#

PORTNAME=	festlex-cmu
PORTVERSION=	1.4.1
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	festlex_CMU
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	CMU American English pronunciation dictionary for Festival

RUN_DEPENDS=	festival:${PORTSDIR}/audio/festival

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
