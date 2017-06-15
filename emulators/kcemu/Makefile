# Created by: Hardy Schumacher <hardy.schumacher@gmx.de>
# $FreeBSD$

PORTNAME=	kcemu
PORTVERSION=	0.5.1
PORTREVISION=	11
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/KCemu/KCemu-${PORTVERSION}
DISTNAME=	KCemu-${PORTVERSION}

MAINTAINER=	hardy.schumacher@gmx.de
COMMENT=	KC85 emulator

BUILD_DEPENDS=	pngtopnm:graphics/netpbm
LIB_DEPENDS=	libaudiofile.so:audio/libaudiofile \
		libavformat.so:multimedia/ffmpeg \
		libdirac_encoder.so:multimedia/dirac \
		libschroedinger-1.0.so:multimedia/schroedinger \
		libsndfile.so:audio/libsndfile \
		libtheora.so:multimedia/libtheora \
		libvncserver.so:net/libvncserver \
		libxvidcore.so:multimedia/xvid \
		libz80ex.so:devel/z80ex

GNU_CONFIGURE=	yes
USE_XORG=	xmu
USE_GNOME=	gtk20
USES=		gettext ncurses pkgconfig

LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/KCemu-${PORTVERSION}

CONFIGURE_ARGS+=--disable-libmp3lame \
		--disable-libflac \
		--disable-libgif

DESKTOP_ENTRIES="KCemu" "${COMMENT}" \
		"${LOCALBASE}/share/KCemu/icons/kcemu-icon.png" "kcemu" \
		"System;Emulator;" "true"

.include <bsd.port.mk>
