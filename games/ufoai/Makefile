# New ports collection makefile for:	ufoai
# Date created:		2006-09-03
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ufoai
DISTVERSION=	2.0RC5
CATEGORIES=	games
MASTER_SITES=	SF
DISTNAME=	${PORTNAME:S/$/-/}${DISTVERSION:S/R/-R/}-source
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	acm@FreeBSD.org
COMMENT=	A strategy game featuring tactical combat

LIB_DEPENDS=	vorbis:${PORTSDIR}/audio/libvorbis \
		jpeg.9:${PORTSDIR}/graphics/jpeg
RUN_DEPENDS=	${LOCALBASE}/share/${PORTNAME}/default.cfg:${PORTSDIR}/games/ufoai-data

USE_BZIP2=	yes
USE_GL=		yes
USE_SDL=	sdl ttf
USE_GETTEXT=	yes
USE_GMAKE=	yes

DATADIR=	share/${PORTNAME}
UFO_DIR=	${PREFIX}/lib/${PORTNAME}
UFO_LIBS=	ref_glx ref_sdl snd_sdl ref_glx snd_oss game
UFO_FILES=	ufo

OPTIONS=		SERVER	"Install dedicated server"	on \
			UFO2MAP	"Install UFO tools"	on \
			ARTS	"Support for arts sound system"	off \
			IPV6	"Support for ipv6"	off

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 500000
IGNORE=		does not build on FreeBSD 4.x
.endif

.if !defined(WITHOUT_SERVER)
HAVE_SERVER=	true
MAKE_ENV+=	BUILD_DEDICATED="YES"
UFO_FILES+=	ufoded
PLIST_SUB+=	SERVER=""
.else
MAKE_ENV+=	BUILD_DEDICATED="NO"
PLIST_SUB+=	SERVER="@comment "
.endif

.if !defined(WITHOUT_UFO2MAP)
HAVE_UFO2MAP=	true
MAKE_ENV+=	BUILD_COMPILETOOLS="YES"
UFO_FILES+=	ufo2map
PLIST_SUB+=	UFO2MAP=""
.else
MAKE_ENV+=	BUILD_COMPILETOOLS="NO"
PLIST_SUB+=	UFO2MAP="@comment "
.endif

.if defined(WITH_ARTS)
HAVE_ARTS=	true
LIB_DEPENDS+=	artsc.0:${PORTSDIR}/audio/arts
MAKE_ENV+=	BUILD_ARTS="YES"
.else
MAKE_ENV+=	BUILD_ARTS="NO"
.endif

.if defined(WITH_IPV6)
HAVE_IPV6=	true
MAKE_ENV+=	HAVE_IPV6="YES"
.else
MAKE_ENV+=	HAVE_IPV6="NO"
.endif

post-patch:
	${REINPLACE_CMD} -e "s|^BUILD_ARTS=|BUILD_ARTS?=|g" -e \
		"s|^BUILD_DEDICATED=|BUILD_DEDICATED?=|g" -e \
		"s|^BUILD_COMPILETOOLS=|BUILD_COMPILETOOLS?=|g" -e \
		"s|^HAVE_IPV6=|HAVE_IPV6?=|g" ${WRKSRC}/Makefile

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
		${INSTALL_PROGRAM} ${WRKSRC}/release${ARCH}/${FILE} ${UFO_DIR}
		${INSTALL_SCRIPT} ${WRKDIR}/${FILE} ${PREFIX}/bin
.	endfor
.	for FILE in ${UFO_LIBS}
		${INSTALL_PROGRAM} ${WRKSRC}/release${ARCH}/${FILE}.so ${UFO_DIR}
.	endfor

	@cd ${WRKSRC}/base/i18n && \
		${FIND} * -type d -exec ${MKDIR} "${UFO_DIR}/base/i18n/{}" \; && \
			${FIND} * -type f -exec ${INSTALL_DATA} "{}" "${UFO_DIR}/base/i18n/{}" \;
	${LN} -s ${PREFIX}/${DATADIR}/* ${UFO_DIR}/base

.include <bsd.port.post.mk>
