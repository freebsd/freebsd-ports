# New ports collection makefile for: unace
# URL: http://members.aol.com/mlemke6413/ace.html
# Version required:     1.2b
# Date created:         23 February 1999
# Whom:                 Joao Carlos Mendes Luis <jonny@jonny.eng.br>
#
# $Id$
#

DISTNAME=	unacepub
PKGNAME=	unace-1.2b
CATEGORIES=	archivers
MASTER_SITES=	http://members.aol.com/mlemke6413/
EXTRACT_SUFX=	.zip

MAINTAINER=	jonny@jonny.eng.br

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip

FETCH_BEFORE_ARGS=	-t

USE_GMAKE=	yes
ALL_TARGET=	unace
MAKEFILE=	unix/makefile

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${MKDIR} ${WRKSRC}
	@unzip -q -o ${DISTDIR}/${DISTNAME}${EXTRACT_SUFX} -d ${WRKSRC}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unace ${PREFIX}/bin

.include <bsd.port.mk>
