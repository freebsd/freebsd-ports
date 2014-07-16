# Created by: mwest@uct.ac.za
# $FreeBSD$

PORTNAME=	libggi
PORTVERSION=	2.2.2
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	graphics devel
MASTER_SITES=	SF/ggi/ggi-core/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	antoine@FreeBSD.org
COMMENT=	Flexible drawing library

LICENSE=	MIT

LIB_DEPENDS=	libgii.so:${PORTSDIR}/devel/libgii

USES=		libtool:keepla tar:bzip2
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-directfb
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
LDFLAGS+=	${PTHREAD_LIBS}
INSTALL_TARGET=	install-strip


OPTIONS_DEFINE=	AALIB SVGALIB X11
OPTIONS_DEFAULT=X11

.include <bsd.port.options.mk>

.if exists(/usr/include/dev/kgi/kgi.h)
CONFIGURE_ARGS+=--enable-kgi --with-extra-includes=/usr/include/dev
.endif

.if ${PORT_OPTIONS:MX11}
CONFIGURE_ARGS+=--enable-x --with-x
USE_XORG=	x11 xxf86dga xxf86vm ice sm xau xext
PLIST_SUB+=	WITH_X=""
.else
CONFIGURE_ARGS+=--disable-x --without-x
PLIST_SUB+=	WITH_X="@comment "
.endif

.if exists(/usr/include/vgl.h) && (${ARCH} == "i386" || ${ARCH} == "amd64")
CONFIGURE_ARGS+=--enable-vgl
PLIST_SUB+=	WITH_VGL=""
.else
CONFIGURE_ARGS+=--disable-vgl
PLIST_SUB+=	WITH_VGL="@comment "
.endif

.if ${PORT_OPTIONS:MAALIB}
CONFIGURE_ARGS+=--enable-aa
LIB_DEPENDS+=	libaa.so:${PORTSDIR}/graphics/aalib
PLIST_SUB+=	WITH_AALIB=""
.else
CONFIGURE_ARGS+=--disable-aa
PLIST_SUB+=	WITH_AALIB="@comment "
.endif

.if ${PORT_OPTIONS:MSVGALIB}
CONFIGURE_ARGS+=--enable-vgagl --enable-svga
LIB_DEPENDS+=	libvga.so:${PORTSDIR}/graphics/svgalib
PLIST_SUB+=	WITH_SVGALIB=""
.else
CONFIGURE_ARGS+=--disable-vgagl --disable-svga
PLIST_SUB+=	WITH_SVGALIB="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} '/^exttest1_LDADD =/s/$$/ -lgg/' \
		${WRKSRC}/extensions/test/Makefile.in
	@${REINPLACE_CMD} '/^showaccel_LDADD =/ { \
		p; s/showaccel/palette/; p; s/palette/cbconsist/; }' \
		${WRKSRC}/programs/check/Makefile.in
	@${REINPLACE_CMD} '/^cube3d_LDADD =/s/$$/ -lgii/' \
		${WRKSRC}/programs/demos/Makefile.in
	@${REINPLACE_CMD} '/^LDADD =/s/$$/ -lgii/' \
		${WRKSRC}/programs/regress/Makefile.in
	@${REINPLACE_CMD} '/^inputdump_LDADD =/s/$$/ -lgii/' \
		${WRKSRC}/programs/util/Makefile.in
	@${REINPLACE_CMD} '/^ggiteleserver_LDADD =/s/$$/ -lgg/' \
		${WRKSRC}/programs/util/ggiteleserver/Makefile.in

post-install:
	${TOUCH} ${STAGEDIR}${PREFIX}/lib/ggi/default/fbdev/.keep
	${TOUCH} ${STAGEDIR}${PREFIX}/lib/ggi/default/kgi/.keep
	${TOUCH} ${STAGEDIR}${PREFIX}/lib/ggi/helper/.keep
	${MV} ${STAGEDIR}${PREFIX}/etc/ggi/libggi.conf ${STAGEDIR}${PREFIX}/etc/ggi/libggi.conf.sample

.include <bsd.port.mk>
