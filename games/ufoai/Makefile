# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>

PORTNAME=	ufoai
PORTVERSION=	2.5
PORTREVISION=	11
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/UFO_AI%202.x/${PORTVERSION}
DISTNAME=	${PORTNAME:S/$/-/}${PORTVERSION}-source
DIST_SUBDIR=	${PORTNAME}

PATCH_SITES=	https://github.com/ufoai/ufoai/commit/
PATCHFILES=	163073ab9527cdaa33d77a713b8e46ff462a2b5c.patch:-p1

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Strategy game featuring tactical combat

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libpng.so:graphics/png \
		libcurl.so:ftp/curl \
		libtheora.so:multimedia/libtheora \
		libxvidcore.so:multimedia/xvid \
		libmxml.so:textproc/mxml \
		libogg.so:audio/libogg
BUILD_DEPENDS=	zip:archivers/zip
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/base/default.cfg:games/ufoai-data

USES=		compiler:c++11-lang gettext gl gmake jpeg localbase openal:soft \
		pkgconfig python:build sdl tar:bzip2
USE_GL=		gl
USE_SDL=	sdl image mixer ttf
USE_CXXSTD=	c++11
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-release --target-os=freebsd
ALL_TARGET=	all lang
LDFLAGS+=	-lpthread -lexecinfo
LDFLAGS_i386=	-Wl,-z,notext

DATADIR=	share/${PORTNAME}
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME:S/$/-/}${PORTVERSION}-source
UFO_DIR=	${PREFIX}/lib/${PORTNAME}
UFO_FILES=	ufo ufomodel

OPTIONS_DEFINE=		SERVER UFO2MAP UFORADIANT
OPTIONS_DEFAULT=	SERVER UFO2MAP
OPTIONS_SUB=		yes

SERVER_DESC=		Install dedicated server
UFO2MAP_DESC=		Install UFO tools
UFORADIANT_DESC=	Install UFO map editor

SERVER_CONFIGURE_ENABLE=ufoded
SERVER_VARS=		UFO_FILES+=ufoded

UFO2MAP_CONFIGURE_ENABLE=ufo2map
UFO2MAP_VARS=		UFO_FILES+=ufo2map

UFORADIANT_ALL_TARGET=	uforadiant
UFORADIANT_CONFIGURE_ENABLE=uforadiant
UFORADIANT_USES=	gnome
UFORADIANT_USE=		GNOME=gtk20,glib20,gtksourceview2,libxml2
UFORADIANT_LIB_DEPENDS=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext

.include <bsd.port.pre.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/base/maps ${WRKSRC}/base/models
	@${REINPLACE_CMD} \
		-e 's|DEFAULT_COMPILER_CC=cc|DEFAULT_COMPILER_CC=${CC}|' \
		-e 's|DEFAULT_COMPILER_CXX=c++|DEFAULT_COMPILER_CXX=${CXX}|' \
		${WRKSRC}/configure
.if ${CHOSEN_COMPILER_TYPE} == "clang"
	@${REINPLACE_CMD} \
		-e 's|-falign-loops=2 -falign-jumps=2 -falign-functions=2||' \
		${WRKSRC}/build/modes/release.mk
.endif
.for LIB in SDL SDL_mixer SDL_ttf curl intl jpeg mxml ogg png theora vorbis zlib
	@${RM} -rf ${WRKSRC}/src/libs/${LIB}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${UFO_DIR}
.for FILE in ${UFO_FILES}
	@${SED} \
		-e 's|@UFODIR@|${UFO_DIR}|' \
		-e 's|@APP@|${FILE}|' \
		${FILESDIR}/run.sh.in > ${WRKDIR}/${FILE}
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${STAGEDIR}${UFO_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${FILE} ${STAGEDIR}${PREFIX}/bin
.endfor
	@${MKDIR} ${STAGEDIR}${PREFIX}/${DATADIR}/base
	${INSTALL_PROGRAM} ${WRKSRC}/base/game.so ${STAGEDIR}${PREFIX}/${DATADIR}/base

	@cd ${WRKSRC}/base/i18n && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/${DATADIR}/base/i18n/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${PREFIX}/${DATADIR}/base/i18n/{}" \;
	${LN} -s ../../${DATADIR}/base ${STAGEDIR}${UFO_DIR}/base

do-install-UFORADIANT-on:
	@${MKDIR} ${STAGEDIR}${UFO_DIR}/radiant
	@${SED} \
		-e 's|@UFODIR@|${UFO_DIR}/radiant|' \
		-e 's|@APP@|uforadiant|' \
		${FILESDIR}/run.sh.in > ${WRKDIR}/uforadiant
	${INSTALL_PROGRAM} ${WRKSRC}/radiant/uforadiant ${STAGEDIR}${UFO_DIR}/radiant
	${INSTALL_SCRIPT} ${WRKDIR}/uforadiant ${STAGEDIR}${PREFIX}/bin
	@cd ${WRKSRC}/radiant && ${COPYTREE_SHARE} . ${STAGEDIR}${UFO_DIR}/radiant

.include <bsd.port.post.mk>
