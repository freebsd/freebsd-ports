# New ports collection makefile for:	Free Chinese Input Toy for X
# Date created:				26 March 2003
# Whom:			Shen Chuan-Hsing <statue@freebsd.sinica.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	fcitx
PORTVERSION=	3.6.3
CATEGORIES=	chinese x11
MASTER_SITES=	http://www.fcitx.org/download/ \
		ftp://mirrors.redv.com/pub/fcitx/

MAINTAINER=	darcsis@gmail.com
COMMENT=	A simple and fast GBK Chinese XIM server

LICENSE=	GPLv2

USE_BZIP2=	yes
USE_XORG=	xpm x11 xtst
USE_ICONV=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

OPTIONS=	XFT		"Use Xft for Freetype font support" on \
		DBUS		"Enable D-Bus for KIMPanel support" off \
		RECORDING	"Enable recording of user input"    off \
		DEBUG		"Enable debug build with logging"   off \

.include <bsd.port.options.mk>

.if defined(WITH_XFT)
LIB_DEPENDS+=	Xft.2:${PORTSDIR}/x11-fonts/libXft
.else
CONFIGURE_ARGS+=	--disable-xft
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
	@${REINPLACE_CMD} -e 's#zh_CN.GB2312#zh_CN.eucCN#g' \
		${WRKSRC}/src/xim.c
	@${REINPLACE_CMD} -e 's#zh_CN.gb2312#zh_CN.eucCN#g' \
		${WRKSRC}/src/ui.c ${WRKSRC}/src/tools.c

pre-install:
	@${CHMOD} +x ${WRKSRC}/install-sh

post-install:
	@${ECHO_CMD}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_CMD}

.include <bsd.port.mk>
