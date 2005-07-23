# New ports collection makefile for:	festlex-poslex
# Date created:        			2000-06-12
# Whom:					Trevor Johnson
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.7 1999/12/28 04:19:59 wiz Exp $
# $FreeBSD$
#

PORTNAME=	festlex-poslex
PORTVERSION=	1.4.1
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_FESTIVAL}
MASTER_SITE_SUBDIR=	${PORTVERSION}
DISTNAME=	festlex_POSLEX
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	English lexicon for Festival

RUN_DEPENDS=	festival:${PORTSDIR}/audio/festival

BROKEN=		Incomplete pkg-plist
DEPRECATED=	"${BROKEN}"
EXPIRATION_DATE=2005-09-22

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

do-install:
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
