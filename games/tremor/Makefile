# New ports collection makefile for:	tremor
# Date created:				15 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	tremor
PORTVERSION=	3.2.4.1
PORTREVISION=	5
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake1/:src \
		http://tremor.quakedev.com/:data
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${PORTNAME}_${PORTVERSION:S/.1//}-bin.zip:data
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Enhaced Quake engine based on JoeQuake

LIB_DEPENDS=	jpeg.10:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

USE_BZIP2=	yes
USE_GL=		gl glu
USE_XORG=	x11 xxf86dga
USE_GMAKE=	yes
ALL_TARGET=	release

OPTIONS=	GLX "Build OpenGL X11 client" on \
		GOODIES "Extra graphics, DM maps and models" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL client" on \
		TEXTURES "Collection of extra textures" off

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITHOUT_GLX) && defined(WITHOUT_SDL)
IGNORE=		needs at least one executable (GLX and SDL)
.endif

.if !defined(WITHOUT_GLX)
MAKE_ENV+=	BUILD_TREMOR=YES
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if defined(WITH_GOODIES)
DISTFILES+=	tremor_goodies.zip:data
PLIST_SUB+=	GOODIES=""
.else
PLIST_SUB+=	GOODIES="@comment "
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZE=YES
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
MAKE_ENV+=	BUILD_TREMOR_SDL=YES
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

.if defined(WITH_TEXTURES)
DISTFILES+=	tremor_texture_packX.zip:data
PLIST_SUB+=	TEXTURES=""
.else
PLIST_SUB+=	TEXTURES="@comment "
.endif

post-extract:
	@${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/tremor_3.2.4-bin.zip \
		base/*.cfg.bak base/tremor0.pak "base/textures/*" -d ${WRKDIR}
	@cd ${WRKDIR}/base && ${MV} config.cfg.bak config.cfg && \
		${MV} autoexec.cfg.bak autoexec.cfg
.if defined(WITH_GOODIES)
	@${UNZIP_CMD} -qL ${DISTDIR}/${DIST_SUBDIR}/tremor_goodies.zip \
		-d ${WRKDIR}
.endif
.if defined(WITH_TEXTURES)
	@${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/tremor_texture_packX.zip \
		-d ${WRKDIR}
.endif

do-install:
.if !defined(WITHOUT_GLX)
	${INSTALL_PROGRAM} ${WRKSRC}/quake/${PORTNAME}-glx ${PREFIX}/bin
.endif
.if !defined(WITHOUT_SDL)
	${INSTALL_PROGRAM} ${WRKSRC}/quake/${PORTNAME}-sdl ${PREFIX}/bin
.endif
	${MKDIR} ${Q1DIR}/${PORTNAME}
	${CP} -R ${WRKDIR}/base/* ${Q1DIR}/${PORTNAME}

.include <bsd.port.post.mk>
