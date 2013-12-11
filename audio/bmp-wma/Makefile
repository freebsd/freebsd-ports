# Created by: Roman Bogorodskiy <bogorodskiy@inbox.ru>
# $FreeBSD$

PORTNAME=	bmp-wma
PORTVERSION=	0.1.1
PORTREVISION=	10
CATEGORIES=	audio
MASTER_SITES=	http://download.berlios.de/bmp-plugins/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	WMA input plugin for beep-media-player

LIB_DEPENDS=	libbeep.so:${PORTSDIR}/multimedia/beep-media-player

PLIST_FILES=	lib/bmp/Input/libwma.so \
		lib/bmp/Input/libwma.la \
		lib/bmp/Input/libwma.a

NO_STAGE=	yes
USES=		pkgconfig
GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool

.include <bsd.port.pre.mk>

.if ${ARCH} == "i386"
CONFIGURE_ARGS+=	--enable-x86
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fpic -DPIC
.endif

.include <bsd.port.post.mk>
