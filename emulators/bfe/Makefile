# New ports collection makefile for:	bfe
# Version required:     991102
# Date created:		02 February 2000
# Whom:			jhb
#
# $FreeBSD$
#

DISTNAME=       bfe-${DATE}
CATEGORIES=     emulators
MASTER_SITES=	http://www.qzx.com/bfe/
EXTRACT_SUFX=	.tgz

MAINTAINER=	jhb@FreeBSD.org

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms
RUN_DEPENDS=	bochs:${PORTSDIR}/emulators/bochs

USE_X_PREFIX=	yes

DATE=		991102

WRKSRC=		${WRKDIR}/bfe

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bfe ${PREFIX}/bin
	-@${MKDIR} ${PREFIX}/share/bfe
	${INSTALL_DATA} ${WRKSRC}/.bferc ${PREFIX}/share/bfe/bferc.sample
	${INSTALL_DATA} ${WRKSRC}/README.bferc ${PREFIX}/share/bfe

.include <bsd.port.mk>
