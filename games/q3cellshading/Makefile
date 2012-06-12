# New ports collection makefile for:	q3cellshading
# Date created:				8 Aug 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	q3cellshading
PORTVERSION=	1.0
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	q3cel-${PORTVERSION}-src

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Quake III engine with Cell Shading capabilities

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	does not run properly; try games/ioquake3 with option
USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/code/unix

OPTIONS_MULTI=	EXE
OPTIONS_MULTI_EXE=	CLIENT DEDICATED SMP
OPTIONS_DEFINE=	GAMELIBS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	CLIETN DEDICATED OPTIMIZED_CFLAGS SMP
CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server
GAMELIBS_DESC=	Build game libraries (when not mandatory)
SMP_DESC=	Build SMP (threaded) client

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
VM_ARCHS=	i386 powerpc

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:${PORTSDIR}/devel/nasm
.endif

.for i in ${ARCH}
.   if ${VM_ARCHS:M${i}} != ""
HAVE_VM_COMPILED=	yes
.   endif
.endfor

.if !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	DLL_ONLY=true
.endif

.if ${PORT_OPTIONS:MCLIENT} || !empty(PORT_OPTIONS:MSMP)
USE_GL=		yes
USE_XORG=	xxf86dga
.endif

.if ${PORT_OPTIONS:MCLIENT}
MAKE_ENV+=	CLIENT=YES
PLIST_SUB+=	CLIENT=""
Q3BIN+=		quake3
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
MAKE_ENV+=	DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
Q3BIN+=		q3ded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	GAMELIBS=YES
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

.if ${PORT_OPTIONS:MSMP}
MAKE_ENV+=	SMP=YES \
		PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB+=	SMP=""
Q3BIN+=		quake3-smp
.else
PLIST_SUB+=	SMP="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|botlib\.log|/dev/null|' \
		${WRKSRC}/code/botlib/be_interface.c
	@${REINPLACE_CMD} -e \
		's|//[[:blank:]]*\(Swap_Init[[:blank:]]*();\)|\1|' \
		${WRKSRC}/code/botlib/be_interface.c \
		${WRKSRC}/code/renderer/tr_init.c

do-install:
.for bin in ${Q3BIN}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${bin} \
		${PREFIX}/bin/${bin:C/(quake3|q3)/\1cel/}
.endfor
.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
.for dir in baseq3 missionpack
	${MKDIR} ${LIBDIR}/${dir}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${dir}/*.so ${LIBDIR}/${dir}
.endfor
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.post.mk>
