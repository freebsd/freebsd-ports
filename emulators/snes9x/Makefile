# New ports collection makefile for:    snes9x
# Date created:         20 July 1997
# Whom:                 Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	snes9x
PORTVERSION=	1.42
CATEGORIES=	emulators
MASTER_SITES=	http://www.lysator.liu.se/snes9x/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	green@FreeBSD.org
COMMENT=	Super Nintendo Entertainment System(SNES) Emulator

WRKSRC=		${WRKDIR}/${DISTNAME}/${PORTNAME}

USE_X_PREFIX=	YES
USE_GMAKE=	YES
GNU_CONFIGURE=	YES
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
MAKE_ARGS=	INCLUDES="-I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDLIBS="-L${X11BASE}/lib ${PTHREAD_LIBS}" \
		OPTIMISE="${CXXFLAGS}"

PLIST_FILES=	bin/${SNES9X_BIN}

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386" && !defined(WITHOUT_X86_ASM)
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
CONFIGURE_ARGS+=	--with-assembler
.if defined(WITH_MMX)
CONFIGURE_ARGS+=	--with-mmx
.endif
.else
CONFIGURE_ARGS+=	--without-assembler
.endif

.if defined(WITH_OPENGL)
USE_GL=		yes
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
