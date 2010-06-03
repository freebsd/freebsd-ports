# New ports collection makefile for:	pacpl
# Date created:		21 July 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pacpl
PORTVERSION=	4.0.5
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SF

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
		KDE4SM		"Konqueror/Dolphin integration"	off \
		AMAROK		"Amarok integration (BROKEN)"	off \
		MORELANGS	"Additional language support"	off

MAN1=		pacpl.1
PACPL_PO=	en_US.po

.include <bsd.port.options.mk>

.if defined(WITH_KDE4SM)
USE_KDE4=	kdebase
PLIST_SUB+=	KDE4SERVICEMENU="" KDE4_PREFIX="${KDE4_PREFIX}"
.else
PLIST_SUB+=	KDE4SERVICEMENU="@comment "
.endif

.if defined(WITH_AMAROK)
BROKEN=		Amarok support temporarily broken in 4.05+
RUN_DEPENDS+=	amarok:${PORTSDIR}/audio/amarok
PLIST_SUB+=	AMAROK=""
.else
PLIST_SUB+=	AMAROK="@comment "
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_BLADEENC)
RUN_DEPENDS+=	bladeenc:${PORTSDIR}/audio/bladeenc
.endif

.if defined(WITH_BONK)
RUN_DEPENDS+=	bonk:${PORTSDIR}/audio/bonk
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
.endif

.if defined(WITH_SNDFILE)
RUN_DEPENDS+=	sndfile-convert:${PORTSDIR}/audio/libsndfile
.endif

.if defined(WITH_LPAC)
RUN_DEPENDS+=	lpac:${PORTSDIR}/audio/lpac
.endif

.if defined(WITH_MONKEY)
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
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
.endif

.if defined(WITH_OGGVORBIS)
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_OGGTAG)
RUN_DEPENDS+=	p5-Ogg-Vorbis-Header>0:${PORTSDIR}/audio/p5-Ogg-Vorbis-Header
.endif

.if defined(WITH_SHORTEN)
RUN_DEPENDS+=	shorten:${PORTSDIR}/audio/shorten
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
.endif

.if defined(WITH_WAVPACK)
RUN_DEPENDS+=	wavpack:${PORTSDIR}/audio/wavpack
.endif

.if defined(WITH_WMATAG)
RUN_DEPENDS+=	p5-Audio-WMA>0:${PORTSDIR}/audio/p5-Audio-WMA
.endif

.if defined(WITH_MORELANGS)
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

.if defined(WITH_KDE4SM)
	${INSTALL_DATA} ${WRKSRC}/plugins/konqueror/pacpl.desktop ${KDE4_PREFIX}/share/kde4/services/ServiceMenus
.endif

.if defined(WITH_AMAROK)
	${MKDIR} ${PREFIX}/share/apps/amarok/scripts/transcoding_pacx
	${INSTALL_DATA} ${WRKSRC}/plugins/amarok/pacx ${PREFIX}/share/apps/amarok/scripts/transcoding_pacx/transcoding_pacx.pl
	${PERL} -e 'print qq(name = Pacx\ntype = transcode)' > ${PREFIX}/share/apps/amarok/scripts/transcoding_pacx/transcoding_pacx.spec
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
