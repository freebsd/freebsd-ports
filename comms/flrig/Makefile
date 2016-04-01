# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	flrig
PORTVERSION=	1.3.22
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/downloads/flrig/ \
		LOCAL/db

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Ham Radio rig control program, cooperates with fldigi

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"
PLIST_FILES=	bin/flrig share/applications/flrig.desktop \
		 share/pixmaps/flrig.xpm
OPTIONS_DEFINE=	NATIVE_OPT

NATIVE_OPT_DESC=	Enable Native Optimizations

NATIVE_OPT_CONFIGURE_ON+=	--enable-optimizations=native
NATIVE_OPT_CONFIGURE_OFF+=	--enable-optimizations=none

.include <bsd.port.mk>
