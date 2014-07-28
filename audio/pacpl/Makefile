# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pacpl
PORTVERSION=	5.0.1
PORTREVISION=	9
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl Audio Converter

USES=		shebangfix perl5
ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	CDPARANOIA CDDB FAAC FAAD FFMPEG FLAC FLACTAG \
		LAME LAUDIO SNDFILE LPAC APE APETAG MP3TAG MP4TAG \
		MPPTAG MPLAYER NLS OPTIMFROG VORBIS VORBISTAG SHORTEN \
		SOX SPEEX TOOLAME TTA WAVPACK WMATAG KDE4 DOCS

OPTIONS_DEFAULT=	CDPARANOIA CDDB FAAD FFMPEG FLAC FLACTAG MP3TAG \
			VORBIS VORBISTAG
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT=	LAME FAAC
.endif

OPTIONS_SUB=	yes

APETAG_DESC=	Enable Monkey's tagging support
FLACTAG_DESC=	Enable FLAC tagging support
KDE4_DESC=	Enable Konqueror/Dolphin integration
LAUDIO_DESC=	Enable laudio support
LPAC_DESC=	Enable LPAC support
MP3TAG_DESC=	Enable MP3 tagging support
MP4TAG_DESC=	Enable MP4 tagging support
MPLAYER_DESC=	Enable Mplayer support
MPPTAG_DESC=	Enable Musepack tagging support
OPTIMFROG_DESC=	Enable OptimFROG support
VORBISTAG_DESC=	Enable Ogg/Vorbis tagging support
SHORTEN_DESC=	Enable Shorten support
SOX_DESC=	Enable SoX support
TOOLAME_DESC=	Enable tooLAME support
TTA_DESC=	Enable TTA support
WAVPACK_DESC=	Enable wavpack support
WMATAG_DESC=	Enable WMA tagging support
MORELANGS_DESC=	Enable Additional language support

SHEBANG_FILES=	pacpl

APE_RUN_DEPENDS=	mac:${PORTSDIR}/audio/mac
APETAG_RUN_DEPENDS=	p5-Audio-Musepack>0:${PORTSDIR}/audio/p5-Audio-Musepack
CDDB_RUN_DEPENDS=	p5-CDDB_get>0:${PORTSDIR}/audio/p5-CDDB_get
CDPARANOIA_RUN_DEPENDS=	cdparanoia:${PORTSDIR}/audio/cdparanoia
FAAC_RUN_DEPENDS=	faac:${PORTSDIR}/audio/faac
FAAD_RUN_DEPENDS=	faad:${PORTSDIR}/audio/faad
FFMPEG_RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
FLAC_RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac
FLACTAG_RUN_DEPENDS=	p5-Audio-FLAC-Header>0:${PORTSDIR}/audio/p5-Audio-FLAC-Header
KDE4_USE=		KDE4=kdehier
LAME_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame
LAUDIO_RUN_DEPENDS=	laudio:${PORTSDIR}/audio/linux-laudio
SNDFILE_RUN_DEPENDS=	sndfile-convert:${PORTSDIR}/audio/libsndfile
LPAC_RUN_DEPENDS=	lpac:${PORTSDIR}/audio/lpac
MPPTAG_RUN_DEPENDS=	p5-Audio-Musepack>0:${PORTSDIR}/audio/p5-Audio-Musepack
MP3TAG_RUN_DEPENDS=	p5-MP3-Tag>0:${PORTSDIR}/audio/p5-MP3-Tag
MP4TAG_RUN_DEPENDS=	p5-MP4-Info>0:${PORTSDIR}/multimedia/p5-MP4-Info
MPLAYER_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
MPPPACK_RUN_DEPENDS=	mppenc:${PORTSDIR}/audio/musepack
OPTIMFROG_RUN_DEPENDS=	ofr:${PORTSDIR}/audio/optimfrog
VORBIS_RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools
VORBISTAG_RUN_DEPENDS=	p5-Ogg-Vorbis-Header>0:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header
SHORTEN_RUN_DEPENDS=	shorten:${PORTSDIR}/audio/shorten
SOX_RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox
SPEEX_RUN_DEPENDS=	speexenc:${PORTSDIR}/audio/speex
TOOLAME_RUN_DEPENDS=	toolame:${PORTSDIR}/audio/toolame
TTA_RUN_DEPENDS=	ttaenc:${PORTSDIR}/audio/tta
WAVPACK_RUN_DEPENDS=	wavpack:${PORTSDIR}/audio/wavpack
WMATAG_RUN_DEPENDS=	p5-Audio-WMA>0:${PORTSDIR}/audio/p5-Audio-WMA

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKDE4}
PLIST_SUB+=	KDE4_PREFIX="${KDE4_PREFIX}"
.endif

post-patch:
	@${REINPLACE_CMD} -e 's@/etc/pacpl@${PREFIX}/etc/pacpl@; \
		s@/usr/share/pacpl@${DATADIR}@' ${WRKSRC}/pacpl ${WRKSRC}/pacpl.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pacpl ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pacpl/modules
	@${MKDIR} ${STAGEDIR}${DATADIR}/locale
	${INSTALL_DATA} ${WRKSRC}/pacpl.conf ${STAGEDIR}${PREFIX}/etc/pacpl/pacpl.conf.sample
	${INSTALL_DATA} ${WRKSRC}/codecs.conf ${STAGEDIR}${PREFIX}/etc/pacpl/codecs.conf.sample
	${INSTALL_DATA} ${WRKSRC}/extra/sample.m ${STAGEDIR}${PREFIX}/etc/pacpl/modules/sample.m
	${INSTALL_DATA} ${WRKSRC}/po/* ${STAGEDIR}${DATADIR}/locale
	@pod2man ${WRKSRC}/pacpl ${WRKSRC}/pacpl.1
	${INSTALL_MAN} ${WRKSRC}/pacpl.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MKDE4}
	${INSTALL_DATA} ${WRKSRC}/plugins/kde/pacpl.desktop ${STAGEDIR}${KDE4_PREFIX}/share/kde4/services/ServiceMenus
.endif

	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/README.module ${WRKSRC}/ChangeLog ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

post-install:
	@${ECHO_MSG} ""
	#@${STAGEDIR}${PREFIX}/bin/pacpl -f # FIXME errors out
	@${ECHO_MSG} ""
	@${ECHO_MSG} "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "If you are updating from pacpl 3.x please do take"
	@${ECHO_MSG} "time to review the changes in 4.x:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "  http://sourceforge.net/p/pacpl/code/ci/master/tree/ChangeLog"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The command-line options are quite different in 4.x.  A"
	@${ECHO_MSG} "few features are no longer available and several are new. "
	@${ECHO_MSG} "You should also take a look at the two config files in"
	@${ECHO_MSG} "${PREFIX}/etc/pacpl."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The supported codecs and tagging available in this port"
	@${ECHO_MSG} "build are listed above this message."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "
	@${ECHO_MSG} ""

.include <bsd.port.mk>
