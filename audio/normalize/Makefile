# Created by: George Reid <greid@ukug.uk.freebsd.org>
# $FreeBSD$

PORTNAME=	normalize
PORTVERSION=	0.7.7
PORTREVISION=	6
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	alex@fafula.com
COMMENT=	A tool for adjusting the volume of wave/MP3 files to a standard level

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad

USE_BZIP2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ARGS=		--disable-helper-search
CPPFLAGS+=		-I${LOCALBASE}/include
LDFLAGS+=		-L${LOCALBASE}/lib
MAKE_JOBS_UNSAFE=	yes

MAN1=		normalize.1 normalize-mp3.1

OPTIONS_DEFINE=	XMMS MP3 OGG FLAC NLS
OPTIONS_DEFAULT=	MP3
XMMS_DESC=	XMMS plugin

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MXMMS}
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--disable-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

.if ${PORT_OPTIONS:MMP3}
RUN_DEPENDS+=	madplay:${PORTSDIR}/audio/madplay \
		lame:${PORTSDIR}/audio/lame
.endif

.if ${PORT_OPTIONS:MOGG}
RUN_DEPENDS+=	oggdec:${PORTSDIR}/audio/vorbis-tools
.endif

.if ${PORT_OPTIONS:MFLAC}
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.mk>
