PORTNAME=	flrig
PORTVERSION=	2.0.04
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/${PORTNAME} \
		http://www.w1hkj.com/files/fldigi/

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Ham Radio rig control program, cooperates with fldigi
WWW=		http://www.w1hkj.com/flrig-help/index.html

LICENSE=	GPLv2

LIB_DEPENDS=	libpng.so:graphics/png \
		libfontconfig.so:x11-fonts/fontconfig \
		libfltk.so:x11-toolkits/fltk \
		libudev.so:devel/libudev-devd

USES=		gmake jpeg xorg desktop-file-utils
USE_XORG=	x11 xrender xcursor xfixes xext xft xinerama

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"
PLIST_FILES=	bin/flrig share/applications/flrig.desktop \
		 share/pixmaps/flrig.xpm
OPTIONS_DEFINE=	NATIVE

NATIVE_CONFIGURE_ON+=	--enable-optimizations=native
NATIVE_CONFIGURE_OFF+=	--enable-optimizations=none

.include <bsd.port.pre.mk>

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv1
CFLAGS+=	-mminimal-toc
.endif

.include <bsd.port.post.mk>
