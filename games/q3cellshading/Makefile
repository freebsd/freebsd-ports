# Created by: Alejandro Pulver <alepulver@FreeBSD.org>
# $FreeBSD$

PORTNAME=	q3cellshading
PORTVERSION=	1.0
PORTREVISION=	3
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	q3cel-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III engine with Cell Shading capabilities

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	does not run properly; try games/ioquake3 with option

USES=		compiler dos2unix gmake zip
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/code/unix
MAKE_JOBS_UNSAFE=	yes

LIBDIR=		${PREFIX}/lib/${PORTNAME}
MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

VM_ARCHS=	i386 powerpc

OPTIONS_DEFINE=	GAMELIBS OPTIMIZED_CFLAGS
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT DEDICATED SMP_CLIENT
OPTIONS_DEFAULT=	CLIENT DEDICATED OPTIMIZED_CFLAGS SMP_CLIENT
OPTIONS_SUB=	yes

CLIENT_DESC=		Build client
DEDICATED_DESC=		Build dedicated server
GAMELIBS_DESC=		Force building game libraries
SMP_CLIENT_DESC=	Build SMP (threaded) client

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:devel/nasm
.endif

.for arch in ${ARCH}
.  if ${VM_ARCHS:M${arch}} != ""
HAVE_VM_COMPILED=	yes
.  endif
.endfor

.if !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	DLL_ONLY=true
.endif

.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MSMP_CLIENT}
USES+=		gl xorg
USE_GL=		glu
USE_XORG=	xxf86dga
.endif

.if ${PORT_OPTIONS:MCLIENT}
MAKE_ENV+=	CLIENT=YES
Q3BIN+=		quake3
.endif

.if ${PORT_OPTIONS:MDEDICATED}
MAKE_ENV+=	DEDICATED=YES
Q3BIN+=		q3ded
.endif

.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	GAMELIBS=YES
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

.if ${PORT_OPTIONS:MSMP_CLIENT}
MAKE_ENV+=	SMP=YES
Q3BIN+=		quake3-smp
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|botlib\.log|/dev/null|' \
		${WRKSRC}/code/botlib/be_interface.c
	@${REINPLACE_CMD} -e \
		's|//[[:blank:]]*\(Swap_Init[[:blank:]]*();\)|\1|' \
		${WRKSRC}/code/botlib/be_interface.c \
		${WRKSRC}/code/renderer/tr_init.c
.if ${COMPILER_TYPE} == clang
	@${REINPLACE_CMD} -E 's,-falign-(jumps|loops)=2,,g; s|-O6||' \
		${WRKSRC}/code/unix/Makefile
.endif

do-install:
.for bin in ${Q3BIN}
# Adjust program names to avoid conflicts with other Quake3 ports
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${bin} \
		${STAGEDIR}${PREFIX}/bin/${bin:C/(quake3|q3)/\1cel/}
.endfor
.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
.for dir in baseq3 missionpack
	@${MKDIR} ${STAGEDIR}${LIBDIR}/${dir}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${dir}/*.so \
		${STAGEDIR}${LIBDIR}/${dir}
.endfor
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.post.mk>
