# New ports collection makefile for:	festvox-el11
# Date created:        			2000-06-20
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.7 1999/12/28 04:19:59 wiz Exp $
# $FreeBSD$
#

PORTNAME=	festvox-el11
PORTVERSION=	1.4.0
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	1.4.1
DISTNAME=	festvox_ellpc11k
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Castilian Spanish male voice for Festival

RUN_DEPENDS=	festival:${PORTSDIR}/audio/festival

BROKEN=		Incomplete pkg-plist
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

WRKSRC=		${WRKDIR}/festival

CONFLICTS=	festvox-rab8

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

post-install:
	${RM} ${PREFIX}/share/festival/lib/voices/spanish/el_diphone/COPYING

.include <bsd.port.mk>
