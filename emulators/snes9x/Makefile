# New ports collection makefile for:    snes9x
# Date created:         20 July 1997
# Whom:                 Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	snes9x
PORTVERSION=	1.41.1
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	http://www.lysator.liu.se/snes9x/
DISTNAME=	${PORTNAME}-${PORTVERSION:R}-${PORTVERSION:E}-src

MAINTAINER=	green@FreeBSD.org
COMMENT=	Super Nintendo Entertainment System(SNES) Emulator

PLIST_FILES=	bin/snes9x
WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USE_X_PREFIX=	YES
GNU_CONFIGURE=	YES
USE_GMAKE=	YES
MAKE_ARGS=	CC="${CC} ${CFLAGS}" CCC="${CXX} ${CXXFLAGS}" \
		INCLUDES="-I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDLIBS="-L${X11BASE}/lib ${PTHREAD_LIBS}" \

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=	--with-assembler
.if defined(WITH_MMX)
CONFIGURE_ARGS+=	--with-mmx
.endif
.endif

.if defined(WITH_OPENGL)
CONFIGURE_ARGS+=	--with-opengl
SNES9X_BIN=	osnes9x
.else
SNES9X_BIN=	snes9x
.endif

.if exists(/usr/lib/libusbhid.a)
CONFIGURE_ARGS+=	--with-joystick
.else
CONFIGURE_ARGS+=	--without-joystick
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${SNES9X_BIN} ${PREFIX}/bin

.include <bsd.port.post.mk>
