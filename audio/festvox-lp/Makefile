# New ports collection makefile for:	festvox-lp
# Date created:        			2005-02-15
# Whom:					Dario Freni
#
# $FreeBSD$
#

PORTNAME=	festvox-lp
PORTVERSION=	1.0
CATEGORIES=	audio accessibility
MASTER_SITES=	http://www.csrf.pd.cnr.it/Software/It-Festival/
DISTNAME=	lp_ogi_diphone
DIST_SUBDIR=	festival

MAINTAINER=	saturnero@gufi.org
COMMENT=	Italian female voice for Festival

RUN_DEPENDS=	${LOCALBASE}/share/festival/lib/ogi_token.scm:${PORTSDIR}/audio/festival+OGI \
		${LOCALBASE}/share/festival/lib/dicts/ifd/lex.out:${PORTSDIR}/audio/festlex-ifd \
		${LOCALBASE}/share/festival/lib/italian_scm/ifd_diph_ds_dur.scm:${PORTSDIR}/audio/festogi-italian

NO_BUILD=	yes
USE_ZIP=	YES
WRKSRC=		${WRKDIR}/festival
FHOME=		${PREFIX}/share/festival

post-extract:
	@ ${CHMOD} -R 644 ${WRKSRC}
	@ ${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
