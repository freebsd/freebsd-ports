# New ports collection makefile for:	ines
# Version required:	0.7
# Date created:		02 November 1996
# Whom:			Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.4 1997/06/07 19:23:12 max Exp $
#

DISTNAME=	iNES07-FreeBSD-80x86-bin
PKGNAME=        ines-0.7
CATEGORIES=     emulators
MASTER_SITES=   http://freeflight.com/fms/iNES/
EXTRACT_SUFX=	.tar.Z

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

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
