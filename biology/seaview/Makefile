# New ports collection Makefile for: seaview
# Version required:     1.0
# Date created:         Dec 5 1997
# Whom:                 frankch@waru.life.nthu.edu.tw
#
# $Id: Makefile,v 1.9 1998/09/26 23:18:03 steve Exp $
#

DISTNAME=       seaview
PKGNAME=        seaview-1.0
CATEGORIES=     biology
MASTER_SITES=   ftp://pbil.univ-lyon1.fr/pub/mol_phylogeny/seaview/
EXTRACT_SUFX=	.tar

MAINTAINER=     frankch@waru.life.nthu.edu.tw

BROKEN_ELF=	xforms is a.out only

LIB_DEPENDS=	xforms.0:${PORTSDIR}/x11-toolkits/xforms

USE_X_PREFIX=	YES
NO_WRKSUBDIR=	YES
EXTRACT_BEFORE_ARGS=	-xf

do-install:
	@ ${INSTALL_PROGRAM} ${WRKSRC}/${DISTNAME} ${PREFIX}/bin
	@ (${MKDIR} ${PREFIX}/lib/X11/seaview)
	@ ${INSTALL_DATA} ${WRKSRC}/seaview.help ${PREFIX}/lib/X11/seaview

post-install:
	@ ${CAT} ${PKGDIR}/DESCR

.include <bsd.port.mk>
