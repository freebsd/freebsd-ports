# New ports collection makefile for:	ufoai
# Date created:		2006-09-03
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ufoai
PORTVERSION=	2.1.1
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:S/$/-/}${PORTVERSION}-source_hotfix
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		${PORTNAME:S/$/-/}${PORTVERSION}-i18n${EXTRACT_SUFX}
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A strategy game featuring tactical combat

LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		openal:${PORTSDIR}/audio/openal \
		jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.5:${PORTSDIR}/graphics/png
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/default.cfg:${PORTSDIR}/games/ufoai-data

USE_BZIP2=	yes
USE_GCC=	3.4+
USE_GL=		yes
USE_SDL=	sdl ttf
USE_GETTEXT=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-release=yes \
			--with-snd-jack=no
CONFIGURE_ENV+=		CFLAGS="${CFLAGS} -I${LOCALBASE}/include -I${X11BASE}/include" \
			CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include ${PTHREAD_CFLAGS}" \
			LDFLAGS="-L${LOCALBASE}/lib -L${X11BASE}/lib ${PTHREAD_LIBS}"
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

DATADIR=	share/${PORTNAME}
SUB_FILES=	pkg-message
WRKSRC=		${WRKDIR}/${PORTNAME:S/$/-/}${PORTVERSION}-source
UFO_DIR=	${PREFIX}/lib/${PORTNAME}
UFO_LIBS=	ref_glx ref_sdl snd_sdl ref_glx snd_oss
UFO_FILES=	ufo

OPTIONS=		MASTER	"Install master server" off \
			SERVER	"Install dedicated server"	on \
			UFO2MAP	"Install UFO tools"	on \
			ARTS	"Support for arts sound system"	off \
			IPV6	"Support for ipv6"	off

.include <bsd.port.pre.mk>

.if defined(WITH_MASTER)
CONFIGURE_ARGS+=	--enable-master
UFO_FILES+=	ufomaster
PLIST_SUB+=	UFOMASTER=""
.else
CONFIGURE_ARGS+=	--disable-master
PLIST_SUB+=	UFOMASTER="@comment "
.endif

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

.if defined(WITH_ARTS)
CONFIGURE_ARGS+=	--with-snd-arts=yes
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
UFO_LIBS+=	snd_arts
PLIST_SUB+=	ARTS=""
.else
CONFIGURE_ARGS+=	--with-snd-arts=no
PLIST_SUB+=	ARTS="@comment "
.endif

.if defined(WITH_IPV6)
HAVE_IPV6=	true
CONFIGURE_ARGS+=	--with-ipv6=yes
.else
CONFIGURE_ARGS+=	--with-ipv6=no
.endif

post-patch:
	${REINPLACE_CMD} -e "s|<SDL.h>|<SDL/SDL.h>|g" ${WRKSRC}/src/ports/unix/cd_sdl.c

pre-install:
.	for FILE in ${UFO_FILES}
		@${ECHO} "#!/bin/sh" > ${WRKDIR}/${FILE}
		@${ECHO} "cd ${PREFIX}/${DATADIR} || exit 1 " >> ${WRKDIR}/${FILE}
		@${ECHO} "exec ${PREFIX}/${DATADIR}/${FILE} \"$$@\"" >> ${WRKDIR}/${FILE}
.	endfor

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
.	for FILE in ${UFO_LIBS}
		${INSTALL_PROGRAM} ${WRKSRC}/${FILE}.so ${UFO_DIR}
.	endfor
		${INSTALL_PROGRAM} ${WRKSRC}/base/game.so ${UFO_DIR}/base

	@cd ${WRKDIR}/base/i18n && \
		${FIND} * -type d -exec ${MKDIR} "${UFO_DIR}/base/i18n/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${UFO_DIR}/base/i18n/{}" \;
	${LN} -s ${PREFIX}/${DATADIR}/* ${UFO_DIR}/base

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
