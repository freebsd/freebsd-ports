# New ports collection makefile for:   ines
# Version required:    0.5
# Date created:        02 November 1996
# Whom:                Yukihiro Nakai <Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	NES
PKGNAME=        ines-0.5
CATEGORIES=     emulators
MASTER_SITES=   ftp://freefall.freebsd.org/pub/FreeBSD/LOCAL_PORTS/
DISTFILES=	iNES05-FreeBSD-80x86-bin.tar.Z

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

USE_X11=	yes

do-build:

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/ines ${PREFIX}/bin/ines
	${INSTALL_PROGRAM} ${WRKSRC}/dasm ${PREFIX}/bin/dasm
	@mkdir ${PREFIX}/share/ines
	@cp ${WRKSRC}/iNES.doc ${PREFIX}/share/ines

.include <bsd.port.mk>

