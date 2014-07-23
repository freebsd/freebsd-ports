# Created by: mwest@uct.ac.za
# $FreeBSD$

PORTNAME=	libgii
PORTVERSION=	1.0.2
PORTREVISION=	4
CATEGORIES=	devel
MASTER_SITES=	SF/ggi/ggi-core/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	GGI API for input sources

LICENSE=	MIT

DEPRECATED=	Unmaintained upstream
EXPIRATION_DATE=	2014-09-22

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USES=		libtool:keepla tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	X11
OPTIONS_DEFAULT=X11

.include <bsd.port.options.mk>

CONFIGURE_ARGS=	--disable-linux-kbd --disable-linux-joy --disable-linux-evdev

.if exists(/usr/include/dev/kii/kii.h)
CONFIGURE_ARGS+=--enable-kii --with-extra-includes=/usr/include/dev
PLIST_SUB+=	KII=""
.else
CONFIGURE_ARGS+=--disable-kii
PLIST_SUB+=	KII="@comment "
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG=	x11 xxf86dga
CONFIGURE_ARGS+=--enable-x --with-x
PLIST_SUB+=	WITH_X=""
.else
CONFIGURE_ARGS+=--disable-x --without-x
PLIST_SUB+=	WITH_X="@comment "
.endif

.if exists(/usr/include/vgl.h) && (${ARCH} == "i386" || ${ARCH} == "amd64")
CONFIGURE_ARGS+=--enable-vgl
PLIST_SUB+=	VGL=""
.else
CONFIGURE_ARGS+=--disable-vgl
PLIST_SUB+=	VGL="@comment "
.endif

post-install:
	${MV} ${STAGEDIR}${PREFIX}/etc/ggi/libgii.conf ${STAGEDIR}${PREFIX}/etc/ggi/libgii.conf.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/ggi/filter/mouse ${STAGEDIR}${PREFIX}/etc/ggi/filter/mouse.sample
	${MV} ${STAGEDIR}${PREFIX}/etc/ggi/filter/keytrans ${STAGEDIR}${PREFIX}/etc/ggi/filter/keytrans.sample

.include <bsd.port.mk>
