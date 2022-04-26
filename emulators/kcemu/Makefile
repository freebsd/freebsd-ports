# Created by: Hardy Schumacher <hardy.schumacher@gmx.de>

PORTNAME=	kcemu
PORTVERSION=	0.5.1
PORTREVISION=	20
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/KCemu/KCemu-${PORTVERSION}
DISTNAME=	KCemu-${PORTVERSION}

MAINTAINER=	hardy.schumacher@gmx.de
COMMENT=	KC85 emulator

DEPRECATED=	Depends on expired multimedia/schroedinger
EXPIRATION_DATE=2022-06-30

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

USES=		compiler:c++11-lang gettext gnome ncurses pkgconfig xorg
USE_CXXSTD=	gnu++98
USE_GNOME=	gtk20
USE_XORG=	xmu
GNU_CONFIGURE=	yes

LDFLAGS+=	-L${LOCALBASE}/lib
WRKSRC=		${WRKDIR}/KCemu-${PORTVERSION}

CONFIGURE_ARGS+=--disable-libmp3lame \
		--disable-libflac \
		--disable-libgif

DESKTOP_ENTRIES="KCemu" "${COMMENT}" \
		"${LOCALBASE}/share/KCemu/icons/kcemu-icon.png" "kcemu" \
		"System;Emulator;" "true"

.include <bsd.port.mk>
