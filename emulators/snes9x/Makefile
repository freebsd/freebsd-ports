# New ports collection makefile for:    snes9x
# Version required:	1.05
# Date created:         20 July 1997
# Whom:                 Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.2 1998/07/27 01:00:43 steve Exp $
#

DISTNAME=	s9x.linux.105.i386
PKGNAME=	snes9x-1.05
CATEGORIES=	emulators
MASTER_SITES=	http://www.snes9x.com/zips/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

BUILD_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_lib
RUN_DEPENDS=    /compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_X_PREFIX=	yes

STRIP=
BINOWN=		root
BINMODE=	755

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin

.include <bsd.port.mk>
