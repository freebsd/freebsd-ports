# Created by: Stephen Hurd <shurd@sasktel.net>
# $FreeBSD$

PORTNAME=	fllog
PORTVERSION=	1.1.8
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/downloads/fllog/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	shurd@sasktel.net
COMMENT=	Ham Radio logging program

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"

OPTIONS_DEFINE=	NATIVE_OPT

NATIVE_OPT_DESC=	Enable Native Optimizations

.include <bsd.port.pre.mk>

PLIST_FILES=	bin/fllog \
		share/applications/fllog.desktop \
		share/pixmaps/fllog.xpm

.if ${PORT_OPTIONS:MNATIVE_OPT}
CONFIGURE_ARGS+=--enable-optimizations=native
.else
CONFIGURE_ARGS+=--enable-optimizations=none
.endif

.include <bsd.port.mk>
