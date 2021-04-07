PORTNAME=	bitlbee-steam
PORTVERSION=	1.4.2
DISTVERSIONPREFIX=v
CATEGORIES=	irc

MAINTAINER=	aou@eecs.berkeley.edu
COMMENT=	Steam plugin for bitlbee

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt
BUILD_DEPENDS=	bitlbee:irc/bitlbee

USES=		autoreconf gnome libtool pkgconfig
USE_GNOME=	glib20
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-plugindir=${PREFIX}/lib/bitlbee

USE_GITHUB=	yes
GH_ACCOUNT=	bitlbee

INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/bitlbee/steam.so

.include <bsd.port.mk>
