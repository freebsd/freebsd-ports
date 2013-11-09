# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pacpl
PORTVERSION=	4.0.5
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Perl Audio Converter

USES=		shebangfix perl5
NO_STAGE=	yes
ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes

OPTIONS_DEFINE=	BONK CDPARANOIA CDDB FAAC FAAD FFMPEG FLAC FLACTAG \
		LAME LAUDIO SNDFILE LPAC APE APETAG MP3TAG MP4TAG \
		MPP  MPLAYER OPTIMFROG VORBIS VORBISTAG SHORTEN \
		SOX SPEEX TOOLAME TTA WAVPACK WMATAG KDE4 AMAROK NORELANGS \
		DOCS

OPTIONS_DEFAULT=	CDPARANOIA CDDB FAAD FFMPEG FLAC FLACTAG MP3TAG \
			VORBIS VORBISTAG
.if !defined(PACKAGE_BUILDING)
OPTIONS_DEFAULT=	LAME FAAC
.endif

BONK_DESC=	Enable Bonk support
AMAROK_DESC=	Enable Amarok integration (BROKEN)
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

MAN1=		pacpl.1
PACPL_PO=	en_US.po

SHEBANG_FILES=	pacpl plugins/amarok/pacx

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MKDE4}
USE_KDE4=	kdehier
PLIST_SUB+=	KDE4SERVICEMENU="" KDE4_PREFIX="${KDE4_PREFIX}"
.else
PLIST_SUB+=	KDE4SERVICEMENU="@comment "
.endif

.if ${PORT_OPTIONS:MAMAROK}
BROKEN=		Amarok support temporarily broken in 4.05+
RUN_DEPENDS+=	amarok:${PORTSDIR}/audio/amarok
PLIST_SUB+=	AMAROK=""
.else
PLIST_SUB+=	AMAROK="@comment "
.endif

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} >= 501400
BUILD_DEPENDS+= p5-Switch>0:${PORTSDIR}/lang/p5-Switch
.endif

.if ${PORT_OPTIONS:MBONK}
RUN_DEPENDS+=	bonk:${PORTSDIR}/audio/bonk
.endif

.if ${PORT_OPTIONS:MCDDB}
RUN_DEPENDS+=	p5-CDDB_get>0:${PORTSDIR}/audio/p5-CDDB_get
.endif

.if ${PORT_OPTIONS:MCDPARANOIA}
RUN_DEPENDS+=	cdparanoia:${PORTSDIR}/audio/cdparanoia
.endif

.if ${PORT_OPTIONS:MFAAC}
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac
.endif

.if ${PORT_OPTIONS:MFAAD}
RUN_DEPENDS+=	faad:${PORTSDIR}/audio/faad
.endif

.if ${PORT_OPTIONS:MFFMPEG}
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
.endif

.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if ${PORT_OPTIONS:MFLACTAG}
RUN_DEPENDS+=	p5-Audio-FLAC-Header>0:${PORTSDIR}/audio/p5-Audio-FLAC-Header
.endif

.if ${PORT_OPTIONS:MLAME}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if ${PORT_OPTIONS:MLAUDIO}
RUN_DEPENDS+=	laudio:${PORTSDIR}/audio/linux-laudio
.endif

.if ${PORT_OPTIONS:MSNDFILE}
RUN_DEPENDS+=	sndfile-convert:${PORTSDIR}/audio/libsndfile
.endif

.if ${PORT_OPTIONS:MLPAC}
RUN_DEPENDS+=	lpac:${PORTSDIR}/audio/lpac
.endif

.if ${PORT_OPTIONS:MAPE}
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
.endif

.if ${PORT_OPTIONS:MMPPTAG} || ${PORT_OPTIONS:MAPETAG}
RUN_DEPENDS+=	p5-Audio-Musepack>0:${PORTSDIR}/audio/p5-Audio-Musepack
.endif

.if ${PORT_OPTIONS:MMP3TAG}
RUN_DEPENDS+=	p5-MP3-Tag>0:${PORTSDIR}/audio/p5-MP3-Tag
.endif

.if ${PORT_OPTIONS:MMP4TAG}
RUN_DEPENDS+=	p5-MP4-Info>0:${PORTSDIR}/multimedia/p5-MP4-Info
.endif

.if ${PORT_OPTIONS:MMPLAYER}
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if ${PORT_OPTIONS:MMPPPACK}
RUN_DEPENDS+=	mppenc:${PORTSDIR}/audio/musepack
.endif

.if ${PORT_OPTIONS:MOPTIMFROG}
RUN_DEPENDS+=	ofr:${PORTSDIR}/audio/optimfrog
.endif

.if ${PORT_OPTIONS:MVORBISVORBIS}
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.if ${PORT_OPTIONS:MVORBISTAG}
RUN_DEPENDS+=	p5-Ogg-Vorbis-Header>0:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header
.endif

