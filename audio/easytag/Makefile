# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	easytag
PORTVERSION=	2.1.8
PORTREVISION=	2
CATEGORIES=	audio
MASTER_SITES=	GNOME

MAINTAINER=	novel@FreeBSD.org
COMMENT=	GTK2 Tag editor for MP3 and OGG files

LICENSE=	GPLv2

LIB_DEPENDS=	libid3.so:${PORTSDIR}/audio/id3lib \
		libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libtag.so:${PORTSDIR}/audio/taglib

CONFLICTS=	easytag-devel-[0-9]*

USE_XZ=		yes
USES=		gmake pkgconfig pathfix desktop-file-utils
USE_GNOME=	gtk20
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_GTK
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	WAVPACK NLS

OPTIONS_SUB=	yes
WAVPACK_LIB_DEPENDS=	libwavpack.so:${PORTSDIR}/audio/wavpack
WAVPACK_CONFIGURE_ENABLE=	wavpack
NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

.include <bsd.port.mk>
