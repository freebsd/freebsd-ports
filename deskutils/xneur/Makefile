# Created by: Alex "lissyara" Keda <admin@lissyara.su>
# $FreeBSD$

PORTNAME=	xneur
PORTVERSION=	0.20.0
PORTREVISION=	1
DISTVERSIONSUFFIX=.orig
CATEGORIES=	deskutils
MASTER_SITES=	https://launchpad.net/~andrew-crew-kuznetsov/+archive/xneur-stable/+files/
DISTNAME=	${PORTNAME}_${DISTVERSIONPREFIX}${DISTVERSION}${DISTVERSIONSUFFIX}

MAINTAINER=	mizhka@gmail.com
COMMENT=	Auto keyboard switcher

LICENSE=	GPLv2

BUILD_DEPENDS=	intltool-update:textproc/intltool
LIB_DEPENDS=	libnotify.so:devel/libnotify \
		libpcre.so:devel/pcre

USES=		compiler:nestedfct gnome iconv libtool localbase pathfix \
		pkgconfig xorg
USE_GNOME=	gtk20

USE_XORG=	xtst

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --libdir=${PREFIX}/lib/xneur --with-gtk=gtk2
CFLAGS_mips=	-fnested-functions
CFLAGS_mips64=	-fnested-functions
CFLAGS_powerpc=	-fnested-functions
CFLAGS_powerpcspe=	-fnested-functions
CFLAGS_powerpc64=	-fnested-functions
CFLAGS_sparc64=	-fnested-functions

USE_LDCONFIG=	${PREFIX}/lib/xneur ${PREFIX}/lib/xneur/xneur
INSTALLS_ICONS=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	ASPELL XOSD NLS X11 SOUND
OPTIONS_DEFAULT=	GSTREAMER ASPELL SOUND
XOSD_DESC=	Xosd support

OPTIONS_SUB=	yes

NLS_USES=		gettext
NLS_CONFIGURE_ENABLE=	nls

X11_USES=		xorg
X11_USE=		XORG=x11
X11_CONFIGURE_WITH=	x

ASPELL_LIB_DEPENDS=	libaspell.so:textproc/aspell
ASPELL_CONFIGURE_ON=	--with-spell=aspell
ASPELL_CONFIGURE_OFF=	--with-spell=no --without-aspell

XOSD_LIB_DEPENDS=	libxosd.so:misc/xosd
XOSD_CONFIGURE_WITH=	xosd
SOUND_USES=	openal:al,alut
SOUND_CONFIGURE_ON=	--with-sound=openal
SOUND_CONFIGURE_OFF=	--with-sound=no

post-patch:
	@${REINPLACE_CMD} -e 's,-Werror,,g; s,-ldl,,g' ${WRKSRC}/configure
	@${MV} ${WRKSRC}/etc/xneurrc ${WRKSRC}/etc/xneurrc.sample

.include <bsd.port.mk>