.if ${PORT_OPTIONS:MSHORTEN}
RUN_DEPENDS+=	shorten:${PORTSDIR}/audio/shorten
.endif

.if ${PORT_OPTIONS:MSOX}
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

.if ${PORT_OPTIONS:MSPEEX}
RUN_DEPENDS+=	speexenc:${PORTSDIR}/audio/speex
.endif

.if ${PORT_OPTIONS:MTOOLAME}
RUN_DEPENDS+=	toolame:${PORTSDIR}/audio/toolame
.endif

.if ${PORT_OPTIONS:MTTA}
RUN_DEPENDS+=	ttaenc:${PORTSDIR}/audio/tta
.endif

.if ${PORT_OPTIONS:MWAVPACK}
RUN_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
.endif

.if ${PORT_OPTIONS:MWMATAG}
RUN_DEPENDS+=	p5-Audio-WMA>0:${PORTSDIR}/audio/p5-Audio-WMA
.endif

.if ${PORT_OPTIONS:MMORELANGS}
PACPL_PO+=	ca.po de.po es.po et.po fr_FR.po it_IT.po nl_NL.po pl.po pt.po ro.po ru_RU.po tr.po zh_CN.po
PLIST_SUB+=	ADDITIONAL_LANGS=""
.else
PLIST_SUB+=	ADDITIONAL_LANGS="@comment "
.endif

post-extract:

	@${ECHO_MSG} ""
	@${ECHO_MSG} " * * * * * * * * * W A R N I N G * * * * * * * * * * * * * "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WARNING: Integration options with Amarok, KDE4 Dolphin and"
	@${ECHO_MSG} "Konqueror now pull in their respective ports!"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "The port now provides the option to select codecs, CD"
	@${ECHO_MSG} "burning, CDDB and tagging modules individually so you don't"
	@${ECHO_MSG} "have to install all by default.  You will still be offered"
	@${ECHO_MSG} "the ability to convert to and from these formats in the"
	@${ECHO_MSG} "pacpl options even if the codec is not installed."
	@${ECHO_MSG} ""
	@${ECHO_MSG} "CTRL-C now if you'd like to reconfigure, read the Changelog,"
	@${ECHO_MSG} "or README:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "	${WRKSRC}/ChangeLog"
	@${ECHO_MSG} "	${WRKSRC}/README"
	@${ECHO_MSG} ""
	@${ECHO_MSG} " * * * * * * * * * * * * * * * * * * * * * * * * * * * * * "
	@${ECHO_MSG} ""
	@sleep 5

post-patch:
	@${REINPLACE_CMD} -e 's@/etc/pacpl@${PREFIX}/etc/pacpl@; \
		s@/usr/share/pacpl@${DATADIR}@' ${WRKSRC}/pacpl ${WRKSRC}/pacpl.conf

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/pacpl ${PREFIX}/bin/
	${MKDIR} ${PREFIX}/etc/pacpl/modules/
	${MKDIR} ${DATADIR}/locale/
	${INSTALL_DATA} ${WRKSRC}/pacpl.conf ${PREFIX}/etc/pacpl/pacpl.conf.sample
	${INSTALL_DATA} ${WRKSRC}/codecs.conf ${PREFIX}/etc/pacpl/codecs.conf.sample
	${INSTALL_DATA} ${WRKSRC}/extra/sample.m ${PREFIX}/etc/pacpl/modules/sample.m
.for po in ${PACPL_PO}
	${INSTALL_DATA} ${WRKSRC}/po/${po} ${DATADIR}/locale
.endfor
	@pod2man ${WRKSRC}/pacpl ${WRKSRC}/pacpl.1
	${INSTALL_MAN} ${WRKSRC}/pacpl.1 ${MAN1PREFIX}/man/man1/

.if ${PORT_OPTIONS:MKDE4}
	${INSTALL_DATA} ${WRKSRC}/plugins/konqueror/pacpl.desktop ${KDE4_PREFIX}/share/kde4/services/ServiceMenus
.endif

.if ${PORT_OPTIONS:MAMAROK}
	${MKDIR} ${PREFIX}/share/apps/amarok/scripts/transcoding_pacx
	${INSTALL_DATA} ${WRKSRC}/plugins/amarok/pacx ${PREFIX}/share/apps/amarok/scripts/transcoding_pacx/transcoding_pacx.pl
	${PERL} -e 'print qq(name = Pacx\ntype = transcode)' > ${PREFIX}/share/apps/amarok/scripts/transcoding_pacx/transcoding_pacx.spec
.endif

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/extra/README.module ${WRKSRC}/ChangeLog ${WRKSRC}/README ${DOCSDIR}
.endif

post-install:
	@${ECHO_MSG} ""
	@${PREFIX}/bin/pacpl -f
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

.include <bsd.port.post.mk>
