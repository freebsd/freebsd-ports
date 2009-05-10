# New ports collection makefile for:	festvox-lp
# Date created:        			2005-02-15
# Whom:					Dario Freni
#
# $FreeBSD$
#

PORTNAME=	festvox-lp
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	it-festival
DISTNAME=	Italian-FESTIVAL
DIST_SUBDIR=	festival

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Italian female voice for Festival

RUN_DEPENDS=	${LOCALBASE}/share/festival/lib/ogi_token.scm:${PORTSDIR}/audio/festival+OGI \
		${LOCALBASE}/share/festival/lib/dicts/ifd/lex.out:${PORTSDIR}/audio/festlex-ifd \
		${LOCALBASE}/share/festival/lib/italian_scm/ifd_diph_ds_dur.scm:${PORTSDIR}/audio/festogi-italian

NO_BUILD=	yes
USE_ZIP=	YES

DEPRECATED=	unfulfilled dependencies for 8+ months, no active maintainer, no user interest
EXPIRATION_DATE=2009-06-10

WRKSRC=		${WRKDIR}/festival
FHOME=		${PREFIX}/share/festival

post-extract:
	@${UNZIP_CMD} -qq -d ${WRKDIR} ${WRKDIR}/lp_ogi_diphone.zip
	@${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${CHMOD} 644

do-install:
	${MKDIR} ${FHOME}
	(cd ${WRKSRC} && ${CP} -pPR * ${FHOME})

.include <bsd.port.mk>
