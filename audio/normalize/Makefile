# New ports collection makefile for:   normalize
# Date created:        31 January 2001
# Whom:                George Reid <greid@ukug.uk.freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	normalize
PORTVERSION=	0.7.7
PORTREVISION=	4
CATEGORIES=	audio
MASTER_SITES=	SAVANNAH

MAINTAINER=	alex@fafula.com
COMMENT=	A tool for adjusting the volume of wave/MP3 files to a standard level

LIB_DEPENDS=	mad.2:${PORTSDIR}/audio/libmad

USE_BZIP2=		yes
GNU_CONFIGURE=		yes
CONFIGURE_ENV=		CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CONFIGURE_ARGS=		--disable-helper-search
CPPFLAGS=		-I${LOCALBASE}/include
LDFLAGS=		-L${LOCALBASE}/lib

MAN1=		normalize.1 normalize-mp3.1

OPTIONS=	XMMS "Build XMMS plugin" off \
		MP3 "MP3 support" on \
		OGG "OGG support" off \
		FLAG "FLAC support" off

.include <bsd.port.pre.mk>

.if defined(WITH_XMMS)
LIB_DEPENDS+=	xmms.4:${PORTSDIR}/multimedia/xmms
PLIST_SUB+=	XMMS=""
.else
CONFIGURE_ARGS+=--disable-xmms
PLIST_SUB+=	XMMS="@comment "
.endif

.if defined(WITH_MP3)
RUN_DEPENDS+=	madplay:${PORTSDIR}/audio/madplay \
		lame:${PORTSDIR}/audio/lame
.endif

.if defined(WITH_OGG)
RUN_DEPENDS+=	oggdec:${PORTSDIR}/audio/vorbis-tools
.endif

.if defined(WITH_FLAC)
RUN_DEPENDS+=	flac:${PORTSDIR}/audio/flac
.endif

.if !defined(WITHOUT_NLS)
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.include <bsd.port.post.mk>
