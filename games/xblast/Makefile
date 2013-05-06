# Created by: se
# $FreeBSD$

PORTNAME=	xblast
PORTVERSION=	2.10.4
PORTREVISION=	10
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION} \
		SF/${PORTNAME}/Images/${IMAGES_DATE}:images \
		SF/${PORTNAME}/Levels/${LEVELS_DATE}:levels \
		SF/${PORTNAME}/Models/${MODELS_DATE}:models
.if !defined(WITHOUT_SOUND)
MASTER_SITES+=	SF/${PORTNAME}/Musics/${MUSICS_DATE}:musics \
		SF/${PORTNAME}/Sounds/${SOUNDS_DATE}:sounds
.else
PKGNAMESUFFIX=	-nosound
.endif
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		images-${IMAGES_DATE}${EXTRACT_SUFX}:images \
		levels-${LEVELS_DATE}${EXTRACT_SUFX}:levels \
		models-${MODELS_DATE}${EXTRACT_SUFX}:models
.if !defined(WITHOUT_SOUND)
DISTFILES+=	musics-${MUSICS_DATE}${EXTRACT_SUFX}:musics \
		sounds${EXTRACT_SUFX}:sounds
.endif
DIST_SUBDIR=	xblast

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-player real-time strategy game for X11

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

.if defined(WITHOUT_SOUND)
WITHOUT_SDL=	yes
.endif
.if !defined(WITHOUT_SDL)
WANT_SDL=	yes
.endif
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-admin
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"
MAKE_JOBS_SAFE=	yes

MAN6=		xblast.6

DATADIR=	${PREFIX}/share/XBlast-TNT

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

FONTSDIR=	${LOCALBASE}/lib/X11/fonts/bitstream-vera

IMAGES_DATE=	2005-01-06
LEVELS_DATE=	2005-01-06
MODELS_DATE=	2005-01-06
MUSICS_DATE=	2005-01-06
SOUNDS_DATE=	2004-04-29

.include <bsd.port.options.mk>
.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if defined(WITHOUT_SDL)
USE_XORG=	ice x11
CONFIGURE_ARGS+=	--disable-sdl
PLIST_SUB+=	NOSDL=""
.else
RUN_DEPENDS+=	${FONTSDIR}/Vera.ttf:${PORTSDIR}/x11-fonts/bitstream-vera
USE_SDL+=	gfx image mixer net ttf sdl
CONFIGURE_ARGS+=	--enable-sdl
PLIST_SUB+=	NOSDL="@comment "
.endif

.if defined(WITHOUT_SOUND)
CONFIGURE_ARGS+=	--disable-sound
PLIST_SUB+=	SOUND="@comment "
.else
CONFIGURE_ARGS+=	--enable-sound
PLIST_SUB+=	SOUND=""
.endif

.if defined(WITH_SMPF)
CONFIGURE_ARGS+=	--enable-SMPF
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|/games/|/|g ; \
		 /-ggdb/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|$$(game_datadir)/locale|$$(prefix)/share/locale|g ; \
		 s|^xblast_LDADD =.*$$|xblast_LDADD = $$(LIBINTL)|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e \
		's|"Vera.ttf"|"${FONTSDIR}/Vera.ttf"|g' ${WRKSRC}/sdl_text.c
	-@${MV} ${WRKDIR}/levels-${LEVELS_DATE}/reconstruct?on2.xal ${WRKDIR}/levels-${LEVELS_DATE}/reconstruction2.xal

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} xblast ${PREFIX}/bin/xblast
.if defined(WITHOUT_SDL) && !defined(WITHOUT_SOUND)
	cd ${WRKSRC} && ${INSTALL_PROGRAM} xbsndsrv ${PREFIX}/bin/xbsndsrv
.endif
	cd ${WRKSRC} && ${INSTALL_MAN} xblast.man ${MAN6PREFIX}/man/man6/xblast.6
.if ${PORT_OPTIONS:MNLS}
.for lang in de fr
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	cd ${WRKSRC}/po && ${INSTALL_DATA} ${lang}.gmo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/xblast.mo
.endfor
.endif
	@${MKDIR} ${DATADIR}/image
	@(${TAR} -C ${WRKDIR}/images-${IMAGES_DATE} --exclude "Imakefile" \
		-cf - . | ${TAR} -C ${DATADIR}/image --unlink -xf -)
	@${MKDIR} ${DATADIR}/level
	@(${TAR} -C ${WRKDIR}/levels-${LEVELS_DATE} --exclude "Imakefile" \
		-cf - . | ${TAR} -C ${DATADIR}/level --unlink -xf -)
	@${MKDIR} ${DATADIR}/image/sprite
	@(${TAR} -C ${WRKDIR}/models-${MODELS_DATE} --exclude "Imakefile" \
		-cf - . | ${TAR} -C ${DATADIR}/image/sprite --unlink -xf -)
.if !defined(WITHOUT_SOUND)
	@${MKDIR} ${DATADIR}/sounds
	@(${TAR} -C ${WRKDIR}/musics-${MUSICS_DATE} --exclude "Imakefile" \
		-cf - . | ${TAR} -C ${DATADIR}/sounds --unlink -xf -)
	@(${TAR} -C ${WRKDIR}/sounds --exclude "Imakefile" \
		-cf - . | ${TAR} -C ${DATADIR}/sounds --unlink -xf -)
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type d -exec ${CHMOD} 755 {} \;
	@${FIND} ${DATADIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \;

.include <bsd.port.mk>
