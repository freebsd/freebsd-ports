# New ports collection Makefile for: seaview
# Version required:     1.0
# Date created:         Dec 5 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $FreeBSD$
#

DISTNAME=       seaview
PKGNAME=        seaview-1.0
CATEGORIES=     biology
MASTER_SITES=   ftp://pbil.univ-lyon1.fr/pub/mol_phylogeny/seaview/
EXTRACT_SUFX=	.tar

MAINTAINER=     frankch@waru.life.nthu.edu.tw

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms

USE_X_PREFIX=	YES
NO_WRKSUBDIR=	YES
EXTRACT_CMD=		${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin
	@ (${MKDIR} ${PREFIX}/lib/X11/seaview)
	@ ${INSTALL_DATA} ${WRKSRC}/seaview.help ${PREFIX}/lib/X11/seaview

post-install:
	@ ${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
