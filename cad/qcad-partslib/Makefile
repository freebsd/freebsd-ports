# New ports collection makefile for:	qcad-partslib
# Date created:		28 Mar 2004
# Whom:			Michael Reifenberger <mr@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	qcad-partslib
PORTVERSION=	2.0.1.2.1
CATEGORIES=	cad
MASTER_SITES=	http://www.ribbonsoft.com/archives/partlibrary/
DISTNAME=	partlibrary-${PORTVERSION:S/.1$/-1/}

MAINTAINER=	mr@FreeBSD.org
COMMENT=	Professional CAD system

BUILD_DEPENDS=	qcad:${PORTSDIR}/cad/qcad

WRKSRC=		${WRKDIR}/partlibrary-${PORTVERSION:S/.1$/-1/}
DATADIR=	${PREFIX}/share/qcad/libraries

USE_X_PREFIX=	yes
USE_ZIP=	yes
USE_REINPLACE=	yes
NO_BUILD=	yes
PLIST=		${WRKDIR}/pkg-plist

.include <bsd.port.pre.mk>

pre-install:
	@${ECHO_CMD} '@exec mkdir -p %D/share/qcad/libraries' > ${PLIST}
	@${FIND} ${WRKSRC}/ -type f | \
		${SED} -e "s:^${WRKSRC}/:share/qcad/libraries/:g" >> ${PLIST}
	@${FIND} -d ${WRKSRC} -type d | \
		${SED} -e "s:^${WRKSRC}:@dirrm share/qcad/libraries:g" >> ${PLIST}

do-install:
	@${MKDIR} ${DATADIR}
	${TAR} -C ${WRKSRC} --exclude CVS -cf - . | \
		${TAR} -C ${DATADIR} --unlink -xf -

.include <bsd.port.post.mk>
