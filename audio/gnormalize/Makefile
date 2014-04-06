# Created by: Denise H. G. <darcsis@gmail.com>
# $FreeBSD$

PORTNAME=	gnormalize
PORTVERSION=	0.63
PORTREVISION=	8
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	darcsis@gmail.com
COMMENT=	An alternative for replaygain

RUN_DEPENDS+=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		wavegain:${PORTSDIR}/audio/wavegain

USES=		perl5 shebangfix
USE_PERL5=	run
INSTALLS_ICONS=	yes

SHEBANG_FILES=	${PORTNAME}

NO_BUILD=	yes

OPTIONS_DEFINE=	MP3 OGG MP4 CDPARANOIA CDDB CDPLAY PLAC MAC MUSEPACK
OPTIONS_DEFAULT=	MP3 OGG MP4

MAC_DESC=	Monkey's Audio Encoding and Playback
CDPLAY_DESC=	CD Playback

MP3_RUN_DEPENDS=	lame:${PORTSDIR}/audio/lame \
			p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info
OGG_RUN_DEPENDS=	oggenc:${PORTSDIR}/audio/vorbis-tools
MP4_RUN_DEPENDS=	faac:${PORTSDIR}/audio/faac \
			faad:${PORTSDIR}/audio/faad
CDDB_RUN_DEPENDS=	cddb.pl:${PORTSDIR}/audio/p5-CDDB_get
CDPLAY_RUN_DEPENDS=	p5-Audio-CD>=0:${PORTSDIR}/audio/p5-Audio-CD
FLAC_RUN_DEPENDS=	flac:${PORTSDIR}/audio/flac
MAC_RUN_DEPENDS=	mac:${PORTSDIR}/audio/mac
MUSEPACK_RUN_DEPENDS=	mppenc:${PORTSDIR}/audio/musepack

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCDPARANOIA} || ${PORT_OPTIONS:MCDDA2WAV}
RUN_DEPENDS+=	cdda2wav:${PORTSDIR}/sysutils/cdrtools
.else
RUN_DEPENDS+=	cdparanoia:${PORTSDIR}/audio/cdparanoia
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^PREFIX=.*,PREFIX=${PREFIX},; \
		s,^MANDIR=.*,MANDIR=${MANPREFIX}/man,; \
		s,^BASE=.*,BASE=${DATADIR},' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr/share/gnormalize,${DATADIR},' \
		${WRKSRC}/gnormalize

.include <bsd.port.mk>
