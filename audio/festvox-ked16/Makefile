# New ports collection makefile for:	festvox-ked16
# Date created:        			2000-06-20
# Whom:					Trevor Johnson <trevor@jpj.net>
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.8 2000/02/15 09:26:15 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox-ked16
PORTVERSION=	1.4.0
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/ \
		ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/
DISTNAME=	festvox_kedlpc16k
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	festival:${.CURDIR}/../festival \
		${LOCALBASE}/share/festival/lib/dicts/wsj.wp39.poslexR:${.CURDIR}/../festlex-poslex \
		${LOCALBASE}/share/festival/lib/dicts/cmu/cmulex.scm:${.CURDIR}/../festlex-cmu

WRKSRC=		${WRKDIR}/festival

CONFLICTS=	festvox-ked8-*

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
