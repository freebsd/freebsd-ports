# New ports collection makefile for:   ines
# Version required:    0.6
# Date created:        02 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.3 1997/04/30 03:17:58 asami Exp $
#

DISTNAME=	iNES06-FreeBSD-80x86-bin
PKGNAME=        ines-0.6
CATEGORIES=     emulators
MASTER_SITES=   http://freeflight.com/fms/iNES/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

EXTRACT_SUFX=	.tar.Z
WRKSRC=		${WRKDIR}/NES
USE_X11=	yes
NO_BUILD=	yes

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ines ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/ines-debug ${PREFIX}/bin
	@${MKDIR} ${PREFIX}/share/ines
	@${INSTALL_DATA} ${WRKSRC}/iNES.doc ${PREFIX}/share/ines
	@${INSTALL_DATA} ${WRKSRC}/headers.tgz ${PREFIX}/share/ines
	@${INSTALL_DATA} ${WRKSRC}/CART.* ${PREFIX}/share/ines

.include <bsd.port.mk>

