# New ports collection makefile for:    snes9x
# Version required:     118e
# Date created:         20 July 1997
# Whom:                 Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.8 1999/03/31 14:01:18 flathill Exp $
#

DISTNAME=	snes118e
PKGNAME=	snes9x-118e
CATEGORIES=	emulators
MASTER_SITES=	http://www.snes9x.com/zips/

MAINTAINER=	nacai@iname.com

BUILD_DEPENDS=	egcc:${PORTSDIR}/lang/pgcc
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	YES
USE_X_PREFIX=	YES
MAKEFILE=	Makefile.linux
ALL_TARGET=	snes9x s9xserver

USE_ZIP=	yes

WRKSRC=		${WRKDIR}/release

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/s9xserver ${PREFIX}/bin

.include <bsd.port.mk>
