# New ports collection makefile for: id3ren
# URL: http://tscnet.com/pages/badcrc/apps/id3ren/
# Version required:     0.97a
# Date created:         28 February 1999
# Whom:                 Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $Id: $
#

DISTNAME=	id3ren97a
PKGNAME=	id3ren-0.97a
CATEGORIES=	audio
MASTER_SITES=	http://tscnet.com/pages/badcrc/apps/id3ren/
EXTRACT_SUFX=	.zip

MAINTAINER=	jonny@jonny.eng.br

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

WRKSRC=		${WRKDIR}/id3ren/src

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@unzip -q -o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -d ${WRKDIR}

.include <bsd.port.mk>
