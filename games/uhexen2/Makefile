# Created by: alepulver
# $FreeBSD$

PORTNAME=	uhexen2
PORTVERSION=	1.5.9
PORTREVISION=	1
CATEGORIES=	games
MASTER_SITES=	SF/${PORTNAME}/Hammer%20of%20Thyrion/${PORTVERSION}/Source \
		SF/${PORTNAME}/Hexen2%20GameData/gamedata-1.29b:data \
		SF/${PORTNAME}/Hexen2%20GameData/hexenworld-pakfiles:hw
DISTNAME=	hexen2source-${PORTVERSION}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		gamedata-all-1.29b${EXTRACT_SUFX}:data
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Hexen II source port supporting Linux/FreeBSD/Unix/Windows

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USES=		gl gmake pkgconfig sdl tar:tgz
USE_GL=		gl
USE_SDL=	sdl
MAKE_ARGS=	X11BASE="${LOCALBASE}"
MAKE_JOBS_UNSAFE=	yes

SUB_FILES=	pkg-message

PORTSCOUT=	skipb:yes

OPTIONS_DEFINE=		DOCS FLAC MIKMOD OGG OPUS
OPTIONS_MULTI=		BIN
OPTIONS_MULTI_BIN=	HEXEN2 HW
OPTIONS_RADIO=		MP3LIB VORBISLIB
OPTIONS_RADIO_MP3LIB=	MAD MPG123
OPTIONS_RADIO_VORBISLIB=	TREMOR VORBIS
OPTIONS_DEFAULT=	HEXEN2 HW MAD OGG VORBIS
OPTIONS_DEFINE_i386=	ASM
OPTIONS_DEFAULT_i386=	ASM
OPTIONS_SUB=		yes

ASM_BUILD_DEPENDS=	nasm:devel/nasm
ASM_MAKE_ARGS_OFF=	USE_X86_ASM=no
FLAC_LIB_DEPENDS=	libFLAC.so:audio/flac
FLAC_MAKE_ARGS=		USE_CODEC_FLAC=yes
HEXEN2_DESC=		Build Hexen II clients and servers
HEXEN2_MAKE_ARGS=	BUILD_HEXEN2=yes
HW_DESC=		Build HexenWorld clients and servers
HW_DISTFILES=		hexenworld-pakfiles-0.15${EXTRACT_SUFX}:hw
HW_MAKE_ARGS=		BUILD_HW=yes
MAD_LIB_DEPENDS=	libmad.so:audio/libmad
MAD_MAKE_ARGS=		MP3LIB=mad
MIKMOD_LIB_DEPENDS=	libmikmod.so:audio/libmikmod
MIKMOD_MAKE_ARGS=	USE_CODEC_MIKMOD=yes
MP3LIB_DESC=		MP3 audio codec
MPG123_LIB_DEPENDS=	libmpg123.so:audio/mpg123
MPG123_MAKE_ARGS=	MP3LIB=mpg123
OGG_LIB_DEPENDS=	libogg.so:audio/libogg
OGG_MAKE_ARGS_OFF=	USE_CODEC_OGG=no
OPUS_LIB_DEPENDS=	libopusfile.so:audio/opusfile
OPUS_MAKE_ARGS=		USE_CODEC_OPUS=yes
OPUS_IMPLIES=		OGG
TREMOR_LIB_DEPENDS=	libvorbisidec.so:audio/libtremor
TREMOR_MAKE_ARGS=	VORBISLIB=tremor
TREMOR_IMPLIES=		OGG
VORBIS_LIB_DEPENDS=	libvorbis.so:audio/libvorbis
VORBIS_MAKE_ARGS=	VORBISLIB=vorbis
VORBIS_IMPLIES=		OGG
VORBISLIB_DESC=		Vorbis audio codec

.include <bsd.port.options.mk>

.if !${PORT_OPTIONS:MMAD} && !${PORT_OPTIONS:MMPG123}
MAKE_ARGS+=	USE_CODEC_MP3=no
.endif

.if !${PORT_OPTIONS:MTREMOR} && !${PORT_OPTIONS:MVORBIS}
MAKE_ARGS+=	USE_CODEC_VORBIS=no
.endif

post-extract:
	@${CP} ${FILESDIR}/${MAKEFILE} ${WRKSRC}

post-patch:
.for f in engine/hexen2/Makefile engine/hexenworld/client/Makefile \
	engine/hexenworld/server/Makefile hw_utils/hwmaster/Makefile \
	libs/timidity/Makefile
	@${REINPLACE_CMD} -e \
		'/^CPU_X86/s|=.*|=| ; \
		 /^CFLAGS/s| -g | | ; \
		 /^CFLAGS/s| -O2 | | ;' ${WRKSRC}/${f}
.endfor
.for f in engine/h2shared/cd_bsd.c
	@${REINPLACE_CMD} -e \
		's|"acd0"|"cd0"|' ${WRKSRC}/${f}
.endfor
.for f in engine/hexen2/sys_unix.c engine/hexenworld/client/sys_unix.c
	@${REINPLACE_CMD} -e \
		'/parms.basedir/s|= cwd;|= "${DATADIR}";|' ${WRKSRC}/${f}
.endfor

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/data1
.for f in default.cfg hexen.rc progs.dat progs2.dat strings.txt
	${INSTALL_DATA} ${WRKDIR}/data1/${f} ${STAGEDIR}${DATADIR}/data1
.endfor
	${INSTALL_DATA} ${WRKDIR}/patchdat/data1/* ${STAGEDIR}${DATADIR}/data1
	(cd ${WRKDIR} && ${COPYTREE_SHARE} portals ${STAGEDIR}${DATADIR})

post-install-HW-on:
	${INSTALL_PROGRAM} ${WRKSRC}/engine/hexenworld/client/glhwcl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/engine/hexenworld/client/hwcl ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/engine/hexenworld/server/hwsv ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/hw_utils/hwmaster/hwmaster ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/hw
	${INSTALL_DATA} ${WRKDIR}/hw/* ${STAGEDIR}${DATADIR}/hw

post-install-HEXEN2-on:
	${INSTALL_PROGRAM} ${WRKSRC}/engine/hexen2/glhexen2 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/engine/hexen2/hexen2 ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
