# New ports collection makefile for:    snes9x
# Version required:     116a
# Date created:         20 July 1997
# Whom:                 Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $Id: Makefile,v 1.4 1999/01/07 02:31:40 simokawa Exp $
#

DISTNAME=	snes116a
PKGNAME=	snes9x-116a
CATEGORIES=	emulators
MASTER_SITES=	http://www.snes9x.com/zips/
EXTRACT_SUFX=	.zip

MAINTAINER=	Nacai@iname.com

BUILD_DEPENDS=	unzip:${PORTSDIR}/archivers/unzip
BUILD_DEPENDS+=	egcc:${PORTSDIR}/lang/pgcc
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm

ONLY_FOR_ARCHS=	i386

USE_GMAKE=	YES
USE_X_PREFIX=	YES
MAKEFILE=	Makefile.linux

EXTRACT_CMD=	unzip
EXTRACT_BEFORE_ARGS=

WRKSRC=		${WRKDIR}/release

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/s9xserver ${PREFIX}/bin

.include <bsd.port.mk>
