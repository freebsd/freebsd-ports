# $FreeBSD$

PORTNAME=	bitlbee-discord
DISTVERSION=	0.4.2-11
DISTVERSIONSUFFIX=-g3061edd
CATEGORIES=	irc

MAINTAINER=	arfy32@gmail.com
COMMENT=	Discord plugin for bitlbee

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	bitlbee:irc/bitlbee
LIB_DEPENDS=	libjson-glib-1.0.so:devel/json-glib

USES=		autoreconf gnome libtool pkgconfig
USE_GNOME=	glib20
USE_GITHUB=	yes
GH_ACCOUNT=	sm00th
GH_TAGNAME=	3061edd283b4e886384e5e8cad10f92dc45f3ee7

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-plugindir=${PREFIX}/lib/bitlbee --with-bdatadir=${LOCALBASE}/share/bitlbee
INSTALL_TARGET=	install-strip

PLIST_FILES=	lib/bitlbee/discord.so \
		share/bitlbee/discord-help.txt

.include <bsd.port.mk>
