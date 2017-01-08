# Created by: Stephen Hurd <shurd@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fllog
PORTVERSION=	1.2.4
CATEGORIES=	comms hamradio
MASTER_SITES=	SF/fldigi/${PORTNAME}

MAINTAINER=	hamradio@FreeBSD.org
COMMENT=	Ham Radio logging program

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"

OPTIONS_DEFINE=	NATIVE_OPT

NATIVE_OPT_DESC=	Enable Native Optimizations

PLIST_FILES=	bin/fllog \
		share/applications/fllog.desktop \
		share/pixmaps/fllog.xpm

NATIVE_OPT_CONFIGURE_ON=	--enable-optimizations=native
NATIVE_OPT_CONFIGURE_OFF=	--enable-optimizations=none

.include <bsd.port.mk>
