# New ports collection makefile for:	festvox-el11
# Date created:        			2000-06-20
# Whom:					Trevor Johnson <trevor@jpj.net>
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.7 1999/12/28 04:19:59 wiz Exp $
# $FreeBSD$
#

PORTNAME=	festvox-el11
PORTVERSION=	1.4.0
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/ \
		${MASTER_SITE_NETBSD} \
		ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/
DISTNAME=	festvox_ellpc11k
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	festival:${.CURDIR}/../festival

WRKSRC=		${WRKDIR}/festival

CONFLICTS=	festvox-rab8

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

post-install:
	${RM} ${PREFIX}/share/festival/lib/voices/spanish/el_diphone/COPYING

.include <bsd.port.mk>
