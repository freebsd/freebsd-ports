# Created by: joerg
# $FreeBSD$

PORTNAME=	xcpc
PORTVERSION=	20070122
PORTREVISION=	15
CATEGORIES=	emulators
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}

MAINTAINER=	pixel@hugbox.org
COMMENT=	Portable Amstrad 464&/664/6128 emulator

HAS_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ARGS+=--prefix=${PREFIX}

USE_XORG=	ice
USE_GNOME=	glib20
USES=		gettext iconv pkgconfig

LIB_DEPENDS+=	libpcre.so:devel/pcre \
		libdsk.so:emulators/libdsk

OPTIONS_DEFINE=	MOTIF ATHENA XSHM DEBUG
OPTIONS_DEFAULT=	MOTIF XSHM
MOTIF_DESC=	With Motif widget set
ATHENA_DESC=	With Athen widget set
XSHM_DESC=	With XShm support

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=--enable-debug
.else
CONFIGURE_ARGS+=--disable-debug
.endif

.if ${PORT_OPTIONS:MXSHM}
CONFIGURE_ARGS+=--enable-xshm
.else
CONFIGURE_ARGS+=--disable-xshm
.endif

.if ${PORT_OPTIONS:MMOTIF}
USES+=	motif
CONFIGURE_ARGS+=--with-motif1
.else
CONFIGURE_ARGS+=--without-motif1
.endif

.if ${PORT_OPTIONS:MATHENA}
LIB_DEPENDS+=	libXaw.so:x11-toolkits/libXaw
CONFIGURE_ARGS+=--with-athena
.else
CONFIGURE_ARGS+=--without-athena
.endif

.include <bsd.port.mk>
