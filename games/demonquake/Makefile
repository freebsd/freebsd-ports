# New ports collection makefile for:	demonquake
# Date created:				13 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	demonquake
PORTVERSION=	0.16.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake1/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		DemonQuake-data${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Another improved Quake engine based on FuhQuake

LIB_DEPENDS+=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png

USE_GMAKE=	yes
USE_DOS2UNIX=	yes
USE_GL=		gl
USE_XORG=	xpm xxf86dga
USE_BZIP2=	yes

OPTIONS=	GLX "Build OpenGL client" on \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL client" on

ALL_TARGET=	release

PLIST_FILES=	%%Q1DIR%%/${PORTNAME}/pak0.pak
PLIST_DIRS=	%%Q1DIR%%/${PORTNAME}

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GLX) && defined(WITHOUT_SDL)
IGNORE=		needs at least one binary (GLX and SDL)
.endif

.if !defined(WITHOUT_GLX)
MAKE_ENV+=	BUILD_DEMONQUAKE=YES
PLIST_FILES+=	bin/${PORTNAME}-glx
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZE=YES
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
MAKE_ENV+=	BUILD_DEMONQUAKE_SDL=YES
PLIST_FILES+=	bin/${PORTNAME}-sdl
.endif

post-patch:
	${REINPLACE_CMD} -e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		${WRKSRC}/gl_image.c

do-install:
.if !defined(WITHOUT_GLX)
	${INSTALL_PROGRAM} ${WRKSRC}/quake/${PORTNAME}-glx ${PREFIX}/bin
.endif
.if !defined(WITHOUT_SDL)
	${INSTALL_PROGRAM} ${WRKSRC}/quake/${PORTNAME}-sdl ${PREFIX}/bin
.endif
	${MKDIR} ${Q1DIR}/${PORTNAME}
	${INSTALL_DATA} ${WRKDIR}/DemonQuake-data/${PORTNAME}/pak0.pak \
		${Q1DIR}/${PORTNAME}

.include <bsd.port.post.mk>
