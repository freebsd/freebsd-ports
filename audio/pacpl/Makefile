# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pacpl
PORTVERSION=	5.0.1
PORTREVISION=	11
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Perl Audio Converter

LICENSE=	GPLv3 # (or later)

RUN_DEPENDS=	p5-Audio-FLAC-Header>0:${PORTSDIR}/audio/p5-Audio-FLAC-Header \
		p5-Audio-Scan>0:${PORTSDIR}/audio/p5-Audio-Scan \
		p5-CDDB_get>0:${PORTSDIR}/audio/p5-CDDB_get \
		p5-MP3-Tag>0:${PORTSDIR}/audio/p5-MP3-Tag \
		p5-Parallel-ForkManager>0:${PORTSDIR}/devel/p5-Parallel-ForkManager \
		p5-Switch>0:${PORTSDIR}/lang/p5-Switch

NO_ARCH=	yes

USES=		perl5 shebangfix
SHEBANG_FILES=	pacpl plugins/gnome/nautilus/PACPL-Convert \
		plugins/kde/PACPL-Konvert

OPTIONS_DEFINE=		APE CDPARANOIA DOCS FAAC FAAD FFMPEG KDE4 \
			LAME LAUDIO MUSEPACK MPLAYER OPTIMFROG OPUS \
			SHORTEN SNDFILE SOX SPEEX TOOLAME TTA VORBIS WAVPACK
OPTIONS_DEFAULT=	CDPARANOIA FAAC FAAD FFMPEG LAME VORBIS
OPTIONS_SUB=		yes

APE_RUN_DEPENDS=	mac:${PORTSDIR}/audio/mac
CDPARANOIA_RUN_DEPENDS=	cdparanoia:${PORTSDIR}/audio/cdparanoia
FAAC_RUN_DEPENDS=	faac:${PORTSDIR}/audio/faac
FAAD_RUN_DEPENDS=	faad:${PORTSDIR}/audio/faad
FFMPEG_RUN_DEPENDS=	ffmpeg:${PORTSDIR}/multimedia/ffmpeg
KDE4_DESC=		Konqueror/Dolphin integration
KDE4_USE=		KDE4=kdehier
LAME_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame
LAUDIO_DESC=		Laudio support
LAUDIO_RUN_DEPENDS=	laudio:${PORTSDIR}/audio/linux-laudio
MPLAYER_RUN_DEPENDS=	mplayer:${PORTSDIR}/multimedia/mplayer
MUSEPACK_RUN_DEPENDS=	mpcenc:${PORTSDIR}/audio/musepack
OPTIMFROG_DESC=		OptimFROG lossless audio support
OPTIMFROG_RUN_DEPENDS=	ofr:${PORTSDIR}/audio/optimfrog
OPUS_DESC=		Ogg Opus audio codec support
OPUS_RUN_DEPENDS=	opusenc:${PORTSDIR}/audio/opus-tools
SNDFILE_RUN_DEPENDS=	sndfile-convert:${PORTSDIR}/audio/libsndfile
VORBIS_RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools
SHORTEN_DESC=		Shorten audio support
SHORTEN_RUN_DEPENDS=	shorten:${PORTSDIR}/audio/shorten
SOX_DESC=		Audio conversion support via SoX
SOX_RUN_DEPENDS=	sox:${PORTSDIR}/audio/sox
SPEEX_RUN_DEPENDS=	speexenc:${PORTSDIR}/audio/speex
TOOLAME_RUN_DEPENDS+=	toolame:${PORTSDIR}/audio/toolame
TTA_RUN_DEPENDS=	ttaenc:${PORTSDIR}/audio/tta
VORBIS_RUN_DEPENDS=	vorbiscomment:${PORTSDIR}/audio/vorbis-tools
WAVPACK_RUN_DEPENDS=	wavpack:${PORTSDIR}/audio/wavpack

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e \
		's|"/etc/pacpl|"${ETCDIR}| ; \
		 s|"/usr/share/pacpl|"${DATADIR}| ; \
		 s|^/etc/pacpl|${ETCDIR}|' ${WRKSRC}/pacpl
	@${REINPLACE_CMD} -e \
		's| /etc/pacpl| ${ETCDIR}|' ${WRKSRC}/pacpl.conf
	@${REINPLACE_CMD} -e \
		's|=/etc/pacpl|=${ETCDIR}| ; \
		 s|=/usr/bin|=${PREFIX}/libexec|' \
		${WRKSRC}/plugins/kde/pacpl.desktop

do-build:
	@(cd ${WRKSRC} && pod2man pacpl pacpl.1)

do-install:
	(cd ${WRKSRC} && ${INSTALL_SCRIPT} pacpl \
		${STAGEDIR}${PREFIX}/bin)
	(cd ${WRKSRC} && ${INSTALL_MAN} pacpl.1 \
		${STAGEDIR}${MANPREFIX}/man/man1)
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} pacpl.png \
		${STAGEDIR}${ETCDIR})
.for i in codecs.conf pacpl.conf
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} \
		${STAGEDIR}${ETCDIR}/${i}.sample)
.endfor
	@${MKDIR} ${STAGEDIR}${ETCDIR}/modules
	(cd ${WRKSRC}/extra && ${INSTALL_DATA} sample.m \
		${STAGEDIR}${ETCDIR}/modules)
	@${MKDIR} ${STAGEDIR}${DATADIR}/locale
	(cd ${WRKSRC}/po && ${INSTALL_DATA} *.po \
		${STAGEDIR}${DATADIR}/locale)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ChangeLog README \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/extra && ${INSTALL_DATA} README.module \
		${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/plugins/gnome/nautilus && ${INSTALL_SCRIPT} PACPL-Convert \
		${STAGEDIR}${PREFIX}/libexec)
.if ${PORT_OPTIONS:MKDE4}
	(cd ${WRKSRC}/plugins/kde && ${INSTALL_SCRIPT} PACPL-Konvert \
		${STAGEDIR}${PREFIX}/libexec)
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/kde4/services/ServiceMenus
	(cd ${WRKSRC}/plugins/kde && ${INSTALL_DATA} pacpl.desktop \
		${STAGEDIR}${PREFIX}/share/kde4/services/ServiceMenus)
.endif

.include <bsd.port.mk>
