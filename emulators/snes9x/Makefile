# New ports collection makefile for:    snes9x
# Date created:         20 July 1997
# Whom:                 Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	snes9x
PORTVERSION=	1.37c
CATEGORIES=	emulators
MASTER_SITES=	http://www.snes9x.com/zips/
DISTNAME=	s9xs137c

MAINTAINER=	green@FreeBSD.org

.if ${MACHINE_ARCH} == i386
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.elif ${MACHINE_ARCH} == alpha
MAKEFILE=	Makefile.alpha
FORBIDDEN=	currently does not work on alpha
.endif

USE_GMAKE=	YES
USE_X_PREFIX=	YES
MAKE_ENV=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}"
USE_ZIP=	YES
WRKSRC=		${WRKDIR}/release

.if exists(/usr/lib/libusb.a)
MAKE_ENV+=	USB_JOYSTICK_SUPPORT=yes
.endif

ONLY_FOR_ARCHS=	i386 alpha

.if ${MACHINE_ARCH} == alpha
post-patch:
	@${SED} -e '/^ZSNESFX/d' \
	    -e '/^ASMCPU/d' \
	    -e '/^OPTIMISE/s/-mpentium //' \
	    -e '/^-Ii386/d' \
	    -e '/offsets >/s:i386/::' \
	    < ${WRKSRC}/Makefile \
	    > ${WRKSRC}/Makefile.alpha
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin

.include <bsd.port.mk>
