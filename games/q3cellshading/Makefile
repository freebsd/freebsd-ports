PORTNAME=	q3cellshading
PORTVERSION=	1.0
PORTREVISION=	4
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	q3cel-${PORTVERSION}-src

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Quake III engine with Cell Shading capabilities
WWW=		https://q3cellshading.sourceforge.net/

ONLY_FOR_ARCHS=	i386
ONLY_FOR_ARCHS_REASON=	does not run properly; try games/ioquake3 with option

USES=		gmake zip

MAKE_ENV=	LIBDIR="${LIBDIR}"
MAKE_JOBS_UNSAFE=	yes

BUILD_WRKSRC=	${WRKSRC}/code/unix
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

VM_ARCHS=	i386 powerpc

OPTIONS_DEFINE=	GAMELIBS OPTIMIZED_CFLAGS
OPTIONS_DEFAULT=	CLIENT DEDICATED OPTIMIZED_CFLAGS SMP_CLIENT
OPTIONS_MULTI=	FLAVOR
OPTIONS_MULTI_FLAVOR=	CLIENT DEDICATED SMP_CLIENT
OPTIONS_SUB=	yes

CLIENT_DESC=		Build client
DEDICATED_DESC=		Build dedicated server
GAMELIBS_DESC=		Force building game libraries
SMP_CLIENT_DESC=	Build SMP (threaded) client

CLIENT_MAKE_ENV=	CLIENT=YES
CLIENT_VARS=	Q3BIN+=quake3
DEDICATED_MAKE_ENV=	DEDICATED=YES
DEDICATED_VARS=	Q3BIN+=q3ded
OPTIMIZED_CFLAGS_MAKE_ENV=	OPTIMIZED_CFLAGS=YES
SMP_CLIENT_MAKE_ENV=	SMP=YES
SMP_CLIENT_VARS=	Q3BIN+=quake3-smp

LIBDIR=		${PREFIX}/lib/${PORTNAME}

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
USE_XORG=	xxf86dga xxf86vm
.endif

.if ${PORT_OPTIONS:MGAMELIBS} || !defined(HAVE_VM_COMPILED)
MAKE_ENV+=	GAMELIBS=YES
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
.include <bsd.port.mk>

PATCH_ARGS+=	-l
