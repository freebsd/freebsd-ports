# Created by: pypt
# $FreeBSD$

PORTNAME=	quake3
PORTVERSION=	1.32c
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	ftp://mancubus.net/pub/idgames/idstuff/source/ \
		http://ftp.mancubus.net/pub/idgames/idstuff/source/ \
		http://www.gamers.org/pub/idgames/idstuff/source/ \
		IDSOFTWARE/source/
DISTNAME=	${PORTNAME}-${REALVERSION}-source

MAINTAINER=	shirshegsm@gmail.com
COMMENT=	Quake III Arena -- first person shooter (native build)

USES=		dos2unix gmake zip
ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	does not run properly; try games/ioquake3
WRKSRC=		${WRKDIR}/${PORTNAME}-${REALVERSION}
BUILD_WRKSRC=	${WRKSRC}/code/unix
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	GAMELIBS OPTIMIZED_CFLAGS
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT DEDICATED THREADS
FLAVOR_DESC=	Executable Selection
CLIENT_DESC=	Build client
DEDICATED_DESC=	Build dedicated server
GAMELIBS_DESC=	Build game libraries (when not mandatory)

OPTIONS_DEFAULT=	CLIENT DEDICATED OPTIMIZED_CFLAGS THREADS

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}
REALVERSION=	1.32b
VM_ARCHS=	i386 powerpc

.include <bsd.port.options.mk>

.if ${ARCH} == "i386"
BUILD_DEPENDS+=	nasm:devel/nasm
.endif

.for i in ${ARCH}
.   if ${VM_ARCHS:M${i}} != ""
HAVE_VM_COMPILED=	yes
.   endif
.endfor

.if !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	DLL_ONLY=true
.endif

.if ${PORT_OPTIONS:MCLIENT} || ${PORT_OPTIONS:MTHREADS}
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

.if ${PORT_OPTIONS:MTHREADS}
MAKE_ENV+=	SMP=YES
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
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${bin} ${STAGEDIR}${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
.for dir in baseq3 missionpack
	${MKDIR} ${STAGEDIR}${LIBDIR}/${dir}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${dir}/*.so ${STAGEDIR}${LIBDIR}/${dir}
.endfor
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.mk>
