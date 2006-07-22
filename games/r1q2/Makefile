# New ports collection makefile for:	r1q2
# Date created:				16 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	r1q2
PORTVERSION=	6557
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	http://www.r1ch.net/stuff/r1q2/src/
DISTNAME=	${PORTNAME}-b${PORTVERSION}-src

PATCH_SITES=	${MASTER_SITE_LOCAL}
PATCH_SITE_SUBDIR=	alepulver
PATCHFILES=	r1q2_diff.gz
PATCH_DIST_STRIP=	-p1

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Enhaced Quake II client/server focusing on stability

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

USE_ZIP=	yes
USE_GCC=	3.2+
USE_GMAKE=	yes
NO_WRKSUBDIR=	yes

OPTIONS=	CLIENT "Build OpenGL client" on \
		DEDICATED "Build dedicated server" on \
		GAME "Build main game modification" on \
		GLX "Build OpenGL renderer" on \
		HTTP "Enable HTTP download support" on \
		OPENAL "Enable OpenAL support" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL client" on \
		SDLGL "Build SDL OpenGL renderer" on

ALL_TARGET=	release

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"

LIBDIR=		${PREFIX}/lib/${PORTNAME}

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_CLIENT) || !defined(WITHOUT_GLX)
USE_GL=		yes
.endif

.if !defined(WITHOUT_SDL) && !defined(WITHOUT_SDLGL)
USE_SDL=	sdl
.endif

.if !defined(WITHOUT_GLX) || !defined(WITHOUT_SDLGL)
LIB_DEPENDS+=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
.endif

.if !defined(WITHOUT_CLIENT)
MAKE_ENV+=	BUILD_CLIENT=YES
PLIST_SUB+=	CLIENT=""
R1Q2_BIN+=	r1q2
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if !defined(WITHOUT_DEDICATED)
MAKE_ENV+=	BUILD_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
R1Q2_BIN+=	r1q2ded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if !defined(WITHOUT_GAME)
MAKE_ENV+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if !defined(WITHOUT_GLX)
MAKE_ENV+=	BUILD_GLX=YES
PLIST_SUB+=	GLX=""
R1Q2_REF+=	r1gl
.else
PLIST_SUB+=	GLX="@comment "
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

.if !defined(WITHOUT_SDL)
MAKE_ENV+=	BUILD_SDL=YES
PLIST_SUB+=	SDL=""
R1Q2_BIN+=	r1q2-sdl
.else
PLIST_SUB+=	SDL="@comment "
.endif

.if !defined(WITHOUT_SDLGL)
MAKE_ENV+=	BUILD_SDLGL=YES
PLIST_SUB+=	SDLGL=""
R1Q2_REF+=	r1sdl
.else
PLIST_SUB+=	SDLGL="@comment "
.endif

.if ${OSVERSION} < 500000
post-patch:
	@${REINPLACE_CMD} -e 's|<stdint\.h>|<inttypes.h>|' \
		${WRKSRC}/game/q_shared.h
.endif

do-install:
.for f in ${R1Q2_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${f} ${PREFIX}/bin
.endfor
	${MKDIR} ${LIBDIR}/baseq2
.for f in ${R1Q2_REF}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/ref_${f}.so ${LIBDIR}
.endfor
.if !defined(WITHOUT_GAME)
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/baseq2/game.so ${LIBDIR}/baseq2
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${WRKSRC}/r1q2.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
