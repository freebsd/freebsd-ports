# New ports collection makefile for:    snes9x
# Version required:     119a
# Date created:         20 July 1997
# Whom:                 Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

DISTNAME=	s9xs125
PKGNAME=	snes9x-1.25
CATEGORIES=	emulators
MASTER_SITES=	http://www.snes9x.com/zips/

MAINTAINER=	nacai@iname.com

.if ${MACHINE_ARCH} == i386
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.elif ${MACHINE_ARCH} == alpha
MAKEFILE=	Makefile.alpha
.endif

USE_GMAKE=	YES
USE_X_PREFIX=	YES
MAKE_ENV=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}"
USE_ZIP=	YES
WRKSRC=		${WRKDIR}/release

ONLY_FOR_ARCHS=	i386 alpha

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/s9xserver ${PREFIX}/bin

.include <bsd.port.mk>
