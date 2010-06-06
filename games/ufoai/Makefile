# New ports collection makefile for:	ufoai
# Date created:		2006-09-03
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ufoai
PORTVERSION=	2.2.1
PORTREVISION=	8
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/UFO_AI%202.x/${PORTVERSION}
DISTNAME=	${PORTNAME:S/$/-/}${PORTVERSION}-source
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A strategy game featuring tactical combat

LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		jpeg.11:${PORTSDIR}/graphics/jpeg \
		png.6:${PORTSDIR}/graphics/png \
		curl:${PORTSDIR}/ftp/curl

RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/default.cfg:${PORTSDIR}/games/ufoai-data

USE_BZIP2=	yes
USE_GL=		yes
USE_SDL=	sdl mixer ttf
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-release=yes
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include" \
			CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}" \
			LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

DATADIR=	share/${PORTNAME}
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME:S/$/-/}${PORTVERSION}-source
UFO_DIR=	${PREFIX}/lib/${PORTNAME}
UFO_FILES=	ufo

OPTIONS=		SERVER	"Install dedicated server"	on \
			UFO2MAP	"Install UFO tools"	on \

.include <bsd.port.pre.mk>

.if !defined(WITHOUT_SERVER)
CONFIGURE_ARGS+=	--enable-dedicated
UFO_FILES+=	ufoded
PLIST_SUB+=	UFOSERVER=""
.else
CONFIGURE_ARGS+=	--disable-dedicated
PLIST_SUB+=	UFOSERVER="@comment "
.endif

.if !defined(WITHOUT_UFO2MAP)
CONFIGURE_ARGS+=	--enable-ufo2map
UFO_FILES+=	ufo2map
PLIST_SUB+=	UFO2MAP=""
.else
CONFIGURE_ARGS+=	--disable-ufo2map
PLIST_SUB+=	UFO2MAP="@comment "
.endif

# Resolve name collision with jpeg-8 amd API png
post-patch:
	${REINPLACE_CMD} -e 's|jpeg_mem_src|local_jpeg_mem_src|' \
		-e 's|png_set_gray_1_2_4_to_8|png_set_expand_gray_1_2_4_to_8|' \
		-e 's|png_check_sig(PngFileBuffer.buffer, 8)|!png_sig_cmp(PngFileBuffer.buffer, 0, 8)|' \
		${WRKSRC}/src/renderer/r_image.c \
		${WRKSRC}/src/tools/ufo2map/common/imagelib.c

pre-install:
.	for FILE in ${UFO_FILES}
		@${ECHO} "#!/bin/sh" > ${WRKDIR}/${FILE}
		@${ECHO} "cd ${PREFIX}/${DATADIR} || exit 1 " >> ${WRKDIR}/${FILE}
		@${ECHO} "exec ${PREFIX}/${DATADIR}/${FILE} \"$$@\"" >> ${WRKDIR}/${FILE}
.	endfor

post-build:
	@cd ${WRKSRC} && ${GMAKE} lang

do-install:
	@${MKDIR} ${UFO_DIR}/base/i18n
.	for FILE in ${UFO_FILES}
	@${SED} \
		-e 's|@UFODIR@|${UFO_DIR}|' \
		-e 's|@APP@|${FILE}|' \
		${FILESDIR}/run.sh.in > ${WRKDIR}/${FILE}
		${INSTALL_PROGRAM} ${WRKSRC}/${FILE} ${UFO_DIR}
		${INSTALL_SCRIPT} ${WRKDIR}/${FILE} ${PREFIX}/bin
.	endfor

		${INSTALL_PROGRAM} ${WRKSRC}/base/game.so ${UFO_DIR}/base

	@cd ${WRKSRC}/base/i18n && \
		${FIND} * -type d -exec ${MKDIR} "${UFO_DIR}/base/i18n/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${UFO_DIR}/base/i18n/{}" \;
	${LN} -s ${PREFIX}/${DATADIR}/* ${UFO_DIR}/base

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
