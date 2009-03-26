# New ports collection makefile for:	pacpl
# Date created:		21 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pacpl
PORTVERSION=	4.0.3
CATEGORIES=	audio
MASTER_SITES=	SFE

MAINTAINER=	hideo@lastamericanempire.com
COMMENT=	Perl Audio Converter

USE_PERL5_BUILD=yes
USE_PERL5_RUN=	yes
ONLY_FOR_ARCHS=	i386 amd64
NO_BUILD=	yes

OPTIONS=	BLADEENC	"BladeEnc support"		off \
		BONK		"Bonk support"			off \
		CDPARANOIA	"CD Ripping support"		on \
		CDDB		"CDDB support"			on \
		FAAC		"FAAC support"			on \
		FAAD		"FAAD support"			on \
		FFMPEG		"FFMPEG suport"			on \
		FLAC		"FLAC support"			on \
		FLACTAG		"FLAC tagging support"		on \
		GOGO		"GOGO-no-coda support"		off \
		LAME		"Lame support"			on \
		LAUDIO		"Laudio support"		off \
		SNDFILE		"libsndfile support"		off \
		LPAC		"LPAC support"			off \
		MONKEY		"Monkey's Audio support"	off \
		APETAG		"Monkey's tagging support"	off \
		MP3TAG		"MP3 tagging support"		on \
		MP4TAG		"MP4 tagging support"		off \
		MPLAYER		"MPlayer support"		on \
		MUSEPACK	"Musepack support"		off \
		MUSETAG		"Musepack tagging support"	off \
		OPTIMFROG	"OptimFROG support"		off \
		OGGVORBIS	"Ogg/Vorbis support"		off \
		OGGTAG		"Ogg/Vorbis tagging support"	off \
		SHORTEN		"Shorten support"		off \
		SOX		"SoX support"			off \
		SPEEX		"Speex support"			off \
		TOOLAME		"tooLAME support"		off \
		TTA		"TTA support"			off \
		WAVPACK		"WavPack support"		off \
		WMATAG		"WMA Tagging support"		off \
		KONQUEROR	"KDE/Konqueror integration"	off \
		DOLPHIN		"Dolphin integration"		off \
		AMAROK		"Amarok integration"		off \
		MORELANGS	"Additional language support"	off

MAN1=		pacpl.1
PACPL_PO=	en_US.po

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500701
RUN_DEPENDS+=	p5-Switch>0:${PORTSDIR}/lang/p5-Switch
.endif

.if defined(WITH_BLADEENC)
RUN_DEPENDS+=	bladeenc:${PORTSDIR}/audio/bladeenc
.endif

.if defined(WITH_BONK)
RUN_DEPENDS+=	bonk:${PORTSDIR}/audio/bonk
KONQMIMES+=	x-bonk
PLIST_SUB+=	BONK=""
.else
PLIST_SUB+=	BONK="@comment "
.endif

.if defined(WITH_CDDB)
RUN_DEPENDS+=	p5-CDDB_get>0:${PORTSDIR}/audio/p5-CDDB_get
.endif

.if defined(WITH_CDPARANOIA)
RUN_DEPENDS+=	cdparanoia:${PORTSDIR}/audio/cdparanoia
.endif

.if defined(WITH_FAAC)
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac
.endif

.if defined(WITH_FAAD)
RUN_DEPENDS+=	faad:${PORTSDIR}/audio/faad
.endif

.if defined(WITH_FFMPEG)
RUN_DEPENDS+=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
.endif

.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if defined(WITH_FLACTAG)
RUN_DEPENDS+=	p5-Audio-FLAC-Header>0:${PORTSDIR}/audio/p5-Audio-FLAC-Header
.endif

.if defined(WITH_GOGO)
RUN_DEPENDS+=	gogo:${PORTSDIR}/audio/gogo
.endif

.if defined(WITH_LAME)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_LAUDIO)
RUN_DEPENDS+=	laudio:${PORTSDIR}/audio/laudio
KONQMIMES+=	x-la
PLIST_SUB+=	LAUDIO=""
.else
PLIST_SUB+=	LAUDIO="@comment "
.endif

.if defined(WITH_SNDFILE)
RUN_DEPENDS+=	sndfile-convert:${PORTSDIR}/audio/libsndfile
.endif

.if defined(WITH_LPAC)
RUN_DEPENDS+=	lpac:${PORTSDIR}/audio/lpac
KONQMIMES+=	x-lpac
PLIST_SUB+=	LPAC=""
.else
PLIST_SUB+=	LPAC="@comment "
.endif

.if defined(WITH_MONKEY)
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
KONQMIMES+=	x-ape
PLIST_SUB+=	MONKEY=""
.else
PLIST_SUB+=	MONKEY="@comment "
.endif

.if defined(WITH_MUSETAG) || defined(WITH_APETAG)
RUN_DEPENDS+=	p5-Audio-Musepack>0:${PORTSDIR}/audio/p5-Audio-Musepack
.endif

.if defined(WITH_MP3TAG)
RUN_DEPENDS+=	p5-MP3-Tag>0:${PORTSDIR}/audio/p5-MP3-Tag
.endif

.if defined(WITH_MP4TAG)
RUN_DEPENDS+=	p5-MP4-Info>0:${PORTSDIR}/multimedia/p5-MP4-Info
.endif

