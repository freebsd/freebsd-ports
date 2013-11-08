# Created by: Hardy Schumacher <hardy.schumacher@gmx.de>
# $FreeBSD$

PORTNAME=	kcemu
PORTVERSION=	0.5.1
PORTREVISION=	5
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/KCemu/KCemu-${PORTVERSION}
DISTNAME=	KCemu-${PORTVERSION}

MAINTAINER=	hardy.schumacher@gmx.de
COMMENT=	KC85 emulator

BUILD_DEPENDS=	pngtopnm:${PORTSDIR}/graphics/netpbm
LIB_DEPENDS=	libaudiofile.so:${PORTSDIR}/audio/libaudiofile \
		avformat.1:${PORTSDIR}/multimedia/ffmpeg \
		dirac_encoder.1:${PORTSDIR}/multimedia/dirac \
		schroedinger-1.0:${PORTSDIR}/multimedia/schroedinger \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		theora:${PORTSDIR}/multimedia/libtheora \
		vncserver:${PORTSDIR}/net/libvncserver \
		xvidcore.4:${PORTSDIR}/multimedia/xvid \
		z80ex.1:${PORTSDIR}/devel/z80ex

GNU_CONFIGURE=	yes
USE_XORG=	xmu
USE_GNOME=	gtk20
USES=		gettext pkgconfig

MAN1=		kctape.1 kc2raw.1 kc2img.1 kc2tap.1 tdtodump.1 \
		kcemu-remote.1 kcemu.1x kc2wav.1

LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/KCemu-${PORTVERSION}

CONFIGURE_ARGS+=--disable-libmp3lame \
		--disable-libflac \
		--disable-libgif

DESKTOP_ENTRIES="KCemu" "${COMMENT}" \
		"${LOCALBASE}/share/KCemu/icons/kcemu-icon.png" "kcemu" \
		"System;Emulator;" "true"

NO_STAGE=	yes
.include <bsd.port.mk>
