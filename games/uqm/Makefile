PORTNAME=	uqm
DISTVERSION=	0.8.0
CATEGORIES=	games
MASTER_SITES=	SF/sc2/UQM/${DISTVERSION:R}
DISTFILES=	${DISTNAME}-src.tgz ${DISTNAME}-content.uqm
EXTRACT_ONLY=	${DISTNAME}-src.tgz

MAINTAINER=	mail@maxlor.com
COMMENT=	Space exploration game The Ur-Quan Masters

LICENSE=	GPLv2+ CC-BY-NC-SA-2.5
LICENSE_COMB=	multi
LICENSE_DISTFILES_GPLv2+ =	${DISTNAME}-src.tgz
LICENSE_DISTFILES_CC-BY-NC-SA-2.5=	${DISTNAME}-content.uqm

LIB_DEPENDS=	libSDL2.so:devel/sdl20 \
		libpng.so:graphics/png

USES=		gmake pkgconfig sdl
USE_SDL=	sdl2

OPTIONS_DEFINE=	DOCS MUSIC OPENAL VOICE
DOCS_DESC=	Install game manual
MUSIC_DESC=	3DO music package (19 MiB)
OPENAL_DESC=	Positional sound through OpenAL (experimental)
VOICE_DESC=	3DO speech package (110 MiB)
OPTIONS_GROUP=	REMIXES
OPTIONS_GROUP_REMIXES=	REMIX1 REMIX2 REMIX3 REMIX4
REMIXES_DESC=	Soundtrack Remixes
REMIX1_DESC=	"Super Meelee!"                  (48 MiB)
REMIX2_DESC=	"Neutral Aliens, Don't Shoot!"   (58 MiB)
REMIX3_DESC=	"Ur-Quan Hierarchy"              (39 MiB)
REMIX4_DESC=	"The New Alliance of Free Stars" (84 MiB)
OPTIONS_SUB=	yes

VOICE_DISTFILES=	${DISTNAME}-voice.uqm
MUSIC_DISTFILES=	${DISTNAME}-3domusic.uqm
OPENAL_USES=	openal:al

.include <bsd.port.options.mk>

# libvorbis is not required for a minimal installations, only for addons
.if ${PORT_OPTIONS:MMUSIC}${PORT_OPTIONS:MVOICE}${PORT_OPTIONS:MREMIX1}${PORT_OPTIONS:MREMIX2}${PORT_OPTIONS:MREMIX3}${PORT_OPTIONS:MREMIX4}
LIB_DEPENDS+=	libvorbis.so:audio/libvorbis
.endif

.if ${PORT_OPTIONS:MDOCS}
LICENSE+=	CC-BY-2.0
LICENSE_DISTFILES_CC-BY-2.0=	${DISTNAME}-src.tgz
.endif
.if ${PORT_OPTIONS:MMUSIC}
LICENSE_DISTFILES_CC-BY-NC-SA-2.5+=	${DISTNAME}-3domusic.uqm
.endif
.if ${PORT_OPTIONS:MVOICE}
LICENSE_DISTFILES_CC-BY-NC-SA-2.5+=	${DISTNAME}-voice.uqm
.endif
.for i in 1 2 3
.	if ${PORT_OPTIONS:MREMIX${i}}	# portlint warning here is false positive
MASTER_SITES+=	SF/sc2/UQM%20Remix%20Packs/UQM%20Remix%20Pack%20${i}:remix${i}
DISTFILES+=	${PORTNAME}-remix-disc${i}.uqm:remix${i}
LICENSE_DISTFILES_CC-BY-NC-SA-2.5+=	${PORTNAME}-remix-disc${i}.uqm
.	endif
.endfor
.if ${PORT_OPTIONS:MREMIX4}
MASTER_SITES+=	SF/sc2/UQM%20Remix%20Packs/UQM%20Remix%20Pack%204:remix4
DISTFILES+=	${PORTNAME}-remix-disc4-1.uqm:remix4
LICENSE_DISTFILES_CC-BY-NC-SA-2.5+=	${PORTNAME}-remix-disc4-1.uqm
.endif

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|^(SYSTEM_BUILD_LDFLAGS)=""|\1="-L${LOCALBASE}/lib"|; s|^(PROG_gcc_FILE)="gcc"|\1="${CC}"|; s|\(gcc --version\)|(${CC} --version)|' \
		${WRKSRC}/build/unix/config_proginfo_build
	@${REINPLACE_CMD} -Ee 's|/usr/X11R6/|${LOCALBASE}/|g; s|/usr/local/|${LOCALBASE}/|g' ${WRKSRC}/build/unix/config_proginfo_host
	@${REINPLACE_CMD} -Ee 's|%PREFIX%|${PREFIX}|g' ${WRKSRC}/config.state
.if ${PORT_OPTIONS:MOPENAL}
	@${REINPLACE_CMD} -Ee "s|(CHOICE_sound_VALUE)='mixsdl'|\1='openal'|g" ${WRKSRC}/config.state
.endif
.if ${LIB_DEPENDS:Mlibvorbis*}
	@${REINPLACE_CMD} -Ee "s|(CHOICE_ovcodec_VALUE)='none'|\1='standard'|g" ${WRKSRC}/config.state
.endif

do-configure:
	@(cd ${WRKSRC} && ${SETENV} LDFLAGS=-lm ./build.sh uqm reprocess_config)

do-build:
	@(cd ${WRKSRC} && ./build.sh uqm ${_MAKE_JOBS})

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/uqm ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/content/packages
	${MKDIR} ${STAGEDIR}${DATADIR}/content/addons
	${INSTALL_DATA} ${WRKSRC}/content/version ${STAGEDIR}${DATADIR}/content
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}-content.uqm ${STAGEDIR}${DATADIR}/content/packages
.if ${PORT_OPTIONS:MMUSIC}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}-3domusic.uqm ${STAGEDIR}${DATADIR}/content/addons
.endif
.if ${PORT_OPTIONS:MVOICE}
	${INSTALL_DATA} ${DISTDIR}/${DISTNAME}-voice.uqm ${STAGEDIR}${DATADIR}/content/addons
.endif
.if ${PORT_OPTIONS:MREMIX1}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-remix-disc1.uqm ${STAGEDIR}${DATADIR}/content/addons
.endif
.if ${PORT_OPTIONS:MREMIX2}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-remix-disc2.uqm ${STAGEDIR}${DATADIR}/content/addons
.endif
.if ${PORT_OPTIONS:MREMIX3}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-remix-disc3.uqm ${STAGEDIR}${DATADIR}/content/addons
.endif
.if ${PORT_OPTIONS:MREMIX4}
	${INSTALL_DATA} ${DISTDIR}/${PORTNAME}-remix-disc4-1.uqm ${STAGEDIR}${DATADIR}/content/addons
.endif
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/doc/users/manual.txt ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/doc/users/uqm.6 ${STAGEDIR}${PREFIX}/man/man6

.include <bsd.port.mk>
