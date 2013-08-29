# Created by: Adam Weinberger <adamw@FreeBSD.org>
# $FreeBSD$

PORTNAME=	easytag
PORTVERSION=	2.1.8
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	GNOME

MAINTAINER=	novel@FreeBSD.org
COMMENT=	GTK2 Tag editor for MP3 and OGG files

LIB_DEPENDS=	libid3.so:${PORTSDIR}/audio/id3lib \
		libid3tag.so:${PORTSDIR}/audio/libid3tag \
		libvorbis.so:${PORTSDIR}/audio/libvorbis \
		libFLAC.so:${PORTSDIR}/audio/flac \
		libmp4v2.so:${PORTSDIR}/multimedia/mp4v2

MAN1=		easytag.1
CONFLICTS=	easytag-devel-[0-9]*

USE_XZ=		yes
USES=		gettext gmake
USE_GNOME=	gnomehack gnomeprefix gtk20 desktopfileutils
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include -DHAVE_GTK
LDFLAGS+=	-L${LOCALBASE}/lib

OPTIONS_DEFINE=	WAVPACK

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MWAVPACK}
LIB_DEPENDS+=		wavpack:${PORTSDIR}/audio/wavpack
CONFIGURE_ARGS+=	--enable-wavpack
.else
CONFIGURE_ARGS+=	--disable-wavpack
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|<mp4\.h>|<mp4v2/mp4v2.h>|g' \
		${WRKSRC}/src/mp4_header.c \
		${WRKSRC}/src/mp4_tag.c

.include <bsd.port.mk>
