# New ports collection makefile for:    snes9x
# Date created:         20 July 1997
# Whom:                 Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	snes9x
PORTVERSION=	1.41
CATEGORIES=	emulators
MASTER_SITES=	http://www.lysator.liu.se/snes9x/
DISTNAME=	${PORTNAME}-${PORTVERSION}-1-src

MAINTAINER=	green@FreeBSD.org
COMMENT=	Super Nintendo Entertainment System(SNES) Emulator

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-1-src/snes9x

USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKE_ARGS=	CC="${CC} ${CFLAGS}" CCC="${CXX} ${CXXFLAGS}" \
		INCLUDES="-I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDLIBS="-L${X11BASE}/lib ${PTHREAD_LIBS}" \

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=	--with-assembler
.if defined(WITH_MMX)
CONFIGURE_ARGS+=	--with-mmx
.endif
.endif

.if exists(/usr/lib/libusbhid.a)
CONFIGURE_ARGS+=	--with-joystick
.else
CONFIGURE_ARGS+=	--without-joystick
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin

.include <bsd.port.post.mk>
