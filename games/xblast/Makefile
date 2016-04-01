# Created by: se
# $FreeBSD$

PORTNAME=	xblast
PORTVERSION=	2.10.4
PORTREVISION=	16
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Sources/${PORTVERSION} \
		SF/${PORTNAME}/Images/${IMAGES_DATE}:images \
		SF/${PORTNAME}/Levels/${LEVELS_DATE}:levels \
		SF/${PORTNAME}/Models/${MODELS_DATE}:models \
		SF/${PORTNAME}/Musics/${MUSICS_DATE}:musics \
		SF/${PORTNAME}/Sounds/${SOUNDS_DATE}:sounds
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		images-${IMAGES_DATE}${EXTRACT_SUFX}:images \
		levels-${LEVELS_DATE}${EXTRACT_SUFX}:levels \
		models-${MODELS_DATE}${EXTRACT_SUFX}:models
DIST_SUBDIR=	xblast

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-player real-time strategy game for X11

LICENSE=	GPLv2 GPLv3
LICENSE_COMB=	dual

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-otherdatadir=${DATADIR}

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

FONTSDIR=	${LOCALBASE}/share/fonts/bitstream-vera

IMAGES_DATE=	2005-01-06
LEVELS_DATE=	2005-01-06
MODELS_DATE=	2005-01-06
MUSICS_DATE=	2005-01-06
SOUNDS_DATE=	2004-04-29

OPTIONS_DEFINE=	NLS SDL SMPF SOUND
OPTIONS_DEFAULT=SDL SOUND
OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls
SDL_USE=		SDL=gfx,image,mixer,net,ttf,sdl
SDL_CONFIGURE_ENABLE=	sdl
SDL_RUN_DEPENDS=	${FONTSDIR}/Vera.ttf:x11-fonts/bitstream-vera
SMPF_DESC=		Support for 16 players
SMPF_CONFIGURE_ENABLE=	SMPF
SOUND_CONFIGURE_ENABLE=	sound
SOUND_DISTFILES=	musics-${MUSICS_DATE}${EXTRACT_SUFX}:musics \
			sounds${EXTRACT_SUFX}:sounds

.include <bsd.port.options.mk>

.if ! ${PORT_OPTIONS:MSDL}
USE_XORG=	ice x11
.endif

post-extract:
	-@${MV} ${WRKDIR}/levels-${LEVELS_DATE}/reconstruct?on2.xal ${WRKDIR}/levels-${LEVELS_DATE}/reconstruction2.xal

post-patch:
	@${TOUCH} -r ${WRKSRC}/configure ${WRKSRC}/aclocal.m4
	@${REINPLACE_CMD} -e \
		's|$$(game_datadir)/locale|$$(prefix)/share/locale|g ; \
		 s|^xblast_LDADD =.*$$|xblast_LDADD = $$(LIBINTL)|g' \
		${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} '/datadir=$$game_datadir/d' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|"Vera.ttf"|"${FONTSDIR}/Vera.ttf"|g' ${WRKSRC}/sdl_text.c

post-install:
	${INSTALL_MAN} ${WRKSRC}/xblast.man ${STAGEDIR}${MAN6PREFIX}/man/man6/xblast.6
	${MKDIR} ${STAGEDIR}${DATADIR}/image
	cd ${WRKDIR}/images-${IMAGES_DATE} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/image "-not -name Imakefile"
	${MKDIR} ${STAGEDIR}${DATADIR}/level
	cd ${WRKDIR}/levels-${LEVELS_DATE} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/level "-not -name Imakefile"
	${MKDIR} ${STAGEDIR}${DATADIR}/image/sprite
	cd ${WRKDIR}/models-${MODELS_DATE} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/image/sprite "-not -name Imakefile"
.if ${PORT_OPTIONS:MSOUND}
	${MKDIR} ${STAGEDIR}${DATADIR}/sounds
	cd ${WRKDIR}/musics-${MUSICS_DATE} && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/sounds "-not -name Imakefile"
	cd ${WRKDIR}/sounds && \
		${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/sounds "-not -name Imakefile"
.endif

.include <bsd.port.mk>
