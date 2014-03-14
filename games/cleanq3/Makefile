# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	cleanq3
PORTVERSION=	0.5.2
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	http://www.bfeared.com/library/quake/archive/quakedev/temor/downloads/
DISTNAME=	CleanQ3_v${PORTVERSION}-srcbin

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Cleaned up copy of the original Quake III Arena source code

USES=		dos2unix gmake zip
WRKSRC=		${WRKDIR}/CleanQ3
BUILD_WRKSRC=	${WRKSRC}/code/unix
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	GAMELIBS OPTIMIZED_CFLAGS
OPTIONS_MULTI=	TYPE
OPTIONS_MULTI_TYPE=	CLIENT SMP_CLIENT DEDICATED
OPTIONS_DEFAULT=	CLIENT SMP_CLIENT DEDICATED OPTIMIZED_CFLAGS

CLIENT_DESC=		Build client
SMP_CLIENT_DESC=	Build SMP (threaded) client
DEDICATED_DESC=		Build dedicated server
GAMELIBS_DESC=		Build game libraries (when not mandatory)

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
VM_ARCHS=	i386

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.endif

.for i in ${ARCH}
.   if ${VM_ARCHS:M${i}} != ""
HAVE_VM_COMPILED=	yes
.   endif
.endfor

.if !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	DLL_ONLY=true
.endif

.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MSMP_CLIENT}
USE_GL=		yes
USE_XORG=	xxf86dga
.endif

.if ${PORT_OPTIONS:MCLIENT}
MAKE_ENV+=	CLIENT=YES
PLIST_SUB+=	CLIENT=""
Q3BIN+=		cleanq3
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MSMP_CLIENT}
MAKE_ENV+=	SMP=YES PTHREAD_LIBS="${PTHREAD_LIBS}"
PLIST_SUB+=	SMP_CLIENT=""
Q3BIN+=		cleanq3-smp
.else
PLIST_SUB+=	SMP_CLIENT="@comment "
.endif

.if ${PORT_OPTIONS:MDEDICATED}
MAKE_ENV+=	DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
Q3BIN+=		cleanq3ded
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

post-patch:
	@${REINPLACE_CMD} -e 's|botlib\.log|/dev/null|' \
		${WRKSRC}/code/botlib/be_interface.c
	@${REINPLACE_CMD} -e \
		's|//[[:blank:]]*\(Swap_Init[[:blank:]]*();\)|\1|' \
		${WRKSRC}/code/botlib/be_interface.c \
		${WRKSRC}/code/renderer/tr_init.c

do-install:
.for bin in ${Q3BIN}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${bin} ${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
.for dir in baseq3 missionpack
	@${MKDIR} ${LIBDIR}/${dir}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${dir}/*.so ${LIBDIR}/${dir}
.endfor
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.mk>
