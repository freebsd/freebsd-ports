# New ports collection makefile for:	festogi-italian
# Date created:        			2005-02-15
# Whom:					Dario Freni
#
# $FreeBSD$
#

PORTNAME=	festogi-italian
PORTVERSION=	1.0
CATEGORIES=	audio accessibility
MASTER_SITES=	http://www.csrf.pd.cnr.it/Software/It-Festival/
DISTNAME=	italian_scm
DIST_SUBDIR=	festival

MAINTAINER=	saturnero@gufi.org
COMMENT=	Italian support for Festival

RUN_DEPENDS=	${LOCALBASE}/share/festival/lib/ogi_token.scm:${PORTSDIR}/audio/festival+OGI

USE_ZIP=yes

WRKSRC=		${WRKDIR}/festival

NO_BUILD=	yes

FHOME=		${PREFIX}/share/festival

post-extract:
	@${CHMOD} -R a+r ${WRKSRC}
	@${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

do-install:
	${MKDIR} ${FHOME}
	cd ${WRKSRC} && ${CP} -pPR * ${FHOME}

.include <bsd.port.mk>
