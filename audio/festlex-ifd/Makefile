# New ports collection makefile for:	festlex-ifd
# Date created:        			2005-02-15
# Whom:					Dario Freni
#
# $FreeBSD$
#

PORTNAME=	festlex-ifd
PORTVERSION=	1.0
CATEGORIES=	audio accessibility
MASTER_SITES=	http://www.csrf.pd.cnr.it/Software/It-Festival/
DISTNAME=	lex_ifd
DIST_SUBDIR=	festival

MAINTAINER=	saturnero@gufi.org
COMMENT=	Italian lexicon for Festival

RUN_DEPENDS=	${LOCALBASE}/share/festival/lib/ogi_token.scm:${PORTSDIR}/audio/festival+OGI

NO_BUILD=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/festival
FHOME=		${PREFIX}/share/festival

post-extract:
	@${CHMOD} -R 644 ${WRKSRC}
	@${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
