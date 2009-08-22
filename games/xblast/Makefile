# New ports collection makefile for:    xblast
# Date created:         Sat Nov 08 09:47:12 CET 1997
# Whom:                 se
#
# $FreeBSD$
#

PORTNAME=	xblast
PORTVERSION=	2.10.4
PORTREVISION=	2
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${IMAGES_DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${LEVELS_DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${MODELS_DISTNAME}${EXTRACT_SUFX}
.if !defined(WITHOUT_SOUND)
DISTFILES+=	${MUSICS_DISTNAME}${EXTRACT_SUFX}
DISTFILES+=	${SOUNDS_DISTNAME}${EXTRACT_SUFX}
.endif
DIST_SUBDIR=	xblast

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-player real-time strategy game for X11

WANT_SDL=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=	--enable-admin
MAKE_ARGS=	ACLOCAL="${TRUE}" AUTOCONF="${TRUE}" AUTOHEADER="${TRUE}" \
		AUTOMAKE="${TRUE}"

MAN6=		xblast.6

DATADIR=	${PREFIX}/share/XBlast-TNT

CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib

FONTSDIR=	${LOCALBASE}/lib/X11/fonts/bitstream-vera

IMAGES_DISTNAME=images-2005-01-06
LEVELS_DISTNAME=levels-2005-01-06
MODELS_DISTNAME=models-2005-01-06
MUSICS_DISTNAME=musics-2005-01-06
SOUNDS_DISTNAME=sounds

.if defined(WITHOUT_NLS)
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.else
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
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

.if defined(WITHOUT_SOUND) && defined(WITHOUT_SDL)
PKGNAMESUFFIX=	-nosound
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

do-install:
	cd ${WRKSRC} && ${INSTALL_PROGRAM} xblast ${PREFIX}/bin/xblast
.if defined(WITHOUT_SDL) && !defined(WITHOUT_SOUND)
	cd ${WRKSRC} && ${INSTALL_PROGRAM} xbsndsrv ${PREFIX}/bin/xbsndsrv
.endif
	cd ${WRKSRC} && ${INSTALL_MAN} xblast.man ${MAN6PREFIX}/man/man6/xblast.6
.if !defined(WITHOUT_NLS)
.for lang in de fr
	@${MKDIR} ${PREFIX}/share/locale/${lang}/LC_MESSAGES
	cd ${WRKSRC}/po && ${INSTALL_DATA} ${lang}.gmo \
		${PREFIX}/share/locale/${lang}/LC_MESSAGES/xblast.mo
.endfor
.endif
	@${MKDIR} ${DATADIR}/image
	@(${TAR} -C ${WRKDIR}/${IMAGES_DISTNAME} --exclude "Imakefile" \
		-cf - . | ${TAR} -C ${DATADIR}/image --unlink -xf -)
	@${MKDIR} ${DATADIR}/level
	@(${TAR} -C ${WRKDIR}/${LEVELS_DISTNAME} --exclude "Imakefile" \
		-cf - . | ${TAR} -C ${DATADIR}/level --unlink -xf -)
	@${MKDIR} ${DATADIR}/image/sprite
	@(${TAR} -C ${WRKDIR}/${MODELS_DISTNAME} --exclude "Imakefile" \
		-cf - . | ${TAR} -C ${DATADIR}/image/sprite --unlink -xf -)
.if !defined(WITHOUT_SOUND)
	@${MKDIR} ${DATADIR}/sounds
	@(${TAR} -C ${WRKDIR}/${MUSICS_DISTNAME} --exclude "Imakefile" \
		-cf - . | ${TAR} -C ${DATADIR}/sounds --unlink -xf -)
	@(${TAR} -C ${WRKDIR}/${SOUNDS_DISTNAME} --exclude "Imakefile" \
		-cf - . | ${TAR} -C ${DATADIR}/sounds --unlink -xf -)
.endif
	@${CHOWN} -R ${SHAREOWN}:${SHAREGRP} ${DATADIR}
	@${FIND} ${DATADIR} -type d -exec ${CHMOD} 755 {} \;
	@${FIND} ${DATADIR} -type f -exec ${CHMOD} ${SHAREMODE} {} \; 

.include <bsd.port.mk>
