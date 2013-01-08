# Created by: Denise H. G. <darcsis@gmail.com>
#
# $FreeBSD$

PORTNAME=	gnormalize
PORTVERSION=	0.63
PORTREVISION=	7
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	darcsis@gmail.com
COMMENT=	An alternative for replaygain

RUN_DEPENDS+=	p5-Gtk2>=0:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		wavegain:${PORTSDIR}/audio/wavegain

USE_PERL5_RUN=	yes
INSTALLS_ICONS=	yes

NO_BUILD=	yes

MAN1=		gnormalize.1

OPTIONS_DEFINE=	MP3 OGG MP4 CDPARANOIA CDDB CDPLAY PLAC MAC MUSEPACK
OPTIONS_DEFAULT=	MP3 OGG MP4

MAC_DESC=	Monkey's Audio Encoding and Playback
CDPLAY_DESC=	CD Playback

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMP3}
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame \
	p5-MP3-Info>=0:${PORTSDIR}/audio/p5-MP3-Info
.endif

.if ${PORT_OPTIONS:MOGG}
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.if ${PORT_OPTIONS:MMP4}
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac \
	faad:${PORTSDIR}/audio/faad
.endif

.if ${PORT_OPTIONS:MCDPARANOIA} || ${PORT_OPTIONS:MCDDA2WAV}
USE_CDRTOOLS=	yes
.else
RUN_DEPENDS+=	cdparanoia:${PORTSDIR}/audio/cdparanoia
.endif

.if ${PORT_OPTIONS:MCDDB}
RUN_DEPENDS+=	cddb.pl:${PORTSDIR}/audio/p5-CDDB_get
.endif

.if ${PORT_OPTIONS:MCDPLAY}
RUN_DEPENDS+=	p5-Audio-CD>=0:${PORTSDIR}/audio/p5-Audio-CD
.endif

.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if ${PORT_OPTIONS:MMAC}
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
.endif

.if ${PORT_OPTIONS:MMUSEPACK}
RUN_DEPENDS+=	mppenc:${PORTSDIR}/audio/musepack
.endif

.if ${OSVERSION} < 800505 || (${OSVERSION} >= 900000 && ${OSVERSION} < 900012)
BUILD_DEPENDS+=	lzma:${PORTSDIR}/archivers/xz
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,^PREFIX=.*,PREFIX=${PREFIX},; \
		s,^MANDIR=.*,MANDIR=${MANPREFIX}/man,; \
		s,^BASE=.*,BASE=${DATADIR},' \
		${WRKSRC}/Makefile
	@${REINPLACE_CMD} -e 's,/usr/share/gnormalize,${DATADIR},' \
		${WRKSRC}/gnormalize

.include <bsd.port.mk>
