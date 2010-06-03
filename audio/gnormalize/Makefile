# New ports collection makefile for:	gnormalize
# Date created:				27 Oct 2007
# Whom:				Denise H. G. <darcsis@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gnormalize
PORTVERSION=	0.63
PORTREVISION=	5
CATEGORIES=	audio
MASTER_SITES=	SF

MAINTAINER=	darcsis@gmail.com
COMMENT=	An alternative for replaygain

RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Gtk2.pm:${PORTSDIR}/x11-toolkits/p5-Gtk2 \
		wavegain:${PORTSDIR}/audio/wavegain

USE_PERL5_RUN=	yes
INSTALLS_ICONS=	yes

NO_BUILD=	yes

MAN1=		gnormalize.1

OPTIONS=	\
	GNORMALIZE_MP3	"WAV <-> MP3 Support"	on	\
	GNORMALIZE_OGG	"Ogg Encoding and Playback"	on	\
	GNORMALIZE_MP4	"WAV <-> MP4 Support"	on	\
	GNORMALIZE_CDRIP	"CD Ripping"	off	\
	GNORMALIZE_CDDB	"CDDB Support"	off	\
	GNORMALIZE_CDPLAY	"CD Playback"	off	\
	GNORMALIZE_FLAC	"FLAC Encoding and Playback"	off	\
	GNORMALIZE_MAC	"Monkey's Audio Encoding and Playback"	off	\
	GNORMALIZE_MPC	"MPC (musepack) Audio"	off

.include <bsd.port.pre.mk>

.if defined(WITH_GNORMALIZE_MP3)
RUN_DEPENDS+=	lame:${PORTSDIR}/audio/lame \
	${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info
.endif

.if defined(WITH_GNORMALIZE_OGG)
RUN_DEPENDS+=	oggenc:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_GNORMALIZE_MP4)
RUN_DEPENDS+=	faac:${PORTSDIR}/audio/faac \
	faad:${PORTSDIR}/audio/faad
.endif

.if defined(WITH_GNORMALIZE_CDRIP)
.if defined(WITH_CDDA2WAV)
RUN_DEPENDS+=	cdda2wav:${PORTSDIR}/sysutils/cdrtools
.else
RUN_DEPENDS+=	cdparanoia:${PORTSDIR}/audio/cdparanoia
.endif
.endif

.if defined(WITH_GNORMALIZE_CDDB)
RUN_DEPENDS+=	cddb.pl:${PORTSDIR}/audio/p5-CDDB_get
.endif

.if defined(WITH_GNORMALIZE_CDPLAY)
RUN_DEPENDS+=	${SITE_PERL}/${PERL_ARCH}/Audio/CD.pm:${PORTSDIR}/audio/p5-Audio-CD
.endif

.if defined(WITH_GNORMALIZE_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if defined(WITH_GNORMALIZE_MAC)
RUN_DEPENDS+=	mac:${PORTSDIR}/audio/mac
.endif

.if defined(WITH_GNORMALIZE_MPC)
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

.include <bsd.port.post.mk>
