# New ports collection makefile for:	quake3
# Date created:				23 August 2005
# Whom:					pypt
#
# $FreeBSD$
#

PORTNAME=	quake3
PORTVERSION=	1.32b
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://www.proarena.com/p/ftpx/x8524/quake_3_arena/ \
		http://www.planetgargoyle.com/ \
		http://www.teamdarkside.net/ \
		http://0day.icculus.org/mirrors/quake3/ \
		http://www.olpainless.net/files/ \
		${MASTER_SITE_IDSOFTWARE:S|$|source/|}
DISTFILES=	${DISTNAME}-source${EXTRACT_SUFX}

MAINTAINER=	shirshegsm@gmail.com
COMMENT=	Quake III Arena -- first person shooter (native build)

USE_ZIP=	yes
USE_DOS2UNIX=	yes
USE_GMAKE=	yes
USE_GCC=	3.2+
BUILD_WRKSRC=	${WRKSRC}/code/unix

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		GAMELIBS "Build game libraries (mandatory on !i386)" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SMP "Build SMP (threaded) client" on

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITHOUT_CLIENT) && defined(WITHOUT_DEDICATED) \
    && defined(WITHOUT_SMP)
IGNORE=		needs at least one of CLIENT, DEDICATED and SMP options
.endif

.if ${ARCH} == "i386"
BUILD_DEPENDS=	nasm:${PORTSDIR}/devel/nasm
.endif

.if !defined(WITHOUT_CLIENT) && !defined(WITHOUT_SMP)
USE_GL=		yes
.endif

.if !defined(WITHOUT_CLIENT)
MAKE_ENV+=	CLIENT=YES
PLIST_SUB+=	CLIENT=""
Q3BIN+=		quake3
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
Q3BIN+=		q3ded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAMELIBS) || ${ARCH} != "i386"
MAKE_ENV+=	GAMELIBS=YES
PLIST_SUB+=	GAMELIBS=""
.else
PLIST_SUB+=	GAMELIBS="@comment "
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

.if !defined(WITHOUT_SMP)
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
		${WRKSRC}/code/qcommon/common.c \
		${WRKSRC}/code/renderer/tr_init.c

do-install:
.for bin in ${Q3BIN}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${bin} ${PREFIX}/bin
.endfor
.if defined(WITH_GAMELIBS) || ${ARCH} != "i386"
.for dir in baseq3 missionpack
	${MKDIR} ${LIBDIR}/${dir}
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/release/${dir}/*.so ${LIBDIR}/${dir}
.endfor
.endif

.include "${.CURDIR}/../quake3-data/Makefile.include"
.include <bsd.port.post.mk>
