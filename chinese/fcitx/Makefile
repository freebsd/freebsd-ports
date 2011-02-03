# New ports collection makefile for:	Free Chinese Input Toy for X
# Date created:				26 March 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fcitx
PORTVERSION=	4.0.0
CATEGORIES=	chinese x11
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} pinyin.tar.gz table.tar.gz
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	darcsis@gmail.com
COMMENT=	A simple and fast GBK Chinese XIM server

LIB_DEPENDS=	execinfo.1:${PORTSDIR}/devel/libexecinfo

LICENSE=	GPLv2

DIST_SUBDIR=	fcitx
USE_GNOME=	pango intltool
USE_XORG=	xpm x11 xtst
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

OPTIONS=	XFT		"Use Xft for Freetype font support" on \
		TRAY		"Enable system tray support" on \
		DBUS		"Enable D-Bus for KIMPanel support" off \
		RECORDING	"Enable recording of user input"    off \
		DEBUG		"Enable debug build with logging"   off \

.include <bsd.port.options.mk>

.if ${OSVERSION} < 800000
BROKEN=		does not build on 7.X
.endif

.if defined(WITH_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
.else
CONFIGURE_ARGS+=	--disable-xft
.endif

.if defined(WITHOUT_TRAY)
CONFIGURE_ARGS+=	--disable-tray
.endif

.if defined(WITH_DBUS)
LIB_DEPENDS+=	dbus-1.3:${PORTSDIR}/devel/dbus
.else
CONFIGURE_ARGS+=	--disable-dbus
.endif

.if defined(WITH_RECORDING)
CONFIGURE_ARGS+=	--enable-recording
.endif

.if defined(WITH_DEBUG)
CONFIGURE_ARGS+=	--enable-debug --enable-log
.endif

post-patch:
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/pinyin.tar.gz ${WRKSRC}/data
	@${CP} ${DISTDIR}/${DIST_SUBDIR}/table.tar.gz ${WRKSRC}/data/table

pre-install:
	@${CHMOD} +x ${WRKSRC}/install-sh

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
