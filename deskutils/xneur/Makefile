# Created by: Alex "lissyara" Keda <admin@lissyara.su>
# $FreeBSD$

PORTNAME=	xneur
PORTVERSION=	0.15.0
PORTREVISION=	3
CATEGORIES=	deskutils
MASTER_SITES=	http://dists.xneur.ru/release-${DISTVERSION}/tgz/ \
		http://mirror.amdmi3.ru/distfiles/

MAINTAINER=	admin@lissyara.su
COMMENT=	Auto keyboard switcher

LIB_DEPENDS=	libnotify.so:${PORTSDIR}/devel/libnotify \
		libpcre.so:${PORTSDIR}/devel/pcre

USE_BZIP2=	yes
USES=		pkgconfig iconv
USE_GNOME=	gnomehack
GNU_CONFIGURE=	yes
LDFLAGS+=	-L${LOCALBASE}/lib ${PTHREAD_LIBS}
CPPFLAGS+=	-I${LOCALBASE}/include ${PTHREAD_CFLAGS}
CONFIGURE_ARGS=	--disable-static --libdir=${PREFIX}/lib/xneur

USE_LDCONFIG=	yes
INSTALLS_ICONS=	yes

MAN1=		xneur.1
MAN5=		xneurrc.5

OPTIONS_DEFINE=	ASPELL XOSD NLS X11
OPTIONS_DEFAULT=	GSTREAMER ASPELL
OPTIONS_RADIO=	SOUND
OPTIONS_RADIO_SOUND=	GSTREAMER OPENAL
XOSD_DESC=	Xosd support

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=	gettext
CONFIGURE_ARGS+=	--enable-nls
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=	--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MX11}
USE_XORG+=	x11
CONFIGURE_ARGS+=	--with-x
.else
CONFIGURE_ARGS+=	--without-x
.endif

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=	--with-sound=gstreamer
.elif ${PORT_OPTIONS:MOPENAL}
USES+=			openal:al,alut
CONFIGURE_ARGS+=	--with-sound=openal
.else
CONFIGURE_ARGS+=	--with-sound=no
.endif

.if ${PORT_OPTIONS:MASPELL}
LIB_DEPENDS+=	libaspell.so:${PORTSDIR}/textproc/aspell
CONFIGURE_ARGS+=	--with-spell=aspell
.else
CONFIGURE_ARGS+=	--with-spell=no --without-aspell
.endif

.if ${PORT_OPTIONS:MXOSD}
LIB_DEPENDS+=	libxosd.so:${PORTSDIR}/misc/xosd
CONFIGURE_ARGS+=	--with-xosd
.else
CONFIGURE_ARGS+=	--without-xosd
.endif

post-patch:
	@${MV} ${WRKSRC}/etc/xneurrc ${WRKSRC}/etc/xneurrc.sample

post-install:
.if !exists(${PREFIX}/etc/xneur/xneurrc)
	${CP} -p ${PREFIX}/etc/xneur/xneurrc.sample ${PREFIX}/etc/xneur/xneurrc
.endif

.include <bsd.port.mk>
