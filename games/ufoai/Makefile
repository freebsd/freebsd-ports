# Created by: Alonso Cardenas Marquez <acm@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ufoai
PORTVERSION=	2.5
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/UFO_AI%202.x/${PORTVERSION}
DISTNAME=	${PORTNAME:S/$/-/}${PORTVERSION}-source
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	m.tsatsenko@gmail.com
COMMENT=	Strategy game featuring tactical combat

LIB_DEPENDS=	libvorbis.so:audio/libvorbis \
		libpng.so:graphics/png \
		libcurl.so:ftp/curl \
		libtheora.so:multimedia/libtheora \
		libxvidcore.so:multimedia/xvid \
		libmxml.so:textproc/mxml
BUILD_DEPENDS=	zip:archivers/zip
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/base/default.cfg:games/ufoai-data

ALL_TARGET=	all lang
USE_GL=		yes
USE_SDL=	sdl image mixer ttf
USE_CXXSTD=	c++11
USES=		compiler:c++11-lang gettext gmake jpeg openal:soft pkgconfig \
		python:build tar:bzip2
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-release --target-os=freebsd
LDFLAGS+=	-lpthread -lexecinfo

DATADIR=	share/${PORTNAME}
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME:S/$/-/}${PORTVERSION}-source
UFO_DIR=	${PREFIX}/lib/${PORTNAME}
UFO_FILES=	ufo ufomodel

OPTIONS_DEFINE=		SERVER UFO2MAP UFORADIANT
OPTIONS_DEFAULT=	SERVER UFO2MAP

SERVER_DESC=		Install dedicated server
UFO2MAP_DESC=		Install UFO tools
UFORADIANT_DESC=	Install UFO map editor

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MSERVER}
CONFIGURE_ARGS+=	--enable-ufoded
UFO_FILES+=	ufoded
PLIST_SUB+=	UFOSERVER=""
.else
CONFIGURE_ARGS+=	--disable-ufoded
PLIST_SUB+=	UFOSERVER="@comment "
.endif

.if ${PORT_OPTIONS:MUFO2MAP}
CONFIGURE_ARGS+=	--enable-ufo2map
UFO_FILES+=	ufo2map
PLIST_SUB+=	UFO2MAP=""
.else
CONFIGURE_ARGS+=	--disable-ufo2map
PLIST_SUB+=	UFO2MAP="@comment "
.endif

.if ${PORT_OPTIONS:MUFORADIANT}
ALL_TARGET+=	uforadiant
CONFIGURE_ARGS+=--enable-uforadiant
USE_GNOME+=	gtk20 glib20 gtksourceview2 libxml2
LIB_DEPENDS+=	libgtkglext-x11-1.0.so:x11-toolkits/gtkglext
RADIANT_FILES=	colours.xml game.xml input.xml mapdef.template menu.xml user.xml
RADIANT_DIRS=	bitmaps i18n prefabs sourceviewer
PLIST_SUB+=	UFORADIANT=""
.else
CONFIGURE_ARGS+=--disable-uforadiant
PLIST_SUB+=	UFORADIANT="@comment "
.endif

.include <bsd.port.pre.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/base/maps ${WRKSRC}/base/models
	${REINPLACE_CMD} \
		-e 's|DEFAULT_COMPILER_CC=cc|DEFAULT_COMPILER_CC=${CC}|' \
		-e 's|DEFAULT_COMPILER_CXX=c++|DEFAULT_COMPILER_CXX=${CXX}|' \
		${WRKSRC}/configure
.if ${CHOSEN_COMPILER_TYPE} == "clang"
	${REINPLACE_CMD} \
		-e 's|-falign-loops=2 -falign-jumps=2 -falign-functions=2||' \
		${WRKSRC}/build/modes/release.mk
.endif

do-install:
	${MKDIR} ${STAGEDIR}${UFO_DIR}
.for FILE in ${UFO_FILES}
	@${SED} \
		-e 's|@UFODIR@|${UFO_DIR}|' \
		-e 's|@APP@|${FILE}|' \
		${FILESDIR}/run.sh.in > ${WRKDIR}/${FILE}
	${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${STAGEDIR}${UFO_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${FILE} ${STAGEDIR}${PREFIX}/bin
.endfor
	${MKDIR} ${STAGEDIR}${PREFIX}/${DATADIR}/base
	${INSTALL_PROGRAM} ${WRKSRC}/base/game.so ${STAGEDIR}${PREFIX}/${DATADIR}/base

.if ${PORT_OPTIONS:MUFORADIANT}
	${MKDIR} ${STAGEDIR}${UFO_DIR}/radiant
	@${SED} \
		-e 's|@UFODIR@|${UFO_DIR}/radiant|' \
		-e 's|@APP@|uforadiant|' \
		${FILESDIR}/run.sh.in > ${WRKDIR}/uforadiant
	${INSTALL_PROGRAM} ${WRKSRC}/radiant/uforadiant ${STAGEDIR}${UFO_DIR}/radiant
	${INSTALL_SCRIPT} ${WRKDIR}/uforadiant ${STAGEDIR}${PREFIX}/bin

.for FILE in ${RADIANT_FILES}
	${INSTALL_DATA} ${WRKSRC}/radiant/${FILE} ${STAGEDIR}${UFO_DIR}/radiant
.endfor

.for DIRE in ${RADIANT_DIRS}
	${MKDIR} ${STAGEDIR}${UFO_DIR}/radiant/${DIRE}
	cd ${WRKSRC}/radiant/${DIRE} && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${UFO_DIR}/radiant/${DIRE}/{}" \; && \
		${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${UFO_DIR}/radiant/${DIRE}/{}" \;
.endfor
.endif

	cd ${WRKSRC}/base/i18n && \
		${FIND} * -type d -exec ${MKDIR} "${STAGEDIR}${PREFIX}/${DATADIR}/base/i18n/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} {} "${STAGEDIR}${PREFIX}/${DATADIR}/base/i18n/{}" \;
	${LN} -s ${PREFIX}/${DATADIR}/base ${STAGEDIR}${UFO_DIR}/base

.include <bsd.port.post.mk>
