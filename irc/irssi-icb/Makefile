# $FreeBSD$

PORTNAME=	irssi-icb
PORTVERSION=	0.17
CATEGORIES=	irc

MAINTAINER=	santhosh.raju@gmail.com
COMMENT=	Irssi plugin for connecting to ICB network

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	${LOCALBASE}/include/irssi/src/common.h:irc/irssi
RUN_DEPENDS=	irssi:irc/irssi

USES=		autoreconf libtool pkgconfig
USE_LDCONFIG=	yes
USE_GNOME=	glib20

USE_GITHUB=	yes
GH_ACCOUNT=	mglocker
GH_TAGNAME=	c4e2ea8

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --with-irssi=${LOCALBASE}/include/irssi
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/irssi/modules/libicb_core.so \
		lib/irssi/modules/libfe_icb.so

.include <bsd.port.mk>
