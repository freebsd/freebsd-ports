# Created by: Hardy Schumacher <hardy.schumacher@gmx.de>
# $FreeBSD$

PORTNAME=	kcemu
PORTVERSION=	0.5.1
PORTREVISION=	7
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/KCemu/KCemu-${PORTVERSION}
DISTNAME=	KCemu-${PORTVERSION}

MAINTAINER=	hardy.schumacher@gmx.de
COMMENT=	KC85 emulator

BUILD_DEPENDS=	pngtopnm:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile \
		libavformat.so:${PORTSDIR}/multimedia/ffmpeg \
		libdirac_encoder.so:${PORTSDIR}/multimedia/dirac \
		libschroedinger-1.0.so:${PORTSDIR}/multimedia/schroedinger \
		libsndfile.so:${PORTSDIR}/audio/libsndfile \
		libtheora.so:${PORTSDIR}/multimedia/libtheora \
		libvncserver.so:${PORTSDIR}/net/libvncserver \
		libxvidcore.so:${PORTSDIR}/multimedia/xvid \
		libz80ex.so:${PORTSDIR}/devel/z80ex

GNU_CONFIGURE=	yes
USE_XORG=	xmu
USE_GNOME=	gtk20
USES=		gettext pkgconfig

LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/KCemu-${PORTVERSION}

CONFIGURE_ARGS+=--disable-libmp3lame \
		--disable-libflac \
		--disable-libgif

DESKTOP_ENTRIES="KCemu" "${COMMENT}" \
		"${LOCALBASE}/share/KCemu/icons/kcemu-icon.png" "kcemu" \
		"System;Emulator;" "true"

BROKEN=		Does not build with ffmpeg-2.7

.include <bsd.port.mk>
