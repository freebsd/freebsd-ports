# New ports collection makefile for:   ines
# Version required:    0.5
# Date created:        02 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1996/12/05 10:59:49 asami Exp $
#

DISTNAME=	NES
PKGNAME=        ines-0.5
CATEGORIES=     emulators
MASTER_SITES=	${MASTER_SITE_LOCAL}
DISTFILES=	iNES05-FreeBSD-80x86-bin.tar.Z

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_X11=	yes

do-build:

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ines ${PREFIX}/bin/ines
	${INSTALL_PROGRAM} ${WRKSRC}/dasm ${PREFIX}/bin/dasm
	@${MKDIR} ${PREFIX}/share/ines
	@${INSTALL_DATA} ${WRKSRC}/iNES.doc ${PREFIX}/share/ines

.include <bsd.port.mk>

