# New ports collection makefile for:	tremor
# Date created:				15 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	tremor
PORTVERSION=	3.2.4.1
PORTREVISION=	9
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake1/:src \
		http://tremor.quakedev.com/:data
DISTNAME=	${PORTNAME}-${PORTVERSION}-src
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}:src \
		${PORTNAME}_${PORTVERSION:S/.1//}-bin.zip:data
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enhanced Quake engine based on JoeQuake

LIB_DEPENDS=	jpeg.11:${PORTSDIR}/graphics/jpeg \
		png15:${PORTSDIR}/graphics/png
EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

USE_BZIP2=	yes
USE_GL=		gl glu
USE_XORG=	x11 xxf86dga
USE_GMAKE=	yes
ALL_TARGET=	release

OPTIONS_MULTI=	OUTPUT
OPTIONS_MULTI_OUTPUT=	OPENGL SDL
OPTIONS_DEFINE=	GOODIES	OPTIMIZED_CFLAGS TEXTURES
OPTIONS_DEFAULT=	OPENGL OPTIMIZED_CFLAGS
GOODIES_DESC=	Extra graphics, DM maps and models
TEXTURES_DESC=	Collection of extra textures

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MOPENGL}
MAKE_ENV+=	BUILD_TREMOR=YES
PLIST_SUB+=	GLX=""
.else
PLIST_SUB+=	GLX="@comment "
.endif

.if ${PORT_OPTIONS:MGOODIES}
DISTFILES+=	tremor_goodies.zip:data
PLIST_SUB+=	GOODIES=""
.else
PLIST_SUB+=	GOODIES="@comment "
.endif

.if ${PORT_OPTIONS:MOPTIMIZED_CFLAGS}
MAKE_ENV+=	OPTIMIZE=YES
.endif

.if ${PORT_OPTIONS:MSDL}
USE_SDL=	sdl
MAKE_ENV+=	BUILD_TREMOR_SDL=YES
PLIST_SUB+=	SDL=""
.else
PLIST_SUB+=	SDL="@comment "
.endif

.if ${PORT_OPTIONS:MTEXTURES}
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
.if ${PORT_OPTIONS:MGOODIES}
	@${UNZIP_CMD} -qL ${DISTDIR}/${DIST_SUBDIR}/tremor_goodies.zip \
		-d ${WRKDIR}
.endif
.if ${PORT_OPTIONS:MTEXTURES}
	@${UNZIP_CMD} -q ${DISTDIR}/${DIST_SUBDIR}/tremor_texture_packX.zip \
		-d ${WRKDIR}
.endif

do-install:
.if ${PORT_OPTIONS:MOPENGL}
	${INSTALL_PROGRAM} ${WRKSRC}/quake/${PORTNAME}-glx ${PREFIX}/bin
.endif
.if ${PORT_OPTIONS:MSDL}
	${INSTALL_PROGRAM} ${WRKSRC}/quake/${PORTNAME}-sdl ${PREFIX}/bin
.endif
	${MKDIR} ${Q1DIR}/${PORTNAME}
	${CP} -R ${WRKDIR}/base/* ${Q1DIR}/${PORTNAME}

.include <bsd.port.mk>
