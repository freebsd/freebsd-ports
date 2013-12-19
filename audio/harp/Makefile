# $FreeBSD$

PORTNAME=	harp
PORTVERSION=	0.5.2
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	heckendorfc@gmail.com
COMMENT=	Minimalist audio player

LICENSE=	GPLv3

GNU_CONFIGURE=	yes

USE_SQLITE=	yes
NO_STAGE=	yes

USE_LDCONFIG=	yes

OPTIONS_DEFINE=	AAC FLAC MP3 SHOUTCAST VORBIS JACK
OPTIONS_DEFAULT=	AAC FLAC MP3 SHOUTCAST VORBIS

MAN1=		harp.1
PORTDOCS=	README

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MAAC}
LIB_DEPENDS+=	libfaad.so:${PORTSDIR}/audio/faad
PLIST_SUB+=	AAC=""
.else
CONFIGURE_ARGS+=	--without-aac
PLIST_SUB+=	AAC="@comment "
.endif

.if ${PORT_OPTIONS:MFLAC}
LIB_DEPENDS+=	libFLAC.so:${PORTSDIR}/audio/flac
PLIST_SUB+=	FLAC=""
.else
CONFIGURE_ARGS+=	--without-flac
PLIST_SUB+=	FLAC="@comment "
.endif

.if ${PORT_OPTIONS:MMP3}
LIB_DEPENDS+=	libmpg123.so:${PORTSDIR}/audio/mpg123
PLIST_SUB+=	MP3=""
.else
CONFIGURE_ARGS+=	--without-mp3
PLIST_SUB+=	MP3="@comment "
.endif

.if ${PORT_OPTIONS:MSHOUTCAST}
PLIST_SUB+=	STREAM=""
.else
CONFIGURE_ARGS+=	--without-stream
PLIST_SUB+=	STREAM="@comment "
.endif

.if ${PORT_OPTIONS:MVORBIS}
LIB_DEPENDS+=	libvorbisfile.so:${PORTSDIR}/audio/libvorbis
PLIST_SUB+=	VORBIS=""
.else
CONFIGURE_ARGS+=	--without-vorbis
PLIST_SUB+=	VORBIS="@comment "
.endif

.if ${PORT_OPTIONS:MJACK}
CONFIGURE_ARGS+=	--with-jack
LIB_DEPENDS+=	libjack.so:${PORTSDIR}/audio/jack
.else
CONFIGURE_ARGS+=	--without-jack
.endif

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
.endif

.include <bsd.port.mk>
