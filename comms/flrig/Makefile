# Created by: Stephen Hurd <shurd@sasktel.net>
# $FreeBSD$

PORTNAME=	flrig
PORTVERSION=	1.3.13
CATEGORIES=	comms hamradio
MASTER_SITES=	http://www.w1hkj.com/downloads/flrig/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	db

MAINTAINER=	shurd@sasktel.net
COMMENT=	Ham Radio rig control program, cooperates with fldigi

LICENSE=	GPLv2

LIB_DEPENDS=	libfltk.so:${PORTSDIR}/x11-toolkits/fltk

USES=		gmake
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	FLTK_CONFIG="${LOCALBASE}/bin/fltk-config"
PLIST_FILES=	bin/flrig share/applications/flrig.desktop \
		 share/pixmaps/flrig.xpm
OPTIONS_DEFINE=	NATIVE_OPT

NATIVE_OPT_DESC=	Enable Native Optimizations

.include <bsd.port.pre.mk>

.if ${PORT_OPTIONS:MNATIVE_OPT}
CONFIGURE_ARGS+=--enable-optimizations=native
.else
CONFIGURE_ARGS+=--enable-optimizations=none
.endif

.include <bsd.port.mk>
