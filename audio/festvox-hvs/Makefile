# New ports collection makefile for:	festvox-hvs
# Date created:        			2000-06-20
# Whom:					Trevor Johnson <trevor@jpj.net>
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.10 2000/02/15 09:26:14 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox-hvs
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.leb.net/pub/blinux/festival/mirror.ogi-synth_home/ \
		ftp://ftp.mayn.de/pub/linux/BLinux/festival/mirror.ogi-synth_home/ \
		ftp://cslu.cse.ogi.edu/pub/tts/
DISTNAME=	voice_hvs_di-2.0
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org

RESTRICTED=	no-commercial-use

RUN_DEPENDS=	festival:${.CURDIR}/../festival \
		${LOCALBASE}/share/festival/lib/dicts/wsj.wp39.poslexR:${.CURDIR}/../festlex-poslex \
		${LOCALBASE}/share/festival/lib/dicts/ogi_lex.out:${.CURDIR}/../festlex-ogi \
		${LOCALBASE}/share/festival/lib/ogi_spanish/ogi_span_mx_lts.scm:${.CURDIR}/../festogi-spanish

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	@ find ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755
	@ find ${WRKSRC} -type d -name CVS | xargs ${RM} -fr

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
