# New ports collection makefile for:	evq3
# Date created:				8 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	evq3
PORTVERSION=	1.0a
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	http://evolution.quakedev.com/dev/evq3/
DISTNAME=	${PORTNAME}-final-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pak-${PORTNAME}.pk3
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	The Marriage of XreaL and Icculus.org Q3 w/ Improvements

LIB_DEPENDS=	freetype.9:${PORTSDIR}/print/freetype2 \
		vorbis.4:${PORTSDIR}/audio/libvorbis

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GL=		yes
USE_XORG=	xxf86dga
USE_SCONS=	yes
SCONS_ARGS=	warnings=0
NO_WRKSUBDIR=	yes

OPTIONS=	GAMELIBS "Build game libraries (when not mandatory)" off \
		LUA "Enable Lua support (for scripting)" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Use SDL for audio instead of OSS" off \
		SIMD "Enable CPU optimizations (sse/3dnow)" on \
		SMP "Build with SMP (threading) support" off

CFLAGS+=	-DDATADIR='"\"${Q3DIR}\""' -DLIBDIR='"\"${LIBDIR}\""'

PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
VM_ARCHS=	i386 amd64 powerpc

.include "${.CURDIR}/../quake3-data/Makefile.include"

.include <bsd.port.pre.mk>

.for i in ${ARCH}
.   if ${VM_ARCHS:M${i}} != ""
HAVE_VM_COMPILED=	yes
.   endif
.endfor

.if defined(WITH_GAMELIBS) || !defined(HAVE_VM_COMPILED)
SCONS_ARGS+=	gamelibs=1
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

.if defined(WITH_LUA)
USE_LUA=	5.0
SCONS_ARGS+=	lua=1
CPPPATH=	${LOCALBASE}/include ${X11BASE}/include ${LUA_INCDIR}
LIBPATH=	${LOCALBASE}/lib ${X11BASE}/lib ${LUA_LIBDIR}
.endif

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
SCONS_ARGS+=	optimize=0
.endif

.if defined(WITH_SDL)
USE_SDL+=	sdl
SCONS_ARGS+=	sound=sdl
.else
SCONS_ARGS+=	sound=oss
.endif

.if !defined(WITHOUT_SIMD) && !defined(PACKAGE_BUILDING)
.if ${MACHINE_CPU:Msse} != ""
SCONS_ARGS+=	simd=sse
.elif ${MACHINE_CPU:M3dnow} != ""
SCONS_ARGS+=	simd=3dnow
.endif
.endif

.if defined(WITH_SMP)
SCONS_ARGS+=	smp=1
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|botlib\.log|/dev/null|' \
		${WRKSRC}/engine/botlib/be_interface.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quake3 ${PREFIX}/bin/${PORTNAME}
	${INSTALL_PROGRAM} ${WRKSRC}/quake3-server ${PREFIX}/bin/${PORTNAME}-server
	${MKDIR} ${LIBDIR}/baseq3
	${INSTALL_DATA} ${DISTDIR}/pak-evq3.pk3 ${LIBDIR}/baseq3
.if defined(WITH_GAMELIBS) || !defined(HAVE_VM_COMPILED)
	${INSTALL_PROGRAM} ${WRKSRC}/baseq3/*.so ${LIBDIR}/baseq3
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog.txt FEATURES.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
