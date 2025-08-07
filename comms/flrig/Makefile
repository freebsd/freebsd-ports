PORTNAME=	flrig
DISTVERSION=	2.0.08
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/${PORTNAME} \
		https://www.w1hkj.org/files/fldigi/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Ham Radio rig control program, cooperates with fldigi
WWW=		https://www.w1hkj.org/flrig-help/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk \
		libfontconfig.so:x11-fonts/fontconfig \
		libpng.so:graphics/png \
		libudev.so:devel/libudev-devd

USES=		desktop-file-utils gmake jpeg xorg
USE_XORG=	x11 xcursor xext xfixes xft xinerama xrender

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"

PLIST_FILES=	bin/flrig \
		share/applications/flrig.desktop \
		share/pixmaps/flrig.xpm

OPTIONS_DEFINE=	NATIVE

NATIVE_CONFIGURE_ON=	--enable-optimizations=native
NATIVE_CONFIGURE_OFF=	--enable-optimizations=none

.include <bsd.port.mk>
