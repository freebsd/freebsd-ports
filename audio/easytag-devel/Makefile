# New ports collection makefile for:	easytag-devel
# Date created:				15 Feb 2005
# Whom:					Adam Weinberger <adamw@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	easytag
PORTVERSION=	2.1.6
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}%20unstable%20%28gtk%202%29/${PORTVERSION}
PKGNAMESUFFIX=	-devel

MAINTAINER=	novel@FreeBSD.org
COMMENT=	GTK2 Tag editor for MP3 and OGG files

LIB_DEPENDS=	id3tag:${PORTSDIR}/audio/libid3tag \
		vorbis:${PORTSDIR}/audio/libvorbis \
		FLAC:${PORTSDIR}/audio/flac \
		mp4v2:${PORTSDIR}/multimedia/mpeg4ip-libmp4v2

MAN1=		easytag.1
CONFLICTS=	easytag-[0-9]*

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_GNOME=	gnomehack gnomeprefix gtk20 desktopfileutils
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -DHAVE_GTK" \
		LDFLAGS="-L${LOCALBASE}/lib"

.if defined(WITH_WAVPACK)
LIB_DEPENDS+=		wavpack.1:${PORTSDIR}/audio/wavpack
CONFIGURE_ARGS+=	--enable-wavpack
.else
CONFIGURE_ARGS+=	--disable-wavpack
.endif

.if defined(WITHOUT_ID3V23)
CONFIGURE_ARGS+=	--disable-id3v23
.else
LIB_DEPENDS+=		id3:${PORTSDIR}/audio/id3lib
.endif

.include <bsd.port.mk>
