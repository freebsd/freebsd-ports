# New ports collection makefile for:	festlex-ifd
# Date created:        			2005-02-15
# Whom:					Dario Freni
#
# $FreeBSD$
#

PORTNAME=	festlex-ifd
PORTVERSION=	1.0
PORTREVISION=	2
CATEGORIES=	audio accessibility
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	it-festival
DISTNAME=	Italian-FESTIVAL
DIST_SUBDIR=	festival

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Italian lexicon for Festival

RUN_DEPENDS=	${LOCALBASE}/share/festival/lib/ogi_token.scm:${PORTSDIR}/audio/festival+OGI

DEPRECATED=	unfulfilled dependencies for 8+ months, no active maintainer, no user interest
EXPIRATION_DATE=2009-06-10

NO_BUILD=	yes
USE_ZIP=	yes

WRKSRC=		${WRKDIR}/festival
FHOME=		${PREFIX}/share/festival

post-extract:
	@${UNZIP_CMD} -qq -d ${WRKDIR} ${WRKDIR}/lex_ifd.zip
	@${FIND} ${WRKSRC} -type d -print0 | ${XARGS} -0 ${CHMOD} 755
	@${FIND} ${WRKSRC} -type f -print0 | ${XARGS} -0 ${CHMOD} 644

do-install:
	${MKDIR} ${FHOME}
	(cd ${WRKSRC} && ${CP} -pPR * ${FHOME})

.include <bsd.port.mk>
