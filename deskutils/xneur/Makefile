# Created by: Alex "lissyara" Keda <admin@lissyara.su>
# $FreeBSD$

PORTNAME=	xneur
PORTVERSION=	0.17.0
PORTREVISION=	3
DISTVERSIONSUFFIX=.orig
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpad.net/~andrew-crew-kuznetsov/+archive/xneur-stable/+files/
DISTNAME=	${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	admin@lissyara.su
COMMENT=	Auto keyboard switcher

LICENSE=	GPLv2

LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libpcre.so:devel/pcre

USES=		compiler:nestedfct iconv libtool localbase pathfix pkgconfig
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --libdir=${PREFIX}/lib/xneur

USE_LDCONFIG=	${PREFIX}/lib/xneur ${PREFIX}/lib/xneur/xneur
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	ASPELL XOSD NLS X11
OPTIONS_DEFAULT=	GSTREAMER ASPELL
OPTIONS_RADIO=	SOUND
OPTIONS_RADIO_SOUND=	GSTREAMER OPENAL
XOSD_DESC=	Xosd support

OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

X11_USE=		XORG=x11
X11_CONFIGURE_WITH=	x

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_ON=	--with-spell=aspell
ASPELL_CONFIGURE_OFF=	--with-spell=no --without-aspell

XOSD_LIB_DEPENDS=	libxosd.so:misc/xosd
XOSD_CONFIGURE_WITH=	xosd

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGSTREAMER}
USE_GSTREAMER=	yes
CONFIGURE_ARGS+=	--with-sound=gstreamer
.elif ${PORT_OPTIONS:MOPENAL}
USES+=			openal:al,alut
CONFIGURE_ARGS+=	--with-sound=openal
.else
CONFIGURE_ARGS+=	--with-sound=no
.endif

post-patch:
	@${REINPLACE_CMD} -e 's,-Werror,,g; s,-ldl,,g' ${WRKSRC}/configure
	@${MV} ${WRKSRC}/etc/xneurrc ${WRKSRC}/etc/xneurrc.sample

.include <bsd.port.mk>
