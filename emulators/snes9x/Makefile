# New ports collection makefile for:    snes9x
# Date created:         20 July 1997
# Whom:                 Yukihiro Nakai<Nakai@Mlab.t.u-tokyo.ac.jp>
#
# $FreeBSD$
#

PORTNAME=	snes9x
PORTVERSION=	1.40
CATEGORIES=	emulators
MASTER_SITES=	http://www.lysator.liu.se/snes9x/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src-2

MAINTAINER=	green@FreeBSD.org
COMMENT=	Super Nintendo Entertainment System(SNES) Emulator

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}-src/snes9x

USE_X_PREFIX=	YES
USE_GMAKE=	YES
MAKE_ARGS=	CC="${CC} ${CFLAGS}" CCC="${CXX} ${CXXFLAGS}" \
		INCLUDES="-I${X11BASE}/include ${PTHREAD_CFLAGS}" \
		LDLIBS="-L${X11BASE}/lib ${PTHREAD_LIBS}" \
		THREAD_SOUND=1 NETPLAY=1 UNZIP=1

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
MAKE_ARGS+=	ZSNESFX=1 ZSNESC4=1 ASMCPU=1 NASM="nasm" I386SPC="i386/SPC.O"
.if defined(WITH_MMX)
MAKE_ARGS+=	ASMKREED=1
.endif
.endif

.if exists(/usr/lib/libusbhid.a)
JOYDEFINES=	-DJOYSTICK_SUPPORT
SYSLIBS=	-lusbhid
.endif

do-configure:
	@cd ${WRKSRC} && ${SED} \
		's:@ZSNESFX@:: ; \
		 s:@ZSNESC4@::g ; \
		 s:@ASMCPU@::g ; \
		 s:@SPC700ASM@::g ; \
		 s:@GLIDE@::g ; \
		 s:@OPENGL@::g ; \
		 s:@AIDO@::g ; \
		 s:@THREAD_SOUND@::g ; \
		 s:@ASMKREED@::g ; \
		 s:@I386SPC@:$${I386SPC}:g ; \
		 s:@JOYDEFINES@:${JOYDEFINES}:g ; \
		 s:@CXX@::g ; \
		 s:@RTTIFLAG@::g ; \
		 s:@CC@::g ; \
		 s:@NASM@::g ; \
		 s:@XINCLUDES@::g ; \
		 s:@OPTIMIZE@::g ; \
		 s:@CPUINC@::g ; \
		 s:@SYSDEFINES@:-DZLIB:g ; \
		 s:@SYSLIBS@:${SYSLIBS}:g ; \
		 s: -lpthread::g ; \
		 s: \.\./zlib/libz\.a::g' < Makefile.in > Makefile

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/snes9x ${PREFIX}/bin

.include <bsd.port.post.mk>