.if defined(WITH_MPLAYER)
RUN_DEPENDS+=	mplayer:${PORTSDIR}/multimedia/mplayer
.endif

.if defined(WITH_MUSEPACK)
RUN_DEPENDS+=	mppenc:${PORTSDIR}/audio/musepack
.endif

.if defined(WITH_OPTIMFROG)
RUN_DEPENDS+=	ofr:${PORTSDIR}/audio/optimfrog
KONQMIMES+=	x-ofr x-ofs
PLIST_SUB+=	OPTIMFROG=""
.else
PLIST_SUB+=	OPTIMFROG="@comment "
.endif

.if defined(WITH_OGGVORBIS)
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_OGGTAG)
RUN_DEPENDS+=	p5-Ogg-Vorbis-Header>0:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header
.endif

.if defined(WITH_SHORTEN)
RUN_DEPENDS+=	shorten:${PORTSDIR}/audio/shorten
KONQMIMES+=	x-shn
PLIST_SUB+=	SHORTEN=""
.else
PLIST_SUB+=	SHORTEN="@comment "
.endif

.if defined(WITH_SOX)
RUN_DEPENDS+=	sox:${PORTSDIR}/audio/sox
.endif

.if defined(WITH_SPEEX)
RUN_DEPENDS+=	speexenc:${PORTSDIR}/audio/speex
.endif

.if defined(WITH_TOOLAME)
RUN_DEPENDS+=	toolame:${PORTSDIR}/audio/toolame
.endif

.if defined(WITH_TTA)
RUN_DEPENDS+=	ttaenc:${PORTSDIR}/audio/tta
KONQMIMES+=	x-tta
PLIST_SUB+=	TTA=""
.else
PLIST_SUB+=	TTA="@comment "
.endif

.if defined(WITH_WAVPACK)
RUN_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
KONQMIMES+=	x-wavpack
PLIST_SUB+=	WAVPACK=""
.else
PLIST_SUB+=	WAVPACK="@comment "
.endif

.if defined(WITH_WMATAG)
RUN_DEPENDS+=	p5-Audio-WMA>0:${PORTSDIR}/audio/p5-Audio-WMA
.endif

.if defined(WITH_FFMPEG) && defined(WITH_MPLAYER)
KONQMIMES+=	x-rm
PLIST_SUB+=	RM=""
.else
PLIST_SUB+=	RM="@comment "
.endif

.if defined(WITH_KONQUEROR)
RUN_DEPENDS+=	konqueror:${PORTSDIR}/x11/kdebase3
PLIST_SUB+=	KONQUEROR=""
.else
PLIST_SUB+=	KONQUEROR="@comment "
.endif

.if defined(WITH_AMAROK)
RUN_DEPENDS+=	amarok:${PORTSDIR}/audio/amarok
PLIST_SUB+=	AMAROK=""
.else
PLIST_SUB+=	AMAROK="@comment "
.endif

.if defined(WITH_DOLPHIN)
RUN_DEPENDS+=	dolphin:${PORTSDIR}/x11-fm/dolphin
PLIST_SUB+=	DOLPHIN=""
.else
PLIST_SUB+=	DOLPHIN="@comment "
.endif

.if defined(WITH_MORELANGS)
PACPL_PO+=	ca.po de.po es.po et.po fr_FR.po pl.po pt.po ru_RU.po tr.po zh_CN.po
PLIST_SUB+=	ADDITIONAL_LANGS=""
.else
PLIST_SUB+=	ADDITIONAL_LANGS="@comment "
.endif

post-extract:

	@${ECHO_MSG} ""
	@${ECHO_MSG} " * * * * * * * * * W A R N I N G * * * * * * * * * * * * * "
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WARNING: Integration options with Amarok, Dolphin, and"
	@${ECHO_MSG} "KDE3/Konqueror now pull in their respective ports!"
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

.if defined(WITH_KONQUEROR)
	${MKDIR} ${PREFIX}/share/mimelnk/audio
	${MKDIR} ${PREFIX}/share/apps/konqueror/servicemenus
	${INSTALL_DATA} ${WRKSRC}/plugins/konqueror/pacpl.desktop ${PREFIX}/share/apps/konqueror/servicemenus/
.for m in ${KONQMIMES}
	${INSTALL_DATA} ${WRKSRC}/plugins/konqueror/mimes/${m}.desktop ${PREFIX}/share/mimelnk/audio/
.endfor
.endif

.if defined(WITH_AMAROK)
	${MKDIR} ${PREFIX}/share/apps/amarok/scripts/transcoding_pacx
	${INSTALL_DATA} ${WRKSRC}/plugins/amarok/pacx ${PREFIX}/share/apps/amarok/scripts/transcoding_pacx/transcoding_pacx.pl
	${PERL} -e 'print qq(name = Pacx\ntype = transcode)' > ${PREFIX}/share/apps/amarok/scripts/transcoding_pacx/transcoding_pacx.spec
.endif

.if defined(WITH_DOLPHIN)
	${MKDIR} ${PREFIX}/share/apps/dolphin/servicemenus
	${INSTALL_DATA} ${WRKSRC}/plugins/dolphin/pacpl.desktop ${PREFIX}/share/apps/dolphin/servicemenus/
.endif

.if !defined(NOPORTDOCS)
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
	@${ECHO_MSG} "	http://pacpl.sourceforge.net/ChangeLog.txt"
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
