# New ports collection makefile for:	festvox-don
# Date created:        			2000-06-12
# Whom:					Trevor Johnson <trevor@jpj.net>
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.10 2000/02/15 09:26:14 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox_don
PORTVERSION=	1.4.0
CATEGORIES=	audio
MASTER_SITES=	http://www.speech.cs.cmu.edu/festival/cstr/festival/1.4.1/ \
		ftp://ftp.cstr.ed.ac.uk/pub/festival/1.4.1/
DISTNAME=	festvox_don
DIST_SUBDIR=	festival

MAINTAINER=	trevor@jpj.net

RUN_DEPENDS=	festival:../festival \
		${LOCALBASE}/share/festival/lib/dicts/wsj.wp39.poslexR:../festlex-poslex \
		${LOCALBASE}/share/festival/lib/dicts/oald/oaldlex.scm:../festlex-oald

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
