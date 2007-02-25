# New ports collection makefile for:	evq3
# Date created:				8 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	evq3
PORTVERSION=	b2
CATEGORIES=	games
MASTER_SITES=	http://evolution.quakedev.com/files/Engine/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	The Marriage of XreaL and Icculus.org Q3 w/ Improvements

BUILD_DEPENDS=	zip:${PORTSDIR}/archivers/zip

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GCC=	3.4+
USE_GL=		yes
USE_SCONS=	yes
SCONS_ARGS=	warnings=0
REINPLACE_ARGS=	-i ''
NO_WRKSUBDIR=	yes

OPTIONS=	FREETYPE2 "Compile engine with FreeType 2.x support" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SIMD "Enable CPU optimizations (sse/3dnow)" on \
		SMP "Build with SMP (threading) support" off

CFLAGS+=	-I${X11BASE}/include -DPNG_NO_ASSEMBLER_CODE

PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
VM_ARCHS=	i386 amd64 powerpc

.include <bsd.port.pre.mk>

.for i in ${ARCH}
.   if ${VM_ARCHS:M${i}} != ""
HAVE_VM_COMPILED=	yes
.   endif
.endfor

.if !defined(HAVE_VM_COMPILED)
SCONS_ARGS+=	qvm=0
SUB_FILES+=	pkg-message
.endif

.if defined(WITH_FREETYPE2)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
SCONS_ARGS+=	freetype=1
.endif

.if defined(WITHOUT_OPTIMIZED_CFLAGS)
SCONS_ARGS+=	optimize=0
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
.for f in CC CCFLAGS X11BASE
	@${REINPLACE_CMD} -e 's|%%${f}%%|${${f}}|' ${WRKSRC}/SConstruct
.endfor
	@${REINPLACE_CMD} -e 's|%%X11BASE%%|${X11BASE}|' \
		${WRKSRC}/SConscript_evq3
.if defined(HAVE_VM_COMPILED) && ${ARCH} != "i386"
	@${REINPLACE_CMD} -e \
		's|vm_x86|vm_${ARCH:S/amd64/x86_64/:S/powerpc/ppc/}|' \
		 ${WRKSRC}/SConscript_evq3
.endif
	@${REINPLACE_CMD} -e 's|^#if defined( __FreeBSD__ ).*|#if 0|' \
		${WRKSRC}/engine/unix/linux_glimp.c
	@${REINPLACE_CMD} -e \
		's|%%DATADIR%%|${Q3DIR}|; s|%%LIBDIR%%|${LIBDIR}|' \
		 ${WRKSRC}/engine/common/fs.c ${WRKSRC}/engine/unix/unix_main.c
	@${REINPLACE_CMD} -e 's|botlib\.log|/dev/null|' \
		${WRKSRC}/engine/botlib/be_interface.c
	@${REINPLACE_CMD} -e 's|\.xreal|.${PORTNAME}|' \
		${WRKSRC}/engine/unix/unix_shared.c

# The .pk3 file (ZIP format) available in the web has wrong paths (everything
# is under a "baseq3" directory), so we have to create our own one.
post-build:
	@cd ${WRKSRC}/baseq3 && zip -r ../pak-evq3.pk3 *

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/build/unix/evq3 ${PREFIX}/bin
	${MKDIR} ${LIBDIR}/baseq3
	${INSTALL_DATA} ${WRKSRC}/pak-evq3.pk3 ${LIBDIR}/baseq3
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.if !defined(HAVE_VM_COMPILED)
post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.post.mk>
