# New ports collection makefile for:	tremor
# Date created:				15 May 2006
# Whom:					alepulver
#
# $FreeBSD$
#

PORTNAME=	tremor
PORTVERSION=	3.2.4
CATEGORIES=	games
MASTER_SITES=	http://qudos.quakedev.com/linux/quake1/:src \
		http://tremor.quakedev.com/:data
DISTFILES=	Tremor-v${PORTVERSION}-bin-src.linux.tar.bz2:src \
		tremor_3.2.4-bin.zip:data
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=	Tremor-v${PORTVERSION}-bin-src.linux.tar.bz2

MAINTAINER=	alepulver@FreeBSD.org
COMMENT=	Enhaced Quake engine based on JoeQuake

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
EXTRACT_DEPENDS=unzip:${PORTSDIR}/archivers/unzip

USE_BZIP2=	yes
USE_GCC=	3.2+
USE_GL=		yes
USE_GMAKE=	yes

OPTIONS=	GOODIES "Extra graphics, DM maps and models" off \
		OPTIMIZED_CFLAGS "Enable compilation optimizations" on \
		SDL "Build SDL client" on \
		TEXTURES "Collection of extra textures" off \
		X86_ASM "Enable x86 assembly code when possible" on

WRKSRC=		${WRKDIR}/Tremor_${PORTVERSION}-bin-src.linux
ALL_TARGET=	release

.include "${.CURDIR}/../quake-data/Makefile.include"

.include <bsd.port.pre.mk>

.if defined(WITH_GOODIES)
DISTFILES+=	tremor_goodies.zip:data
PLIST_SUB+=	GOODIES=""
.else
PLIST_SUB+=	GOODIES="@comment "
.endif

.if !defined(WITHOUT_OPTIMIZED_CFLAGS)
MAKE_ENV+=	OPTIMIZED_CFLAGS=YES
.endif

.if !defined(WITHOUT_SDL)
USE_SDL=	sdl
MAKE_ENV+=	BUILD_SDL=YES
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

.if !defined(WITHOUT_X86_ASM)
MAKE_ENV+=	X86_ASM=YES
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
	${INSTALL_PROGRAM} ${WRKSRC}/release/${PORTNAME} ${PREFIX}/bin
.if !defined(WITHOUT_SDL)
	${INSTALL_PROGRAM} ${WRKSRC}/release/${PORTNAME}-sdl ${PREFIX}/bin
.endif
	${MKDIR} ${Q1DIR}/${PORTNAME}
	${CP} -R ${WRKDIR}/base/* ${Q1DIR}/${PORTNAME}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/tremor.txt ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
