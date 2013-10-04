# Created by: mwest@uct.ac.za
# $FreeBSD$

PORTNAME=	libgii
PORTVERSION=	1.0.2
PORTREVISION=	3
CATEGORIES=	devel
MASTER_SITES=	SF/ggi/ggi-core/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	GGI API for input sources

LICENSE=	MIT

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
USE_BZIP2=	yes
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

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
	${INSTALL_DATA} ${WRKSRC}/libgii.conf ${STAGEDIR}${PREFIX}/etc/ggi/libgii.conf.dist
	${INSTALL_DATA} ${WRKSRC}/filter/mouse/mouse ${STAGEDIR}${PREFIX}/etc/ggi/filter/mouse.dist
	${INSTALL_DATA} ${WRKSRC}/filter/keytrans/keytrans ${STAGEDIR}${PREFIX}/etc/ggi/filter/keytrans.dist

.include <bsd.port.mk>
