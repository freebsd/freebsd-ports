# New ports collection makefile for:	festvox-ogirab
# Date created:        			2000-06-19
# Whom:					Trevor Johnson <trevor@jpj.net>
# based on the NetBSD port
#
# $NetBSD: Makefile,v 1.10 2000/02/15 09:26:16 agc Exp $
# $FreeBSD$
#

PORTNAME=	festvox-ogirab
PORTVERSION=	2.0
CATEGORIES=	audio
MASTER_SITES=	ftp://ftp.leb.net/pub/blinux/festival/mirror.ogi-synth_home/ \
		ftp://ftp.mayn.de/pub/linux/BLinux/festival/mirror.ogi-synth_home/ \
		ftp://cslu.cse.ogi.edu/pub/tts/
DISTNAME=	voice_ogirab_di-2.0
DIST_SUBDIR=	festival

MAINTAINER=	trevor@FreeBSD.org

RUN_DEPENDS=	festival:${.CURDIR}/../festival \
		${LOCALBASE}/share/festival/lib/dicts/ogi_lex.out:${.CURDIR}/../festlex-ogi

RESTRICTED=	no-commercial-use

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R a+r ${WRKSRC}
	find ${WRKSRC} -type d -print0 | xargs -0 ${CHMOD} 755
	find ${WRKSRC} -type d -name CVS | xargs ${RM} -fr

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
