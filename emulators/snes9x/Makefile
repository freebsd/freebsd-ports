# New ports collection makefile for:    snes9x
# Version required:	0.23
# Date created:         1 June 1997
# Whom:                 Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id$
#

DISTNAME=	snes9x_linux0.23
PKGNAME=	snes9x-0.23
CATEGORIES=	emulators
MASTER_SITES=	ftp://ftp.euro.net/pub/misc/Snes9X/

MAINTAINER=	Nakai@Mlab.t.u-tokyo.ac.jp

BUILD_DEPENDS=	/compat/linux/lib/ld.so:${PORTSDIR}/emulators/linux_lib
RUN_DEPENDS=    /compat/linux/lib/libc.so.5:${PORTSDIR}/emulators/linux_lib

NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_X11=	yes

STRIP=
BINOWN=		root
BINMODE=	4755

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin

.include <bsd.port.mk>
