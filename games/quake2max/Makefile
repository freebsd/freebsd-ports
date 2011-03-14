# New ports collection makefile for:	quake2max
# Date created:				24 Jul 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	quake2max
PORTVERSION=	0.45
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake2/engines/Quake2MaX/:src \
		${MASTER_SITE_LOCAL:S/$/:data/}
MASTER_SITE_SUBDIR=	alepulver/:data
DISTNAME=	Quake2maX_${PORTVERSION}-src_unix
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${Q2MAX_DATA}:data
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	An OpenGL only Quake II engine modification

EXTRACT_DEPENDS=unrar:${PORTSDIR}/archivers/unrar

USE_BZIP2=	yes
USE_GMAKE=	yes
USE_XORG=	xxf86dga
ALL_TARGET=	release
WRKSRC=		${WRKDIR}/${DISTNAME:S/quake2max/Quake2maX/}

OPTIONS=	CLIENT "Build client" on \
		DEDICATED "Build dedicated server" on \
		GAME "Build a main game .so file" off \
		GLX "Build OpenGL renderer" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL client" on \
		SDLGL "Build SDL OpenGL renderer" on

MAKE_ENV=	LIBDIR="${LIBDIR}"
PLIST_SUB=	LIBDIR="${LIBDIR:S/${PREFIX}\///}"
LIBDIR=		${PREFIX}/lib/${PORTNAME}

Q2MAX_DATA=	${PORTNAME}.044.rar

.include "${.CURDIR}/../quake2-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_GLX) || defined(WITH_SDLGL)
LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png
USE_GL=		yes
.endif

.if defined(WITH_SDL) || defined(WITH_SDLGL)
USE_SDL=	yes
.endif

.if defined(WITH_CLIENT)
MAKE_ENV+=	BUILD_QUAKE2MAX=YES
PLIST_SUB+=	CLIENT=""
Q2MAX_BIN+=	quake2max
.else
PLIST_SUB+=	CLIENT="@comment "
.endif

.if defined(WITH_DEDICATED)
MAKE_ENV+=	BUILD_DEDICATED=YES
PLIST_SUB+=	DEDICATED=""
Q2MAX_BIN+=	quake2max-ded
.else
PLIST_SUB+=	DEDICATED="@comment "
.endif

.if defined(WITH_GAME)
MAKE_ENV+=	BUILD_GAME=YES
PLIST_SUB+=	GAME=""
.else
PLIST_SUB+=	GAME="@comment "
.endif

.if defined(WITH_GLX)
MAKE_ENV+=	BUILD_GLX=YES
PLIST_SUB+=	GLX=""
Q2MAX_REF+=	glx
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if defined(WITH_OPTIMIZED_CFLAGS)
MAKE_ENV+=	WITH_OPTIMIZED_CFLAGS=YES
.endif

.if defined(WITH_SDL)
MAKE_ENV+=	BUILD_QUAKE2MAX-SDL=YES
PLIST_SUB+=	SDL=""
Q2MAX_BIN+=	quake2max-sdl
.else
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_SDLGL)
MAKE_ENV+=	BUILD_SDLGL=YES
PLIST_SUB+=	SDLGL=""
Q2MAX_REF+=	sdlgl
.else
PLIST_SUB+=	SDLGL="@comment "
.endif

post-extract:
	@cd ${WRKSRC} && unrar e ${DISTDIR}/${Q2MAX_DATA} baseq2/_maxpak.pak

post-patch:
# Resolve name collision with jpeg-8
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		${WRKSRC}/ref_gl/gl_image.c

do-install:
	${MKDIR} ${LIBDIR}/baseq2
.for f in ${Q2MAX_BIN}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/${f} ${PREFIX}/bin
.endfor
.for f in ${Q2MAX_REF}
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/rfx_${f}.so ${LIBDIR}
.endfor
.if defined(WITH_GAME)
	${INSTALL_PROGRAM} ${WRKSRC}/quake2/baseq2/game.so ${LIBDIR}/baseq2
.endif
	${INSTALL_DATA} ${WRKSRC}/_maxpak.pak ${LIBDIR}/baseq2/maxpak.pak

.include <bsd.port.post.mk>
