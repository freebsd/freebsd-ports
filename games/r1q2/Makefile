# New ports collection makefile for:	r1q2
# Date created:				16 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	r1q2
PORTVERSION=	6557
CATEGORIES=	games
MASTER_SITES=	http://www.r1ch.net/stuff/r1q2/src/
DISTNAME=	${PORTNAME}-b${PORTVERSION}-src

PATCH_SITES=	http://qudos.quakedev.com/linux/quake2/engines/R1Q2/
PATCHFILES=	r1q2_diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Enhaced Quake II client/server focusing on stability

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png

USE_ZIP=	yes
USE_GCC=	3.2+
USE_GMAKE=	yes
USE_GL=		yes
NO_WRKSUBDIR=	yes

OPTIONS=	DEDICATED "Build dedicated server" on \
		HTTP "Enable HTTP download support" on \
		OPENAL "Ebable OpenAL support" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL client" on \
		SDLGL "Build SDL OpenGL renderer" on

ALL_TARGET=	release

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	BUILD_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if !defined(WITHOUT_HTTP)
LIB_DEPENDS+=	curl.3:${PORTSDIR}/ftp/curl
MAKE_ENV+=	WITH_HTTP_DOWNLOAD_SUPPORT=YES
.endif

.if !defined(WITHOUT_OPENAL)
LIB_DEPENDS+=	openal.0:${PORTSDIR}/audio/openal
MAKE_ENV+=	WITH_OPENAL_SUPPORT=YES
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

.if !defined(WITHOUT_SDL) && !defined(WITHOUT_SDLGL)
USE_SDL=	sdl
.endif

.if !defined(WITHOUT_SDL)
MAKE_ENV+=	BUILD_SDL=YES
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

.if !defined(WITHOUT_SDLGL)
MAKE_ENV+=	BUILD_SDLGL=YES
PLIST_SUB+=	SDLGL=""
.else
PLIST_SUB+=	SDLGL="@comment "
.endif

.if ${OSVERSION} < 500000
post-patch:
	@${REINPLACE_CMD} -e 's|<stdint\.h>|<inttypes.h>|' \
		${WRKSRC}/game/q_shared.h
.endif

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${PORTNAME} ${PREFIX}/bin
.if !defined(WITHOUT_SDL)
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${PORTNAME}-sdl ${PREFIX}/bin
.endif
	${MKDIR} ${LIBDIR}/baseq2
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/ref_r1gl.so ${LIBDIR}
.if !defined(WITHOUT_SDLGL)
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/ref_r1sdl.so ${LIBDIR}
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/baseq2/game.so ${LIBDIR}/baseq2
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${WRKSRC}/r1q2.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
